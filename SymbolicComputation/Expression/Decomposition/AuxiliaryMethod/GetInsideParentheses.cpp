/**
 * @file GetInsideParentheses.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#include "GetInsideParentheses.h"

#ifndef GET_INSIDE_PARENTHESES_CPP
#define GET_INSIDE_PARENTHESES_CPP
namespace ExpressionManagement
{
    /**
     * @brief GetInsideParentheses will take expression inside parentheses
     * @brief It will serve as a part of recursive algorithm of expression decompositions
     * @param Input is the expression to
     * @return std::string
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
     * @brief GetInsideParentheses will take expression inside parentheses
     * @brief It will serve as a part of recursive algorithm of expression decompositions
     * @param Input is the expression to
     * @return CustomTokenUnit
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

int main()
{
}