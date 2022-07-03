/**
 * @file IsConstant.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#ifndef IS_CONSTANTS_CPP
#define IS_CONSTANTS_CPP

#include "../../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief IsConstant checks whether the input expression is constant or not
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
}

#endif

int main()
{
}