/**
 * @file IsValidExpression.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-06
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef IS_VALID_EXPRESSION_CPP
#define IS_VALID_EXPRESSION_CPP

#include <string>
#include <iostream>

namespace ExpressionManagement
{
    /**
     * @brief IsValidExpression is to check if an expression (accepted spaces) is valid or not
     * @brief Valid here is just a preprocessor method, we check for characters brief and not check for the meaning of the expression
     * @brief We will add some other special characters such as "!" later
     * @param ExpressionStringToCheck is the input string to check
     * @return true
     */
    bool IsValidExpression(std::string ExpressionStringToCheck)
    {
        char Checker;
        for (unsigned int i = 0; i < ExpressionStringToCheck.length(); i++)
        {
            Checker = ExpressionStringToCheck[i];
            if (Checker >= 'a' && Checker <= 'z')
                continue;
            else if (Checker >= 'A' && Checker <= 'Z')
                continue;
            else if (Checker >= '0' && Checker <= '9')
                continue;
            else if (Checker == '.' || Checker == '^' || Checker == '*' || Checker == '/' || Checker == '+' || Checker == '-')
                continue;
            else if (Checker == '_' || Checker == ' ' || Checker == '(' || Checker == ')')
                continue;
            else
                return false;
        }
        return true;
    }
}
#endif