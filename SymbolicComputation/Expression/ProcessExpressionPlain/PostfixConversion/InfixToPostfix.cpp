/**
 * @file InfixToPostfix.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */
#include "InfixToPostfix.h"

namespace ExpressionManagement
{
    /**
     * @brief InfixToPostfixConversion is used to convert a expression from infix to postfix
     * @brief It will help to build expression tree later
     * @param ExpressionStack to PostfixConversionStack
     * @param StringScanner to ExpressionCustomTokenScanner
     * @param InsideParser to InsideParenthesesExpressionConversion
     * @param InsideExpression to InsideParenthesesExpressionCustomToken
     * @return CustomTokenUnit as postfix expression
     */
    CustomTokenUnit InfixToPostfixConversion(CustomTokenUnit InfixCustomTokenUnitInput)
    {
        std::string ExpressionCustomTokenScanner = "";
        CustomTokenUnit ExpressionInputToConvert = InfixCustomTokenUnitInput;
        CustomTokenUnit PostfixExpressionCustomToken;
        CustomTokenUnit InsideParenthesesExpressionCustomToken;
        CustomTokenUnit InsideParenthesesExpressionConversion;
        std::stack<std::string> PostfixConversionStack;
        while (ExpressionInputToConvert.size() != 0)
        {
            ExpressionCustomTokenScanner = ExpressionInputToConvert[0];
            ExpressionInputToConvert.erase(ExpressionInputToConvert.begin());
            if (IsBuiltInFunctions(ExpressionCustomTokenScanner) == true)
            {
                InsideParenthesesExpressionCustomToken = GetInsideParentheses(ExpressionInputToConvert);
                // remove the function
                for (unsigned i = 0; i < InsideParenthesesExpressionCustomToken.size(); ++i)
                    ExpressionInputToConvert.erase(ExpressionInputToConvert.begin());
                InsideParenthesesExpressionConversion = InfixToPostfixConversion(InsideParenthesesExpressionCustomToken);
                for (unsigned i = 0; i < InsideParenthesesExpressionConversion.size(); ++i)
                    PostfixExpressionCustomToken.push_back(InsideParenthesesExpressionConversion[i]);
                PostfixExpressionCustomToken.push_back(ExpressionCustomTokenScanner);
                ExpressionCustomTokenScanner = "";
                InsideParenthesesExpressionCustomToken.clear();
            }
            else if (ExpressionCustomTokenScanner == "(")
            {
                PostfixConversionStack.push(ExpressionCustomTokenScanner);
                ExpressionCustomTokenScanner = "";
            }
            else if (ExpressionCustomTokenScanner == ")")
            {
                // we will pop all the operands until it gets to the parentheses
                while (PostfixConversionStack.top() != "(")
                {
                    PostfixExpressionCustomToken.push_back(PostfixConversionStack.top());
                    PostfixConversionStack.pop();
                }
                PostfixConversionStack.pop();
                ExpressionCustomTokenScanner = "";
            }
            else if (IsOperator(ExpressionCustomTokenScanner))
            {
                while ((PostfixConversionStack.empty() == false) && (PriorityOrder(ExpressionCustomTokenScanner) <= PriorityOrder(PostfixConversionStack.top())))
                {
                    PostfixExpressionCustomToken.push_back(PostfixConversionStack.top());
                    PostfixConversionStack.pop();
                }
                PostfixConversionStack.push(ExpressionCustomTokenScanner);
                ExpressionCustomTokenScanner = "";
            }
            else
            {
                PostfixExpressionCustomToken.push_back(ExpressionCustomTokenScanner);
                ExpressionCustomTokenScanner = "";
            }
        }
        while (PostfixConversionStack.empty() == false)
        {
            PostfixExpressionCustomToken.push_back(PostfixConversionStack.top());
            PostfixConversionStack.pop();
        }
        return PostfixExpressionCustomToken;
    }
}
/**
 * @brief We want to create a list of operands to create list of arguments of expression in computation class
 * @brief We do not need to check for invalid expression here because we will do in the expression computation class
 * @return CustomTokenUnit
 */
void Decomposition::CreateOperandsList()
{
    std::vector<std::string> PostfixCustomTokenUnitToScan = this->OutputPostfixDecompositionCustomToken();
    for (unsigned int i = 0; i < PostfixCustomTokenUnitToScan.size(); ++i)
    {
        if (IsDigit(PostfixCustomTokenUnitToScan[i]) == true)
            continue;
        else if (IsBuiltInFunctions(PostfixCustomTokenUnitToScan[i]) == true)
            continue;
        else if (IsOperator(PostfixCustomTokenUnitToScan[i]) == true)
            continue;
        else if (PostfixCustomTokenUnitToScan[i] == "(" || PostfixCustomTokenUnitToScan[i] == ")")
            continue;
        else
            this->OperandsList.push_back(PostfixCustomTokenUnitToScan[i]);
    }
}