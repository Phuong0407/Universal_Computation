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
#include "FindValueFromArgumentName.cpp"
#include "IsArgumentExistence.cpp"
#include <limits.h>

namespace ExpressionManagement
{
    /**
     * @brief We use recursive algorithm to calculate
     * @param ArgumentValueListParameter is used to calculate
     * @param ExpressionTreeRootInput is default parameters that null for the API
     * @return double
     */
    double ComputeExpressionValue(TreeExpressionBuildingBlock *ExpressionTreeRootInput, CustomTokenUnit ArgumentNameList,
                                  std::unordered_map<std::string, double> ArgumentValueList)
    {
        TreeExpressionBuildingBlock *ExpressionTreeToCompute = ExpressionTreeRootInput;
        double InsideExpressionParameterValue = 0.0;
        double RightSubExpressionTreeValue = 0.0;
        double LeftSubExpressionTreeValue = 0.0;
        if (ExpressionTreeToCompute == NULL)
            throw std::runtime_error("No expression tree exists, please check the file ExpressionTreeConstruction.cpp");
        if (ExpressionTreeToCompute->Left == NULL && ExpressionTreeToCompute->Right == NULL)
        {
            if (IsDigit(ExpressionTreeToCompute->Data) == true)
                return stod(ExpressionTreeToCompute->Data);
            else if (IsConstant(ExpressionTreeToCompute->Data) == true)
                return Constant.at(ExpressionTreeToCompute->Data);
            else if (IsArgumentExistence(ArgumentNameList, ExpressionTreeToCompute->Data) == true)
                return FindValueFromArgumentName(ArgumentNameList, ArgumentValueList, ExpressionTreeToCompute->Data);
        }
        else if (ExpressionTreeToCompute->Left == NULL && ExpressionTreeToCompute->Right != NULL)
        {
            if (IsBuiltInFunctions(ExpressionTreeToCompute->Data) == true)
            {
                InsideExpressionParameterValue = ComputeExpressionValue(ExpressionTreeToCompute->Right, ArgumentNameList, ArgumentValueList);
                return BuiltInFunctionsComputation(InsideExpressionParameterValue, ExpressionTreeToCompute->Data);
            }
            else
                throw std::invalid_argument("Is not a built-in functions. Please check ExpressionBuildingBlock.h");
        }
        else if (ExpressionTreeToCompute->Left != NULL && ExpressionTreeToCompute->Right != NULL)
        {
            LeftSubExpressionTreeValue = ComputeExpressionValue(ExpressionTreeToCompute->Left, ArgumentNameList, ArgumentValueList);
            RightSubExpressionTreeValue = ComputeExpressionValue(ExpressionTreeToCompute->Right, ArgumentNameList, ArgumentValueList);
            if (ExpressionTreeToCompute->Data == "^")
                return pow(LeftSubExpressionTreeValue, RightSubExpressionTreeValue);
            else if (ExpressionTreeToCompute->Data == "*")
                return LeftSubExpressionTreeValue * RightSubExpressionTreeValue;
            else if (ExpressionTreeToCompute->Data == "/")
            {
                if (RightSubExpressionTreeValue == 0)
                    throw std::invalid_argument("Divided by zero");
                else
                    return LeftSubExpressionTreeValue / RightSubExpressionTreeValue;
            }
            else if (ExpressionTreeToCompute->Data == "+")
                return LeftSubExpressionTreeValue + RightSubExpressionTreeValue;
            else if (ExpressionTreeToCompute->Data == "-")
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