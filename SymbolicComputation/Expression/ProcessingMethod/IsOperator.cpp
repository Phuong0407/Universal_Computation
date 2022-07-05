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
     * @brief IsOperator checks whether input expression is operator or not
     * @brief Operators are '^', '*', '/', '+', '-' in version 2.0
     * @brief Can add more operators for future development
     * @param Checking is the input to check
     * @return true or false
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
     * @brief IsOperator checks whether input expression is operator or not
     * @brief Operators are '^', '*', '/', '+', '-' in version 2.0
     * @brief Can add more operators for future development
     * @param Checking is the input to check
     * @return true or false
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

// using namespace std;
// using namespace ExpressionManagement;
// int main()
// {
//     if (IsOperator("/") == true)
//         cout << "true";
//     if (IsOperator('^') == true)
//         cout << "true";
// }