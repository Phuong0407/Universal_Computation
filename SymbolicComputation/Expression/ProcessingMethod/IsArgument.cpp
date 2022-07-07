/**
 * @file IsArgument.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-07
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef IS_ARGUMENT_CPP
#define IS_ARGUMENT_CPP

#include "ProcessingAuxiliaryMethodAPI.cpp"

namespace ExpressionManagement
{
    /**
     * @brief It will check if a string is an argument for expression
     * @param Checking is the input to check
     * @return true
     */
    bool IsArgument(std::string Checking)
    {
        if (IsOperator(Checking) == true)
            return false;
        else if (IsBuiltInFunction(Checking) == true)
            return false;
        else if (IsConstant(Checking) == true)
            return false;
        else if (IsDigit(Checking) == true)
            return false;
        else if (Checking == "(" || Checking == ")")
            return false;
        else
            return true;
    }

}

#endif