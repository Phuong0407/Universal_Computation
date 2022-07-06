/**
 * @file IsArgumentExistence.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0-
 * @date 2022-07-06
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef IS_ARGUMENT_EXISTENCE_CPP
#define IS_ARGUMENT_EXISTENCE_CPP

#include <string>
#include <iostream>
#include <unordered_set>
#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief Checking whether an argument is belongs to argument name list
     * @param ArgumentNameToCheck is the input string to check
     * @param ArgumentNameList is the list or argument to check
     * @return true if exist
     */
    bool IsArgumentExistence(CustomTokenUnit ArgumentNameList, std::string ArgumentNameToCheck)
    {
        bool Checker = false;
        for (unsigned int i = 0; i < ArgumentNameList.size(); ++i)
        {
            if (ArgumentNameList[i] != ArgumentNameToCheck)
                continue;
            else
                Checker = true;
        }
        return Checker;
    }
}
#endif