/**
 * @file PriorityOrderCompute.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef PRIORITY_ORDER_COMPUTE_CPP
#define PRIORITY_ORDER_COMPUTE_CPP

#include <string>
#include <iostream>

namespace ExpressionManagement
{
    /**
     * @brief Gives order for all entities consisting of operators and operands. 
     * Modify simultaneously with IsOperator.cpp
     * @param Checking input to calculate rank of the entity
     * @return int as its rank
     */
    int PriorityOrder(char Checking)
    {
        if (Checking == '^')
            return 3;
        if (Checking == '*' || Checking == '/')
            return 2;
        else if (Checking == '+' || Checking == '-')
            return 1;
        else
            return 0;
    }

     /**
     * @brief Gives order for all entities consisting of operators and operands. 
     * Modify simultaneously with IsOperator.cpp
     * @param Checking input to calculate rank of the entity
     * @return int as its rank
     */
    int PriorityOrder(std::string Checking)
    {
        if (Checking == "^")
            return 3;
        if (Checking == "*" || Checking == "/")
            return 2;
        else if (Checking == "+" || Checking == "-")
            return 1;
        else
            return 0;
    }
}
#endif