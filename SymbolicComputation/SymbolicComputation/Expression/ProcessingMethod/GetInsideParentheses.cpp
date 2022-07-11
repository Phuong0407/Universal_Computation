/**
 * @file GetInsideParentheses.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

//#include "GetInsideParentheses.h"
#pragma once
#ifndef GET_INSIDE_PARENTHESES_CPP
#define GET_INSIDE_PARENTHESES_CPP

#include "IsBalance.cpp"
#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief Gets expression inside parentheses, it only accepts the string in the form "(---)---", not all the others,
     * Using IsBalance() to check whether the set of parentheses is balance
     * @param Input expression to get
     * @return std::string as expression inside parentheses in the form (---)
     */
    std::string GetInsideParentheses(std::string Input)
    {
        unsigned int PositionTracker = 0;
        std::string InsideParenthesesExpressionBuilder = "";
        char InputScanner = Input[PositionTracker];
        InsideParenthesesExpressionBuilder += InputScanner;
        while (PositionTracker < Input.length())
        {
            PositionTracker++;
            InputScanner = Input[PositionTracker];
            InsideParenthesesExpressionBuilder += InputScanner;
            if (IsBalance(InsideParenthesesExpressionBuilder) == true && InputScanner == ')')
                break;
            else
                continue;
        }
        return InsideParenthesesExpressionBuilder;
    }

    /**
     * @brief Gets expression inside parentheses, it only accepts the string in the form "(---)---", not all the others,
     * Using IsBalance() to check whether the set of parentheses is balance
     * @param Input expression to get
     * @return CustomTokenUnit as expression inside parentheses in the form (---)
     */
    CustomTokenUnit GetInsideParentheses(CustomTokenUnit Input)
    {
        unsigned int PositionTracker = 0;
        CustomTokenUnit InsideParenthesesExpressionBuilder;
        std::string InputScanner = Input[PositionTracker];
        InsideParenthesesExpressionBuilder.push_back(InputScanner);
        while (PositionTracker < Input.size())
        {
            PositionTracker++;
            InputScanner = Input[PositionTracker];
            InsideParenthesesExpressionBuilder.push_back(InputScanner);
            if (IsBalance(InsideParenthesesExpressionBuilder) == true && InputScanner == ")")
                break;
            else
                continue;
        }
        return InsideParenthesesExpressionBuilder;
    }
}
#endif