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
     * @brief Decomposes a string expression to infix expression in a CustomTokenUnit,
     * Infix form contains "operands" (variables, numbers and built-in functions), two parentheses '(" and ')', operators (+, -, *, /, ^)
     * @param InputExpressionToDecompose string to decompose to CustomTokenUnit
     * @return CustomTokenUnit as a infix expression
     */
    CustomTokenUnit DecompositionToInfixCustomToken(std::string InputExpressionToDecompose)
    {
        char ExpressionScanner;
        std::string ExpressionToDecompose = InputExpressionToDecompose;
        std::string ExpressionUnitBuilder = "";
        std::string InsideParenthesesExpression = "";
        std::string CustomTokenUnitExpressionScanner = "";
        CustomTokenUnit InfixDecomposition;
        CustomTokenUnit SubExpressionDecomposition;
        CustomTokenUnit InsideParenthesesExpressionTokenUnit;
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
                ExpressionScanner = ExpressionToDecompose[0];
                if (IsOperator(ExpressionScanner) == true)
                {
                    ExpressionUnitBuilder = "";
                    ExpressionUnitBuilder += ExpressionScanner;
                    InfixDecomposition.push_back(ExpressionUnitBuilder);
                    ExpressionToDecompose = ExpressionToDecompose.substr(1, ExpressionToDecompose.length());
                    SubExpressionDecomposition = DecompositionToInfixCustomToken(ExpressionToDecompose);
                    InfixDecomposition.insert(InfixDecomposition.end(), SubExpressionDecomposition.begin(), SubExpressionDecomposition.end());
                    ExpressionToDecompose = "";
                }
                else if (IsOperand(ExpressionScanner) == true)
                {
                    CustomTokenUnitExpressionScanner = "";
                    while (IsOperand(ExpressionScanner) == true)
                    {
                        CustomTokenUnitExpressionScanner += ExpressionScanner;
                        ExpressionToDecompose = ExpressionToDecompose.substr(1, ExpressionToDecompose.length());
                        ExpressionScanner = ExpressionToDecompose[0];
                    }
                    if (IsBuiltInFunctions(CustomTokenUnitExpressionScanner) == true)
                    {
                        InfixDecomposition.push_back(CustomTokenUnitExpressionScanner);
                        InsideParenthesesExpression = GetInsideParentheses(ExpressionToDecompose);
                        InsideParenthesesExpressionTokenUnit = DecompositionToInfixCustomToken(InsideParenthesesExpression);
                        InfixDecomposition.insert(InfixDecomposition.end(), InsideParenthesesExpressionTokenUnit.begin(), InsideParenthesesExpressionTokenUnit.end());
                        if (InsideParenthesesExpression.length() == ExpressionToDecompose.length())
                            ExpressionToDecompose = "";
                        else
                            ExpressionToDecompose = ExpressionToDecompose.substr(InsideParenthesesExpression.length(), ExpressionToDecompose.length());
                    }
                    else
                        InfixDecomposition.push_back(CustomTokenUnitExpressionScanner);
                    SubExpressionDecomposition = DecompositionToInfixCustomToken(ExpressionToDecompose);
                    InfixDecomposition.insert(InfixDecomposition.end(), SubExpressionDecomposition.begin(), SubExpressionDecomposition.end());
                    ExpressionToDecompose = "";
                }
                else if (ExpressionScanner == '(' || ExpressionScanner == ')')
                {
                    ExpressionUnitBuilder = "";
                    ExpressionUnitBuilder += ExpressionScanner;
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
}
#endif