/**
 * @file TreeComputation.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-15
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef TREE_COMPUTATION_H
#define TREE_COMPUTATION_H

#include <cmath>
#include <limits.h>
#include "TreeConstruction.h"

namespace Expression
{
    class TreeComputation
    {
    private:
        bool isDigit(std::string InputToCheck)
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

    public:
        static double computeTreeExpression(TreeNode *Root, ValueMap ArgumentValueMap)
        {
            if (Root == NULL)
                throw std::runtime_error("Do not have expression");
            else
            {
                if (Root->Data.first >= PowerOperatorID && Root->Data.first <= AddSubOperatorID)
                {
                    double LeftTreeValue = computeTreeExpression(Root->Left, ArgumentValueMap);
                    double RightTreeValue = computeTreeExpression(Root->Right, ArgumentValueMap);
                    if (Root->Data.second == "^")
                        return pow(LeftTreeValue, RightTreeValue);
                    else if (Root->Data.second == "*")
                        return LeftTreeValue * RightTreeValue;
                    else if (Root->Data.second == "/")
                    {
                        if (RightTreeValue == 0.0)
                            throw std::runtime_error("Divided by zero!");
                        return LeftTreeValue / RightTreeValue;
                    }
                    else if (Root->Data.second == "+")
                        return LeftTreeValue + RightTreeValue;
                    else if (Root->Data.second == "-")
                        return LeftTreeValue - RightTreeValue;
                }
                else if (Root->Data.first >= FunctionID && Root->Data.first <= ParaOptFunctionID)
                {
                    if (Root->Left != NULL && Root->Right != NULL)
                    {
                        double LeftValue = computeTreeExpression(Root->Left, ArgumentValueMap);
                        double RightValue = computeTreeExpression(Root->Right, ArgumentValueMap);
                        if (Root->Data.second == "sin")
                            return sin(LeftValue * RightValue);
                        else if (Root->Data.second == "cos")
                            return cos(LeftValue * RightValue);
                        else if (Root->Data.second == "tan")
                            return tan(LeftValue * RightValue);
                        else if (Root->Data.second == "cotan")
                        {
                            double TempResult = tan(LeftValue * RightValue);
                            if (TempResult == 0.0)
                                throw std::runtime_error("Out of bound for cotan base 10!");
                            return 1.0 / tan(LeftValue * RightValue);
                        }
                        else if (Root->Data.second == "arcsin")
                        {
                            if (RightValue < -1.0 || RightValue > 1.0)
                                throw std::runtime_error("Out of bound for arcsin!");
                            return asin(RightValue) / LeftValue;
                        }
                        else if (Root->Data.second == "arccos")
                        {
                            if (RightValue < -1.0 || RightValue > 1.0)
                                throw std::runtime_error("Out of bound for arccos!");
                            return acos(RightValue) / LeftValue;
                        }
                        else if (Root->Data.second == "arctan")
                            return atan(RightValue) / LeftValue;
                        else if (Root->Data.second == "arccotan")
                        {
                            if (RightValue == 0.0)
                                throw std::runtime_error("Out of bound for arccotan!");
                            return atan(1.0 / RightValue) / LeftValue;
                        }
                        else if (Root->Data.second == "sqrt")
                            return pow(RightValue, 1.0 / LeftValue);
                        else if (Root->Data.second == "log")
                            return log10(RightValue) / log10(LeftValue);
                    }
                    else if (Root->Left == NULL && Root->Right != NULL)
                    {
                        double RightValue = computeTreeExpression(Root->Right, ArgumentValueMap);
                        if (Root->Data.second == "abs")
                            return abs(RightValue);
                        else if (Root->Data.second == "ln")
                        {
                            if (RightValue <= 0.0)
                                throw std::runtime_error("Out of bound for natural logarithm!");
                            return log(RightValue);
                        }
                        else if (Root->Data.second == "sinh")
                            return sinh(RightValue);
                        else if (Root->Data.second == "cosh")
                            return cosh(RightValue);
                        else if (Root->Data.second == "tanh")
                            return tanh(RightValue);
                        else if (Root->Data.second == "cotanh")
                        {
                            double TempValue = tanh(RightValue);
                            if (TempValue == 0.0)
                                throw std::runtime_error("Out of bound for cotanh!");
                            return 1.0 / TempValue;
                        }
                        else if (Root->Data.second == "argsinh")
                            return asinh(RightValue);
                        else if (Root->Data.second == "argcosh")
                            return acosh(RightValue);
                        else if (Root->Data.second == "argtanh")
                        {
                            if (RightValue >= 1.0 || RightValue <= -1.0)
                                throw std::runtime_error("Out of bound for argtanh!");
                            return atanh(RightValue);
                        }
                        else if (Root->Data.second == "argcoth")
                        {
                            if (-1.0 <= RightValue && RightValue >= 1.0)
                                throw std::runtime_error("Out of bound for argcoth!");
                            return atanh(1.0 / RightValue);
                        }
                        else if (Root->Data.second == "sin")
                            return sin(RightValue);
                        else if (Root->Data.second == "cos")
                            return cos(RightValue);
                        else if (Root->Data.second == "tan")
                            return tan(RightValue);
                        else if (Root->Data.second == "cotan")
                        {
                            double TempResult = tan(RightValue);
                            if (TempResult == 0.0)
                                throw std::runtime_error("Out of bound for cotan base 10!");
                            return 1.0 / tan(RightValue);
                        }
                        else if (Root->Data.second == "arcsin")
                        {
                            if (RightValue < -1.0 || RightValue > 1.0)
                                throw std::runtime_error("Out of bound for arcsin!");
                            return asin(RightValue);
                        }
                        else if (Root->Data.second == "arccos")
                        {
                            if (RightValue < -1.0 || RightValue > 1.0)
                                throw std::runtime_error("Out of bound for arccos!");
                            return acos(RightValue);
                        }
                        else if (Root->Data.second == "arctan")
                            return atan(RightValue);
                        else if (Root->Data.second == "arccotan")
                        {
                            if (RightValue == 0.0)
                                throw std::runtime_error("Out of bound for arccotan!");
                            return atan(1.0 / RightValue);
                        }
                        else if (Root->Data.second == "sqrt")
                            return sqrt(RightValue);
                        else if (Root->Data.second == "log")
                            return log10(RightValue);
                    }
                }
                else if (Root->Left == NULL && Root->Right == NULL)
                {
                    if (Root->Data.first == 11)
                        return UniversalConstant.at(Root->Data.second);
                    else if (Root->Data.first == 10)
                        return stod(Root->Data.second);
                    else if (Root->Data.first == 12)
                        return ArgumentValueMap.at(Root->Data.second);
                }
            }
            return std::numeric_limits<double>::max();
        }
    };
    typedef class TreeComputation TreeComputation;
}

#endif
