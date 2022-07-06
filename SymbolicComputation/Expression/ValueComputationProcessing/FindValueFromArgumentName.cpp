/**
 * @file FindValueFromArgumentName.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-06
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef FIND_VALUE_FROM_ARGUMENT_NAME_CPP
#define FIND_VALUE_FROM_ARGUMENT_NAME_CPP

#include <string>
#include <iostream>
#include <unordered_map>
#include "IsArgumentExistence.cpp"

namespace ExpressionManagement
{
    /**
     * @brief We search from ArgumentValueList
     * @param ArgumentNameToFind is string to find
     * @param ArgumentValueList is the unordered_map to find value from
     * @return double
     */
    double FindValueFromArgumentName(CustomTokenUnit ArgumentNameList, std::unordered_map<std::string, double> ArgumentValueList, std::string ArgumentNameToFind)
    {
        if (IsArgumentExistence(ArgumentNameList, ArgumentNameToFind) == false)
            throw std::invalid_argument("Do not have this variable in this expression! Please check the file ExpressionTreeComputation.cpp");
        return ArgumentValueList.at(ArgumentNameToFind);
    }
}
#endif