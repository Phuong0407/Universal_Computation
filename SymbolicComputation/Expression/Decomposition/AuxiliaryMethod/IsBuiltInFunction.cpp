/**
 * @file IsBuiltInFunction.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#ifndef IS_BUILT_IN_FUNCTION_CPP
#define IS_BUILT_IN_FUNCTION_CPP

#include "../../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "IsDigit.cpp"

namespace ExpressionManagement
{
    /**
     * @brief IsBuiltInFunctions methods helps checking for built-in functions
     * @brief Checking by finding in the built-in unordered_set in ExpressionBuildingBlock.h
     * @brief Add method to check for generalized root, for example, sqrt2(3) is square root of 3
     * @param InputCheckingString is the input to check
     * @return true
     */
    bool IsBuiltInFunctions(std::string InputCheckingString)
    {
        if (BuiltInFunctions.find(InputCheckingString) != BuiltInFunctions.end())
            return true;
        // We check for root function with order different from 2, for example sqrt3(2) is cube root of 2
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