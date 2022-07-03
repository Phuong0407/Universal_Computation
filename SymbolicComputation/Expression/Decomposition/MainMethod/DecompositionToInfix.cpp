/**
 * @file Decomposition.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#ifndef DECOMPOSITION_TO_INFIX_CPP
#define DECOMPOSITION_TO_INFIX_CPP

#include "DecompositionToInfix.h"

namespace ExpressionManagement
{
    void DecompositionToInfix::DecompositionToInfixInputAPI(std::string InputExpressionString)
    {
        this->ExpressionStringStorageInputAPI(InputExpressionString);
        VectorAssign(this->InfixExpressionCustomToken, this->DecompositionToInfixCustomToken(this->OutputExpressionNoBlank()));
        std::cout << this->OutputExpressionNoBlank();
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
    CustomTokenUnit DecompositionToInfix::DecompositionToInfixCustomToken(std::string ExpressionInput)
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

    CustomTokenUnit DecompositionToInfix::DecompositionToInfixOutputAPI()
    {
        return this->InfixExpressionCustomToken;
    }
}
#endif