/**
 * @file ExpressionManagement.cpp is implementation file for ExpressionManagement.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-06-29
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef PROCESS_EXPRESSION_DECOMPOSITION__TOKEN_CPP
#define PROCESS_EXPRESSION_DECOMPOSITION_TOKEN_CPP

#include "ExpressionCustomTokenDecomposition.h"

/**
 * @brief ExpressionManagement namespace control all the operations related to expression exploitation
 */
namespace ExpressionManagement
{
    /**
     * @brief Construct a new ExpressionCustomTokenDecomposition object
     * @brief This is the only API to communicate with other object
     * @param InputExpression is the expression input to initialize object
     */
    void ExpressionCustomTokenDecomposition::DecompositionToInfixCustomTokenInitialization(std::string InputExpressionString)
    {
        this->ExpressionStringDecompositionInitialization(InputExpressionString);
        this->InfixDecompositionCustomToken = this->DecompositionToInfixCustomToken(this->OutputExpressionNoBlank());
        this->PostfixDecompositionCustomToken = this->InfixToPostfixConversion(this->OutputInfixDecompositionCustomToken());
        this->CreateOperandsList();
    }

    /**
     * @brief Decomposition method decompose a string expression to infix expression in a custom token unit
     * @brief Divide the problem to three case operands(variables, numbers and built-in functions), two parentheses, operators
     * @brief Use recurrence stack to decompose, need to check for overflow to avoid infinity recurrence
     * @brief We add a sub-method to create operand list, it will help build variable list later
     * @brief Change made in comparison with version 1.0
     * @brief Token to void return type, no parameter needed and direct use the expression from base class
     * @param PutString to ExpressionUnitBuilder
     * @param ScannerChar to ExpressionScannerUnit
     * @param Inside to InsideParenthesesExpression
     * @param ScannerString to ExpressionDecompositionBuildingBlockUnit
     * @param InputReplacement to ExpressionToDecompose
     * @param ExpressionDecomposition to InfixDecomposition
     * @param TempDecomposition to SubExpressionDecomposition
     * @param InsideDecomposition to InsideParenthesesExpressionTokenUnit
     * @return CustomTokenUnit as a infix expression
     */
    CustomTokenUnit ExpressionCustomTokenDecomposition::DecompositionToInfixCustomToken(std::string ExpressionInput)
    {
        char ExpressionScannerUnit;
        std::string ExpressionToDecompose = "";
        std::string ExpressionUnitBuilder = "";
        std::string InsideParenthesesExpression = "";
        std::string ExpressionDecompositionBuildingBlockUnit = "";
        CustomTokenUnit InfixDecomposition;
        CustomTokenUnit SubExpressionDecomposition;
        CustomTokenUnit InsideParenthesesExpressionTokenUnit;
        ExpressionToDecompose.assign(this->OutputExpressionNoBlank());
        while (ExpressionToDecompose.length() >= 1)
        {
            if (ExpressionToDecompose.length() == 1)
            {
                // at this place just the operand and ")" can appear
                InfixDecomposition.push_back(ExpressionToDecompose);
                ExpressionToDecompose = "";
            }
            else
            {
                ExpressionScannerUnit = ExpressionToDecompose[0];
                if (IsOperator(ExpressionScannerUnit) == true)
                {
                    ExpressionUnitBuilder = "";
                    ExpressionUnitBuilder += ExpressionScannerUnit;
                    InfixDecomposition.push_back(ExpressionUnitBuilder);
                    ExpressionToDecompose = ExpressionToDecompose.substr(1, ExpressionToDecompose.length());
                    SubExpressionDecomposition = DecompositionToInfixCustomToken(ExpressionToDecompose);
                    InfixDecomposition.insert(InfixDecomposition.end(), SubExpressionDecomposition.begin(), SubExpressionDecomposition.end());
                    ExpressionToDecompose = "";
                }
                else if (IsOperand(ExpressionScannerUnit) == true)
                {
                    // get all the string of operand
                    ExpressionDecompositionBuildingBlockUnit = "";
                    while (IsOperand(ExpressionScannerUnit) == true)
                    {
                        ExpressionDecompositionBuildingBlockUnit += ExpressionScannerUnit;
                        ExpressionToDecompose = ExpressionToDecompose.substr(1, ExpressionToDecompose.length());
                        ExpressionScannerUnit = ExpressionToDecompose[0];
                    }
                    if (IsBuiltInFunctions(ExpressionDecompositionBuildingBlockUnit) == true)
                    {
                        InfixDecomposition.push_back(ExpressionDecompositionBuildingBlockUnit);
                        InsideParenthesesExpression = GetInsideParentheses(ExpressionToDecompose);
                        InsideParenthesesExpressionTokenUnit = DecompositionToInfixCustomToken(InsideParenthesesExpression);
                        InfixDecomposition.insert(InfixDecomposition.end(), InsideParenthesesExpressionTokenUnit.begin(), InsideParenthesesExpressionTokenUnit.end());
                        if (InsideParenthesesExpression.length() == ExpressionToDecompose.length())
                            ExpressionToDecompose = "";
                        else
                            ExpressionToDecompose = ExpressionToDecompose.substr(InsideParenthesesExpression.length(), ExpressionToDecompose.length());
                    }
                    else
                    {
                        InfixDecomposition.push_back(ExpressionDecompositionBuildingBlockUnit);
                    }
                    SubExpressionDecomposition = DecompositionToInfixCustomToken(ExpressionToDecompose);
                    InfixDecomposition.insert(InfixDecomposition.end(), SubExpressionDecomposition.begin(), SubExpressionDecomposition.end());
                    ExpressionToDecompose = "";
                }
                else if (ExpressionScannerUnit == '(' || ExpressionScannerUnit == ')')
                {
                    ExpressionUnitBuilder = "";
                    ExpressionUnitBuilder += ExpressionScannerUnit;
                    InfixDecomposition.push_back(ExpressionUnitBuilder);
                    ExpressionToDecompose = ExpressionToDecompose.substr(1, ExpressionToDecompose.length());
                    SubExpressionDecomposition = DecompositionToInfixCustomToken(ExpressionToDecompose);
                    InfixDecomposition.insert(InfixDecomposition.end(), SubExpressionDecomposition.begin(), SubExpressionDecomposition.end());
                    ExpressionToDecompose = "";
                }
                else
                    continue;
            }
        }
        return InfixDecomposition;
    }

