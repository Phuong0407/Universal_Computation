/**
 * @file Decomposition.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef DECOMPOSITION_TO_INFIX_CPP
#define DECOMPOSITION_TO_INFIX_CPP

#include "ProcessingAuxiliaryMethodAPI.cpp"

namespace ExpressionManagement
{
    /**
     * @brief DecompositionToInfixCustomToken method decompose a string expression to infix expression in a custom token unit
     * @brief Divide the problem to three case operands(variables, numbers and built-in functions), two parentheses, operators
     * @brief Use recurrence stack to decompose, need to check for overflow to avoid infinity recurrence
     * @brief Changes make in comparision with 1.0 version
     * @param PutString to ExpressionUnitBuilder
     * @param ScannerChar to ExpressionScanner
     * @param Inside to InsideParenthesesExpression
     * @param ScannerString to CustomTokenUnitExpressionScanner
     * @param InputReplacement to ExpressionToDecompose
     * @param ExpressionDecomposition to InfixDecomposition
     * @param TempDecomposition to SubExpressionDecomposition
     * @param InsideDecomposition to InsideParenthesesExpressionTokenUnit
     * @return CustomTokenUnit as a infix expression
     */
    CustomTokenUnit DecompositionToInfixCustomToken(std::string InputExpressionToDecompose)
    {
        CustomTokenUnit InfixDecomposition;
        std::string ExpressionToDecompose = InputExpressionToDecompose;
        while (ExpressionToDecompose.length() >= 1)
        {
            if (ExpressionToDecompose.length() == 1)
            {
                // at thIs place just the operand and ")" can appear
                InfixDecomposition.push_back(ExpressionToDecompose);
                ExpressionToDecompose = "";
            }
            else
            {
                char ExpressionScanner = ExpressionToDecompose[0];
                if (IsOperator(ExpressionScanner) == true)
                {
                    std::string ExpressionUnitBuilder = "";
                    ExpressionUnitBuilder += ExpressionScanner;
                    InfixDecomposition.push_back(ExpressionUnitBuilder);
                    ExpressionToDecompose = ExpressionToDecompose.substr(1, ExpressionToDecompose.length());
                    CustomTokenUnit SubExpressionDecomposition = DecompositionToInfixCustomToken(ExpressionToDecompose);
                    InfixDecomposition.insert(InfixDecomposition.end(), SubExpressionDecomposition.begin(), SubExpressionDecomposition.end());
                    ExpressionToDecompose = "";
                }
                else if (IsOperand(ExpressionScanner) == true)
                {
                    std::string CustomTokenUnitExpressionScanner = "";
                    while (IsOperand(ExpressionScanner) == true)
                    {
                        CustomTokenUnitExpressionScanner += ExpressionScanner;
                        ExpressionToDecompose = ExpressionToDecompose.substr(1, ExpressionToDecompose.length());
                        ExpressionScanner = ExpressionToDecompose[0];
                    }
                    if (IsBuiltInFunctions(CustomTokenUnitExpressionScanner) == true)
                    {
                        InfixDecomposition.push_back(CustomTokenUnitExpressionScanner);
                        std::string InsideParenthesesExpression = GetInsideParentheses(ExpressionToDecompose);
                        CustomTokenUnit InsideParenthesesExpressionTokenUnit = DecompositionToInfixCustomToken(InsideParenthesesExpression);
                        InfixDecomposition.insert(InfixDecomposition.end(), InsideParenthesesExpressionTokenUnit.begin(), InsideParenthesesExpressionTokenUnit.end());
                        if (InsideParenthesesExpression.length() == ExpressionToDecompose.length())
                            ExpressionToDecompose = "";
                        else
                            ExpressionToDecompose = ExpressionToDecompose.substr(InsideParenthesesExpression.length(), ExpressionToDecompose.length());
                    }
                    else
                        InfixDecomposition.push_back(CustomTokenUnitExpressionScanner);
                    CustomTokenUnit SubExpressionDecomposition = DecompositionToInfixCustomToken(ExpressionToDecompose);
                    InfixDecomposition.insert(InfixDecomposition.end(), SubExpressionDecomposition.begin(), SubExpressionDecomposition.end());
                    ExpressionToDecompose = "";
                }
                else if (ExpressionScanner == '(' || ExpressionScanner == ')')
                {
                    std::string ExpressionUnitBuilder = "";
                    ExpressionUnitBuilder += ExpressionScanner;
                    InfixDecomposition.push_back(ExpressionUnitBuilder);
                    ExpressionToDecompose = ExpressionToDecompose.substr(1, ExpressionToDecompose.length());
                    CustomTokenUnit SubExpressionDecomposition = DecompositionToInfixCustomToken(ExpressionToDecompose);
                    InfixDecomposition.insert(InfixDecomposition.end(), SubExpressionDecomposition.begin(), SubExpressionDecomposition.end());
                    ExpressionToDecompose = "";
                }
                else
                    continue;
            }
        }
        return InfixDecomposition;
    }
}
#endif