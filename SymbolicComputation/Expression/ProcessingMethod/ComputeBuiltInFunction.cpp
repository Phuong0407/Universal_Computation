/**
 * @file ComputeBuiltInFunction.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-06
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef COMPUTE_BUILT_IN_FUNCTION_CPP
#define COMPUTE_BUILT_IN_FUNCTION_CPP

#include "IsBuiltInFunction.cpp"

namespace ExpressionManagement
{
    /**
     * @brief Calculates value of built-in function with variable values, 
     * exception handling for computable domains of functions
     * @param VariableValue variable value that used to compute
     * @param BuiltInFunction string that serve as in Built-in function input
     * @return double as function value
     */
    double BuiltInFunctionsComputation(double VariableValue, std::string BuiltInFunction)
    {
        double FunctionValueComputation = 0.0;
        if (IsBuiltInFunctions(BuiltInFunction) == false)
            throw std::runtime_error("Invalid expression!");
        else if (BuiltInFunction == "abs")
            FunctionValueComputation = abs(VariableValue);
        else if (BuiltInFunction == "log")
        {
            if (VariableValue <= 0.0)
                throw std::runtime_error("Out of bound for logarithm base 10!");
            FunctionValueComputation = log10(VariableValue);
        }
        else if (BuiltInFunction == "ln")
        {
            if (VariableValue <= 0.0)
                throw std::runtime_error("Out of bound for natural logarithm!");
            FunctionValueComputation = log(VariableValue);
        }
        else if (BuiltInFunction == "sin")
            FunctionValueComputation = sin(VariableValue);
        else if (BuiltInFunction == "cos")
            FunctionValueComputation = cos(VariableValue);
        else if (BuiltInFunction == "tan")
            FunctionValueComputation = tan(VariableValue);
        else if (BuiltInFunction == "cotan")
            FunctionValueComputation = 1.0 / tan(VariableValue);
        else if (BuiltInFunction == "arcsin")
        {
            if (VariableValue < -1.0 || VariableValue > 1.0)
                throw std::runtime_error("Out of bound for arcsin!");
            FunctionValueComputation = asin(VariableValue);
        }
        else if (BuiltInFunction == "arccos")
        {
            if (VariableValue < -1.0 || VariableValue > 1.0)
                throw std::runtime_error("Out of bound for arccos!");
            FunctionValueComputation = acos(VariableValue);
        }
        else if (BuiltInFunction == "arctan")
            FunctionValueComputation = atan(VariableValue);
        else if (BuiltInFunction == "arccotan")
        {
            if (VariableValue == 0.0)
                throw std::runtime_error("Out of bound for arccotan!");
            FunctionValueComputation = atan(1.0 / VariableValue);
        }
        else if (BuiltInFunction == "sinh")
            FunctionValueComputation = sinh(VariableValue);
        else if (BuiltInFunction == "cosh")
            FunctionValueComputation = cosh(VariableValue);
        else if (BuiltInFunction == "tanh")
            FunctionValueComputation = tanh(VariableValue);
        else if (BuiltInFunction == "cotanh")
        {
            FunctionValueComputation = tanh(VariableValue);
            if (FunctionValueComputation == 0.0)
                throw std::runtime_error("Out of bound for cotanh!");
            FunctionValueComputation = 1.0 / FunctionValueComputation;
        }
        else if (BuiltInFunction == "argsinh")
            FunctionValueComputation = asinh(VariableValue);
        else if (BuiltInFunction == "argcosh")
        {
            if (VariableValue < 1.0)
                throw std::runtime_error("Out of bound for argcosh!");
            FunctionValueComputation = acosh(VariableValue);
        }
        else if (BuiltInFunction == "argtanh")
        {
            if (VariableValue >= 1.0 || VariableValue <= -1.0)
                throw std::runtime_error("Out of bound for argtanh!");
            FunctionValueComputation = atanh(VariableValue);
        }
        else if (BuiltInFunction == "argcoth")
        {
            if (-1.0 <= VariableValue && VariableValue <= 1.0)
                throw std::runtime_error("Out of bound for argcoth!");
            FunctionValueComputation = atanh(1.0 / VariableValue);
        }
        else if (BuiltInFunction == "sqrt")
        {
            if (VariableValue <= 0.0)
                throw std::runtime_error("Out of bound for square root!");
            FunctionValueComputation = sqrt(VariableValue);
        }
        else if(BuiltInFunction.length() >= 4)
        {
            std::string CheckingRootFunctionNotation = BuiltInFunction.substr(0, 3);
            std::string CheckingRootFunctionOrder = BuiltInFunction.substr(3, BuiltInFunction.length());
            if (CheckingRootFunctionNotation == "log")
            {
                double LogBase = stod(CheckingRootFunctionOrder);
                if(LogBase < 0.0)
                    throw std::runtime_error("Negative base of logarithm!");
                return log10(VariableValue)/log10(LogBase);
            }
        }
        else if (BuiltInFunction.length() >= 5)
        {
            std::string CheckingRootFunctionNotation = BuiltInFunction.substr(0, 4);
            std::string CheckingRootFunctionOrder = BuiltInFunction.substr(4, BuiltInFunction.length());
            double RootOrder = std::stod(CheckingRootFunctionOrder);
            if(CheckingRootFunctionNotation == "sqrt")
            {
                if (VariableValue == 0)
                {
                    if (RootOrder < 0)
                        throw std::runtime_error("Root with negative-order of zero!");
                    else
                        return 0.0;
                }
                return pow(VariableValue, 1.0 / RootOrder);
            }
        }
        else
            throw std::runtime_error("Invalid argument!");
        return FunctionValueComputation;
    }
}

#endif