/**
 * @file IsOperand.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef IS_OPERAND_CPP
#define IS_OPERAND_CPP

#include <iostream>

namespace ExpressionManagement
{
    /**
     * @brief Checks whether input expression is operand or not.
     * Operands here are variables, numbers, constants in version 2.0.
     * @param Checking input to check
     * @return true if input is operand
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
}
#endif