/**
 * @file InfixToPostfix.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */

#include "ProcessingAuxiliaryMethodAPI.cpp"

namespace ExpressionManagement
{
    /**
     * @brief InfixToPostfixConversion is used to convert a expression from infix to postfix
     * @param InfixCustomTokenUnitInput is the expression in infix form CustomTokenUnit
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
