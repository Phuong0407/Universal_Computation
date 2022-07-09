/**
 * @file IsConstant.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef IS_CONSTANTS_CPP
#define IS_CONSTANTS_CPP

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief Checks whether the input expression is constant or not.
     * Checks by finding from unordered_set in ExpressionBuildingBlock.h.
     * @param Input is the input to check
     * @return true if constant found
     */
    bool IsConstant(std::string StringToFind)
    {
        auto Search = Constant.find(StringToFind);
        if (Search != Constant.end())
            return true;
        else
            return false;
    }
}
#endif
