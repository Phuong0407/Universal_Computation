/**
 * @file TreeExpressionCompute.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#ifndef TREE_EXPRESSION_COMPUTE_CPP
#define TREE_EXPRESSION_COMPUTE_CPP

#include "../ProcessingMethod/ProcessingMainMethodAPI.cpp"
#include <limits.h>

namespace ExpressionManagement
{
    /**
     * @brief Recursively calculate from an expression tree (without any arguments). 
     * Using exception handling to tackle with value out of domain of built-in function
     * @param ExpressionTreeRootInput input to compute
     * @return double as result
     */
    double ComputeExpressionValue(TreeExpressionBuildingBlock *ExpressionTreeRootInput)
    {
        double LeftSubExpressionTreeValue = 0.0;
        double RightSubExpressionTreeValue = 0.0;
        double InsideExpressionParameterValue = 0.0;
        if (ExpressionTreeRootInput == NULL)
            throw std::runtime_error("No expression tree exists, please check the file ExpressionTreeConstruction.cpp");
        if (ExpressionTreeRootInput->Left == NULL && ExpressionTreeRootInput->Right == NULL)
        {
            if (IsDigit(ExpressionTreeRootInput->Data) == true)
                return stod(ExpressionTreeRootInput->Data);
            else if (IsConstant(ExpressionTreeRootInput->Data) == true)
                return Constant.at(ExpressionTreeRootInput->Data);
        }
        else if (ExpressionTreeRootInput->Left == NULL && ExpressionTreeRootInput->Right != NULL)
        {
            if (IsBuiltInFunctions(ExpressionTreeRootInput->Data) == true)
            {
                InsideExpressionParameterValue = ComputeExpressionValue(ExpressionTreeRootInput->Right);
                return BuiltInFunctionsComputation(InsideExpressionParameterValue, ExpressionTreeRootInput->Data);
            }
            else
                throw std::invalid_argument("Is not a built-in functions. Please check ExpressionBuildingBlock.h");
        }
        else if (ExpressionTreeRootInput->Left != NULL && ExpressionTreeRootInput->Right != NULL)
        {
            LeftSubExpressionTreeValue = ComputeExpressionValue(ExpressionTreeRootInput->Left);
            RightSubExpressionTreeValue = ComputeExpressionValue(ExpressionTreeRootInput->Right);
            if (ExpressionTreeRootInput->Data == "^")
                return pow(LeftSubExpressionTreeValue, RightSubExpressionTreeValue);
            else if (ExpressionTreeRootInput->Data == "*")
                return LeftSubExpressionTreeValue * RightSubExpressionTreeValue;
            else if (ExpressionTreeRootInput->Data == "/")
            {
                if (RightSubExpressionTreeValue == 0)
                    throw std::invalid_argument("Divided by zero");
                else
                    return LeftSubExpressionTreeValue / RightSubExpressionTreeValue;
            }
            else if (ExpressionTreeRootInput->Data == "+")
                return LeftSubExpressionTreeValue + RightSubExpressionTreeValue;
            else if (ExpressionTreeRootInput->Data == "-")
                return LeftSubExpressionTreeValue - RightSubExpressionTreeValue;
            else
                throw std::invalid_argument("Do not belongs to operators set. Please check again that the expression is valid!");
        }
        else
            throw std::invalid_argument("Please check again that the expression is valid!");
        return std::numeric_limits<double>::max();
    }
}
#endif