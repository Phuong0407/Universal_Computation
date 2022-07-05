/**
 * @file ExpressionTreeComputation.cpp is the implementation file of ExpressionTreeComputation.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-02
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_TREE_COMPUTATION_CPP
#define EXPRESSION_TREE_COMPUTATION_CPP

#include "ExpressionTreeComputation.h"

namespace ExpressionManagement
{
    /**
     * @brief We want to check an expression is valid or not
     * @brief The valid character are the alphabet, 5 operators, numbers and '.' for real number, and '_'
     * @param ExpressionStringToCheck is the input to check
     * @return true
     */
    bool ExpressionTreeComputation::IsValidExpression(std::string ExpressionStringToCheck)
    {
        char Checker;
        for (unsigned int i = 0; i < ExpressionStringToCheck.length(); i++)
        {
            if (Checker >= 'a' && Checker <= 'z')
                continue;
            else if (Checker >= 'A' && Checker <= 'Z')
                continue;
            else if (Checker >= '0' && Checker <= '9')
                continue;
            else if (Checker == '.' || Checker == '^' || Checker == '*' || Checker == '/' || Checker == '+' || Checker == '-')
                continue;
            else if (Checker == '_')
                continue;
            else
                return false;
        }
        return true;
    }

    /**
     * @brief This is the input API to initialize expression computation class
     * @brief We do not combine initialization and computation
     * @param ExpressionStringInput
     * @param ExpressionArgumentValue
     * @param FromKeyBoardInitializeArgumentList is default boolean argument, true if we want to get argument value from keyboard
     */
    void ExpressionTreeComputation::ComputeExpressionValueInitialization(std::string ExpressionStringInput, std::vector<double> ExpressionArgumentValue, bool FromKeyBoardInitializeArgumentList)
    {
        if (this->OutputExpressionInitial() != ExpressionStringInput)
        {
            if (IsValidExpression(ExpressionStringInput) == true)
            {
                this->ExpressionTreeInitialization(ExpressionStringInput);
                this->CreateListOfArgumentName();
                if (FromKeyBoardInitializeArgumentList == true)
                    this->CreateListOfArgumentValueFromKeyBoard();
                else
                {
                    if (ExpressionArgumentValue.size() != this->OutputArgumentListName().size())
                        throw std::runtime_error("Give an incompatible-size list of arguments. Please give another list or arguments!");
                    this->CreateListOfArgumentValueFromGivenData(ExpressionArgumentValue);
                }
            }
            else
                throw std::invalid_argument("Invalid expression");
        }
    }

    /**
     * @brief CreateListOfArgumentName is used to get a list of argument names
     */
    void ExpressionTreeComputation::CreateListOfArgumentName()
    {
        std::string ArgumentNameUnitBuilder = "";
        std::vector<std::string> OperandsListBuilder = this->OutputOperandsList();
        if (OperandsListBuilder.empty() == true)
            throw std::invalid_argument("Wrong in algorithm, please check the method decomposition the file ExpressionCustomTokenDecomposition.cpp!");
        for (unsigned int i = 0; i < OperandsListBuilder.size(); ++i)
        {
            if (IsDigit(OperandsListBuilder[i]) == true)
                continue;
            else if (IsBuiltInFunctions(OperandsListBuilder[i]) == true)
                continue;
            else
            {
                ArgumentNameUnitBuilder = OperandsListBuilder[i];
                this->ArgumentNameList.push_back(ArgumentNameUnitBuilder);
            }
        }
    }

    /**
     * @brief CreateListOfArgumentValue...() are used to initialize argument value (consisting of argument name and value)
     */
    void ExpressionTreeComputation::CreateListOfArgumentValueFromKeyBoard()
    {
        double ArgumentValueScanner = 0.0;
        std::cout << "Enter values for variables: " << std::endl;
        for (unsigned int i = 0; i < ArgumentNameList.size(); ++i)
        {
            std::cout << "Enter value for " << ArgumentNameList[i] << ": " << std::endl;
            std::cin >> ArgumentValueScanner;
            this->ArgumentValueList[ArgumentNameList[i]] = ArgumentValueScanner;
        }
    }

    void ExpressionTreeComputation::CreateListOfArgumentValueFromGivenData(std::vector<double> InputArgumentValue)
    {
        double ArgumentValueScanner = 0.0;
        if (InputArgumentValue.size() != this->ArgumentNameList.size())
            throw std::invalid_argument("Not compatible between number of variables and number of input variable value");
        for (unsigned int i = 0; i < ArgumentNameList.size(); ++i)
            this->ArgumentValueList[ArgumentNameList[i]] = ArgumentValueScanner;
    }

    /**
     * @brief Checking whether an argument is belongs to argument name list
     * @param ArgumentNameToCheck is string to check
     * @return true
     */
    bool ExpressionTreeComputation::IsArgumentExistence(std::string ArgumentNameToCheck)
    {
        if (this->ArgumentValueList.find(ArgumentNameToCheck) == this->ArgumentValueList.end())
            return false;
        else
            return true;
    }

    /**
     * @brief We search from ArgumentValueList
     * @param ArgumentNameToFind is string to find
     * @return double
     */
    double ExpressionTreeComputation::FindValueFromArgumentName(std::string ArgumentNameToFind)
    {
        if (IsArgumentExistence(ArgumentNameToFind) == false)
            throw std::invalid_argument("Do not have this variable in this expression! Please check the file ExpressionTreeComputation.cpp");
        return this->ArgumentValueList.at(ArgumentNameToFind);
    }

    /**
     * @brief We use recursive algorithm to calculate
     * @param ArgumentValueListParameter is used to calculate
     * @param ExpressionTreeRootInput is default parameters that null for the API
     * @return double
     */
    double ExpressionTreeComputation::ComputeExpressionValue(std::unordered_map<std::string, double> ArgumentValueListParameter, TreeExpressionBuildingBlock *ExpressionTreeRootInput)
    {
        double InsideExpressionParameterValue = 0.0;
        double RightSubExpressionTreeValue = 0.0;
        double LeftSubExpressionTreeValue = 0.0;
        TreeExpressionBuildingBlock *ExpressionTreeToCompute = new TreeExpressionBuildingBlock[1];
        ExpressionTreeToCompute = this->OutputExpressionTree();
        if (ExpressionTreeToCompute == NULL)
            throw std::invalid_argument("No expression tree exists, please check the file ExpressionTreeConstruction.cpp");
        if (ExpressionTreeToCompute->Left == NULL && ExpressionTreeToCompute->Right == NULL)
        {
            if (IsDigit(ExpressionTreeToCompute->Data) == true)
                return stod(ExpressionTreeToCompute->Data);
            else if (IsConstant(ExpressionTreeToCompute->Data) == true)
                return Constant.at(ExpressionTreeToCompute->Data);
            else if (IsArgumentExistence(ExpressionTreeToCompute->Data) == true)
                return this->FindValueFromArgumentName(ExpressionTreeToCompute->Data);
        }
        else if (ExpressionTreeToCompute->Left == NULL && ExpressionTreeToCompute->Right != NULL)
        {
            if (IsBuiltInFunctions(ExpressionTreeToCompute->Data) == true)
            {
                InsideExpressionParameterValue = this->ComputeExpressionValue(this->ArgumentValueList, ExpressionTreeToCompute->Right);
                return BuiltInFunctionsComputation(InsideExpressionParameterValue, ExpressionTreeToCompute->Data);
            }
            else
                throw std::invalid_argument("Is not a built-in functions. Please check ExpressionBuildingBlock.h");
        }
        else if (ExpressionTreeToCompute->Left != NULL && ExpressionTreeToCompute->Right != NULL)
        {
            LeftSubExpressionTreeValue = ComputeExpressionValue(this->ArgumentValueList, ExpressionTreeToCompute->Left);
            RightSubExpressionTreeValue = ComputeExpressionValue(this->ArgumentValueList, ExpressionTreeToCompute->Right);
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

    std::vector<std::string> ExpressionTreeComputation::OutputArgumentListName()
    {
        return this->ArgumentNameList;
    }

    std::unordered_map<std::string, double> ExpressionTreeComputation::OutputArgumentListValue()
    {
        return this->ArgumentValueList;
    }

    double ExpressionTreeComputation::OutputExpressionValue()
    {
        return this->ExpressionValue;
    }
}
#endif