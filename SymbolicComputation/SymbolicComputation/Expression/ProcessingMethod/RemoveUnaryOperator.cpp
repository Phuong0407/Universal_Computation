/**
 * @file RemoveUnaryOperator.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-07
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef REMOVE_UNARY_OPERATOR_CPP
#define REMOVE_UNARY_OPERATOR_CPP

#include <iostream>
#include <cstring>

namespace ExpressionManagement
{
    /**
     * @brief Only removes + and - in the form +3 + 4 by transform to 0 + 3 + 4, for example
     * @param InputToRemove string to remove
     * @return std::string as removed string expression
     */
    std::string RemoveUnaryOperator(std::string InputToRemove)
    {
        std::string TempStringInsert = "";
        if (InputToRemove[0] == '+' || InputToRemove[0] == '-')
        {
            TempStringInsert += '0';
            TempStringInsert += InputToRemove;
            InputToRemove.assign(TempStringInsert);
        }
        for (unsigned int i = 0; i < InputToRemove.length(); ++i)
            if (InputToRemove[i] == '(' && (InputToRemove[i + 1] == '+' || InputToRemove[i + 1] == '-'))
                InputToRemove.insert(i + 1, "0");
        return InputToRemove;
    }
}

#endif