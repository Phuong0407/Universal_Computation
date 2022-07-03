/**
 * @file IsOperand.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#ifndef IS_OPERAND_CPP
#define IS_OPERAND_CPP

#include "../../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief IsOperand checks whether input expression is operand or not
     * @brief Operands are variables, numbers, constants in version 2.0
     * @param Checking is input we want to check
     * @return true
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