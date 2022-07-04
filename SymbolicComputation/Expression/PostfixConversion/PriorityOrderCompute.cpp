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

#include "../../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief PriorityOrder gives order for all entities consisting of operators and operands
     * @brief This will serve for InfixToPostfix method later, can be develop further
     * @param Checking is the input to calculate rank of the entity
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
     * @brief PriorityOrder gives order for all entities consisting of operators and operands
     * @brief This will serve for InfixToPostfix method later, can be develop further
     * @param Checking is the input to calculate rank of the entity
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