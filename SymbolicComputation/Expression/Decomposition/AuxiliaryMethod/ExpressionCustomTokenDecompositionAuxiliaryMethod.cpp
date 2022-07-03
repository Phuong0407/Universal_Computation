/**
 * @file ExpressionCustomTokenDecompositionAuxiliaryMethod.cpp
 * @file is the implementation file of ExpressionCustomTokenDecompositionAuxiliaryMethod.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief Methods for checking and calculating some parameters related to infix expression decomposition
 * @version 2.0
 * @date 2022-07-01
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef EXPRESSION_CUSTOM_TOKEN_DECOMPOSITION_AUXILIARY_METHOD_CPP
#define EXPRESSION_CUSTOM_TOKEN_DECOMPOSITION_AUXILIARY_METHOD_CPP

#include "ExpressionCustomTokenDecompositionAuxiliaryMethod.h"

namespace ExpressionManagement
{
    /**
     * @brief IsDigit method helps us to check whether a string operand is a real number
     * @brief When using this method, please check if a string is an operand or not, or maybe not using
     * @param InputToCheck is the operand to check
     * @return true
     */
    bool IsDigit(std::string InputToCheck)
    {
        bool InputCheckerUnit = true;
        if (InputToCheck[0] == '-' || InputToCheck[0] == '+')
            return true;
        for (int i = 0; InputToCheck[i] != '\0'; i++)
            if (!isdigit(InputToCheck[i]))
            {
                if (InputToCheck[i] == '.')
                    continue;
                else
                    InputCheckerUnit = false;
            }
        return InputCheckerUnit;
    }

    /**
     * @brief IsOperand checks whether input expression is operand or not
     * @brief Operands are variables, numbers, constants in version 2.0
     * @param Checking is input we want to check
     * @return true or false
     */
    bool IsOperand(char Checking)
    {
        if (Checking >= 'a' && Checking <= 'z')
            return true;
        else if (Checking >= 'A' && Checking <= 'Z')
            return true;
        else if (Checking >= '0' && Checking <= '9')
            return true;
        else if (Checking == '.')
            return true;
        else
            return false;
    }

    /**
     * @brief IsOperator checks whether input expression is operator or not
     * @brief Operators are '^', '*', '/', '+', '-' in version 2.0
     * @brief Can add more operators for future development
     * @param Checking is the input to check
     * @return true or false
     */
    bool IsOperator(char Checking)
    {
        if (Checking == '^')
            return true;
        else if (Checking == '*')
            return true;
        else if (Checking == '/')
            return true;
        else if (Checking == '+')
            return true;
        else if (Checking == '-')
            return true;
        else
            return false;
    }
    bool IsOperator(std::string Checking)
    {
        if (Checking == "^")
            return true;
        else if (Checking == "*")
            return true;
        else if (Checking == "/")
            return true;
        else if (Checking == "+")
            return true;
        else if (Checking == "-")
            return true;
        else
            return false;
    }

    /**
     * @brief PriorityOrder gives order for all entities consisting of operators and operands
     * @brief This will serve for InfixToPostfix method later, can be develop further
     * @param Checking is the input to calculate rank of the entity
     * @return int as its rank
     */
    int PriorityOrder(char Checking)
    {
        if (Checking == '^')
            return 3;
        if (Checking == '*' || Checking == '/')
            return 2;
        else if (Checking == '+' || Checking == '-')
            return 1;
        else
            return 0;
    }

    int PriorityOrder(std::string Checking)
    {
        if (Checking == "^")
            return 3;
        if (Checking == "*" || Checking == "/")
            return 2;
        else if (Checking == "+" || Checking == "-")
            return 1;
        else
            return 0;
    }

    /**
     * @brief IsConstant check whether the input expression is constant or not
     * @brief We will check by finding from unordered_set in ExpressionBuildingBlock.h
     * @param Input is the input to check
     * @return true
     */
    bool IsConstant(std::string Input)
    {
        auto Search = Constant.find(Input);
        if (Search != Constant.end())
            return true;
        else
            return false;
    }

    /**
     * @brief IsBuiltInFunctions methods helps checking for built-in functions
     * @brief We will check by finding in the built-in unordered_set in ExpressionBuildingBlock.h
     * @brief Add method to check for generalized root, for example, sqrt2(3) is square root of 3
     * @param InputCheckingString is the input to check
     * @return true
     */
    bool IsBuiltInFunctions(std::string InputCheckingString)
    {
        std::string CheckingRootFunctionNotation = "";
        std::string CheckingRootFunctionOrder = "";
        if (BuiltInFunctions.find(InputCheckingString) != BuiltInFunctions.end())
            return true;

        // We check for root function with order different from 2, for example sqrt3(2) is cube root of 2
        else if (InputCheckingString.length() >= 5)
        {
            CheckingRootFunctionNotation = InputCheckingString.substr(InputCheckingString[0], InputCheckingString[3]);
            CheckingRootFunctionOrder = InputCheckingString.substr(InputCheckingString[4], InputCheckingString.length());
            if (IsDigit(CheckingRootFunctionOrder) == true && CheckingRootFunctionNotation == "sqrt")
                return true;
        }
        return false;
    }

    /**
     * @brief IsBalance methods check whether the string in expression is balance or not
     * @brief Balance means all the parentheses goes in a pair, that is for example, [(){}[([]{})]] is balance
     * @brief In this project, we only accept () as parentheses for all mathematical expression
     * @param TempChar to InputScanner
     * @param Input to InputToCheckBalance
     * @return true
     */
    bool IsBalance(std::string InputToCheckBalance)
    {
        char InputScanner;
        std::stack<char> ExpressionCheckingUnit;
        for (unsigned int i = 0; i < InputToCheckBalance.length(); i++)
        {
            InputScanner = InputToCheckBalance[i];
            if (InputScanner == '(')
                ExpressionCheckingUnit.push(InputScanner);
            else if (InputScanner == ')')
            {
                if (ExpressionCheckingUnit.empty() == true)
                    return false;
                else
                    ExpressionCheckingUnit.pop();
            }
            else
                continue;
        }
        if (ExpressionCheckingUnit.empty() == true)
            return true;
        else
            return false;
    }
    bool IsBalance(CustomTokenUnit InputToCheckBalance)
    {
        std::string InputScanner = "";
        std::stack<std::string> ExpressionCheckingUnit;
        for (unsigned int i = 0; i < InputToCheckBalance.size(); i++)
        {
            InputScanner = InputToCheckBalance[i];
            if (InputScanner == "(")
                ExpressionCheckingUnit.push(InputScanner);
            else if (InputScanner == ")")
            {
                if (ExpressionCheckingUnit.empty() == true)
                    return false;
                else
                    ExpressionCheckingUnit.pop();
            }
            else
                continue;
        }
        if (ExpressionCheckingUnit.empty() == true)
            return true;
        else
            return false;
    }
    /**
     * @brief GetInsideParentheses methods used for get the expression inside a parentheses
     * @brief This will serve as a base steps for recursion in decomposition method
     * @param Input is expression to get inside parentheses
     */
    std::string GetInsideParentheses(std::string Input)
    {
        unsigned int PositionTracker = 0;
        std::string InsideParenthesesExpressionBuilder = "";
        char InputScanner = Input[PositionTracker];
        InsideParenthesesExpressionBuilder += InputScanner;
        while (PositionTracker < Input.length())
        {
            PositionTracker++;
            InputScanner = Input[PositionTracker];
            InsideParenthesesExpressionBuilder += InputScanner;
            if (IsBalance(InsideParenthesesExpressionBuilder) == true && InputScanner == ')')
                break;
            else
                continue;
        }
        return InsideParenthesesExpressionBuilder;
    }
    CustomTokenUnit GetInsideParentheses(CustomTokenUnit Input)
    {
        unsigned int PositionTracker = 0;
        CustomTokenUnit InsideParenthesesExpressionBuilder;
        std::string InputScanner = Input[PositionTracker];
        InsideParenthesesExpressionBuilder.push_back(InputScanner);
        while (PositionTracker < Input.size())
        {
            PositionTracker++;
            InputScanner = Input[PositionTracker];
            InsideParenthesesExpressionBuilder.push_back(InputScanner);
            if (IsBalance(InsideParenthesesExpressionBuilder) == true && InputScanner == ")")
                break;
            else
                continue;
        }
        return InsideParenthesesExpressionBuilder;
    }
}
#endif