/**
 * @file CreateArgumentNameList.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-08
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef CREATE_ARGUMENT_NAME_LIST_CPP
#define CREATE_ARGUMENT_NAME_LIST_CPP

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "IsArgument.cpp"

namespace ExpressionManagement
{
    /**
     * @brief Creates a list of argument name, using RemoveIdenticalElement() because only one argument name can exist.
     * @param InfixExpressionInput infix form of expression in CustomTokenUnit
     * @return CustomTokenUnit as a list of argument name
     */
    CustomTokenUnit CreateArgumentNameList(CustomTokenUnit InfixExpressionInput)
    {
        CustomTokenUnit ArgumentNameList;
        std::string ArgumentNameBuilder = "";
        if (InfixExpressionInput.empty() == true)
            throw std::invalid_argument("Wrong in algorithm or invalid expression!");
        for (unsigned int i = 0; i < InfixExpressionInput.size(); ++i)
        {
            if (IsArgument(InfixExpressionInput[i]) == true)
                ArgumentNameList.push_back(InfixExpressionInput[i]);
        }
        return RemoveIdenticalElement(ArgumentNameList);
    }
}
#endif