/**
 * @file GetArgumentName.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-06
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef GET_ARGUMENT_NAME_CPP
#define GET_ARGUMENT_NAME_CPP

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief Using further to creates a list of operands to create list of arguments of expression in computation class, do not use anymore!
     * @return CustomTokenUnit
     */
    CustomTokenUnit GetArgumentName(CustomTokenUnit InfixExpressionInput)
    {
        CustomTokenUnit ArgumentNameList;
        for (unsigned int i = 0; i < InfixExpressionInput.size(); ++i)
        {
            if (IsDigit(InfixExpressionInput[i]) == true)
                continue;
            else if (IsConstant(InfixExpressionInput[i]) == true)
                continue;
            else if (IsBuiltInFunctions(InfixExpressionInput[i]) == true)
                continue;
            else if (IsOperator(InfixExpressionInput[i]) == true)
                continue;
            else if (InfixExpressionInput[i] == "(" || InfixExpressionInput[i] == ")")
                continue;
            else
                ArgumentNameList.push_back(InfixExpressionInput[i]);
        }
        return ArgumentNameList;
    }
}
#endif