    /**
     * @brief InfixToPostfixConversion is used to convert a expression from infix to postfix
     * @param ExpressionStack to PostfixConversionStack
     * @param StringScanner to ExpressionCustomTokenScanner
     * @param InsideParser to InsideParenthesesExpressionConversion
     * @param InsideExpression to InsideParenthesesExpressionCustomToken
     * @return CustomTokenUnit as postfix expression
     */
    CustomTokenUnit ExpressionCustomTokenDecomposition::InfixToPostfixConversion(CustomTokenUnit InfixCustomTokenUnitInput)
    {
        std::string ExpressionCustomTokenScanner = "";
        CustomTokenUnit ExpressionInputToConvert = this->InfixDecompositionCustomToken;
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

    /**
     * @brief We want to create a list of operands to create list of arguments of expression in computation class
     * @brief We do not need to check for invalid expression here because we will do in the expression computation class
     * @return CustomTokenUnit
     */
    void ExpressionCustomTokenDecomposition::CreateOperandsList()
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

    CustomTokenUnit
    ExpressionCustomTokenDecomposition::OutputInfixDecompositionCustomToken()
    {
        return this->InfixDecompositionCustomToken;
    }
    CustomTokenUnit ExpressionCustomTokenDecomposition::OutputPostfixDecompositionCustomToken()
    {
        return this->PostfixDecompositionCustomToken;
    }
    std::vector<std::string> ExpressionCustomTokenDecomposition::OutputOperandsList()
    {
        return this->OperandsList;
    }
}

#endif