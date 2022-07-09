/**
 * @file IsOperator.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef IS_OPERATOR_CPP
#define IS_OPERATOR_CPP

#include <iostream>
namespace ExpressionManagement
{
    /**
     * @brief Checks whether input expression is operator or not. 
     * Operators are '^', '*', '/', '+', '-'. Can add more operators for future development. 
     * Modify simultaneously with IsOperator.cpp
     * @param Checking input to check
     * @return true if char is operator
     */
    bool IsOperator(char Checking)
    {
        if (Checking == '^')
            return true;
        else if (Checking == '*')
            return true;
        else if (Checking == '/')
            return true;
        else if (Checking == '+')
            return true;
        else if (Checking == '-')
            return true;
        else
            return false;
    }

    /**
     * @brief Checks whether input expression is operator or not. 
     * Operators are '^', '*', '/', '+', '-'. Can add more operators for future development. 
     * Modify simultaneously with IsOperator.cpp
     * @param Checking input to check
     * @return true if string is operator
     */
    bool IsOperator(std::string Checking)
    {
        if (Checking == "^")
            return true;
        else if (Checking == "*")
            return true;
        else if (Checking == "/")
            return true;
        else if (Checking == "+")
            return true;
        else if (Checking == "-")
            return true;
        else
            return false;
    }
}
#endif