/**
 * @file IsBalance.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef IS_BALANCED_CPP
#define IS_BALANCED_CPP

//#include "IsBalance.h"
#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief Checks whether the string in expression is balance or not, balance means all the parentheses goes in a pair,
     * that is for example, [(){}[([]{})]] is balance, only accept () as parentheses for all mathematical expression
     * @param InputToCheckBalance input to check
     * @return true if the string is balance
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

/**
     * @brief Checks whether the string in expression is balance or not, balance means all the parentheses goes in a pair,
     * that is for example, [(){}[([]{})]] is balance, only accept () as parentheses for all mathematical expression
     * @param InputToCheckBalance input to check
     * @return true if the string is balance
     */
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
}
#endif