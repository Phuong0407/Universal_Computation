/**
 * @file IsBuiltInFunction.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef IS_BUILT_IN_FUNCTION_CPP
#define IS_BUILT_IN_FUNCTION_CPP

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "IsDigit.cpp"

namespace ExpressionManagement
{
    /**
     * @brief Checks whether input is built-in function or not,
     * checking by finding in the built-in unordered_set in ExpressionBuildingBlock.h.
     * Additional check for generalized root and logarithms,
     * for example, sqrt2(3) is square root of 3 and log2.5(3) is logarithm of base 2.5 of 3.
     * @param InputCheckingString input to check
     * @return true if found built-in functions
     */
    bool IsBuiltInFunctions(std::string InputCheckingString)
    {
        if (BuiltInFunctions.find(InputCheckingString) != BuiltInFunctions.end())
            return true;
        else if(InputCheckingString.length() >= 4)
        {
            std::string CheckingRootFunctionNotation = "";
            std::string CheckingRootFunctionOrder = "";
            CheckingRootFunctionNotation = InputCheckingString.substr(0, 3);
            CheckingRootFunctionOrder = InputCheckingString.substr(3, InputCheckingString.length());
            if (IsDigit(CheckingRootFunctionOrder) == true && CheckingRootFunctionNotation == "log")
                return true;
            else
                return false;
        }
        else if (InputCheckingString.length() >= 5)
        {
            std::string CheckingRootFunctionNotation = "";
            std::string CheckingRootFunctionOrder = "";
            CheckingRootFunctionNotation = InputCheckingString.substr(0, 4);
            CheckingRootFunctionOrder = InputCheckingString.substr(4, InputCheckingString.length());
            if (IsDigit(CheckingRootFunctionOrder) == true && CheckingRootFunctionNotation == "sqrt")
                return true;
            else
                return false;
        }
        else
            return false;
    }
}
#endif