/**
 * @file ATBuiltInFunctionCompute.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-15
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef AT_BUILTIN_FUNCTION_COMPUTATION_H
#define AT_BUILTIN_FUNCTION_COMPUTATION_H

#include <cmath>
#include <limits.h>
#include "../BuildingBlock/BuildingBlock.h"

namespace ExpressionManagement
{
    class BuiltInFunctionComputationAPI
    {
    public:
        /**
         * @brief Calculates value of built-in function without square brackets,
         * exception handling for computable domains of functions
         * @param VariableValue variable value that used to compute
         * @param BuiltInFunction string that serve as in Built-in function input
         * @return double as function value
         */
        static double BuiltInFunctionComputation(ExpressionUnit Function, double ArgumentValue)
        {
            if (Function.first == 5)
            {
                if (Function.second == "abs")
                    return abs(ArgumentValue);
                else if (Function.second == "ln")
                {
                    if (ArgumentValue <= 0.0)
                        throw std::runtime_error("Out of bound for natural logarithm!");
                    return log(ArgumentValue);
                }
                else if (Function.second == "sinh")
                    return sinh(ArgumentValue);
                else if (Function.second == "cosh")
                    return cosh(ArgumentValue);
                else if (Function.second == "tanh")
                    return tanh(ArgumentValue);
                else if (Function.second == "cotanh")
                {
                    double TempValue = tanh(ArgumentValue);
                    if (TempValue == 0.0)
                        throw std::runtime_error("Out of bound for cotanh!");
                    return 1.0 / TempValue;
                }
                else if (Function.second == "argsinh")
                    return asinh(ArgumentValue);
                else if (Function.second == "argcosh")
                    return acosh(ArgumentValue);
                else if (Function.second == "argtanh")
                {
                    if (ArgumentValue >= 1.0 || ArgumentValue <= -1.0)
                        throw std::runtime_error("Out of bound for argtanh!");
                    return atanh(ArgumentValue);
                }
                else if (Function.second == "argcoth")
                {
                    if (-1.0 <= ArgumentValue && ArgumentValue >= 1.0)
                        throw std::runtime_error("Out of bound for argcoth!");
                    return atanh(1.0 / ArgumentValue);
                }
            }
            else if (Function.first == 6)
            {
                if (Function == "log")
                {
                    if (ArgumentValue <= 0.0)
                        throw std::runtime_error("Out of bound for logarithm base 10!");
                    return log10(ArgumentValue);
                }
                else if (Function == "sin")
                    return sin(ArgumentValue);
                else if (Function == "cos")
                    return cos(ArgumentValue);
                else if (Function == "tan")
                    return tan(ArgumentValue);
                else if (Function == "cotan")
                {
                    double TempResult = tan(ArgumentValue);
                    if (TempResult == 0.0)
                        throw std::runtime_error("Out of bound for logarithm base 10!");
                    return 1.0 / TempResult;
                }
                else if (Function == "arcsin")
                {
                    if (ArgumentValue < -1.0 || ArgumentValue > 1.0)
                        throw std::runtime_error("Out of bound for arcsin!");
                    return asin(ArgumentValue);
                }
                else if (Function == "arccos")
                {
                    if (ArgumentValue < -1.0 || ArgumentValue > 1.0)
                        throw std::runtime_error("Out of bound for arccos!");
                    return acos(ArgumentValue);
                }
                else if (Function == "arctan")
                    return atan(ArgumentValue);
                else if (Function == "arccotan")
                {
                    if (ArgumentValue == 0.0)
                        throw std::runtime_error("Out of bound for arccotan!");
                    return atan(1.0 / ArgumentValue);
                }
                else if (Function == "sqrt")
                {
                    if (ArgumentValue <= 0.0)
                        throw std::runtime_error("Out of bound for square root!");
                    return sqrt(ArgumentValue);
                }
            }
        }
    };
    typedef class BuiltInFunctionComputationAPI BuiltInFunctionComputationAPI;
}

#endif