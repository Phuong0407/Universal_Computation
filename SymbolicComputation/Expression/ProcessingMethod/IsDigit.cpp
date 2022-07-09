/**
 * @file IsDigit.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef IS_DIGIT_CPP
#define IS_DIGIT_CPP

#include <string>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>

namespace ExpressionManagement
{
    /**
     * @brief Checks whether a string operand is a real number or not.
     * Please check if a string is an operand or not, or maybe not using!
     * @param InputToCheck operand to check
     * @return true if it is a number
     */
    bool IsDigit(std::string InputToCheck)
    {
        bool InputCheckerUnit = true;
        if (InputToCheck[0] == '-' || InputToCheck[0] == '+')
            return true;
        for (int i = 0; InputToCheck[i] != '\0'; i++)
            if (!isdigit(InputToCheck[i]))
            {
                if (InputToCheck[i] == '.')
                    continue;
                else
                    InputCheckerUnit = false;
            }
        return InputCheckerUnit;
    }
}
#endif