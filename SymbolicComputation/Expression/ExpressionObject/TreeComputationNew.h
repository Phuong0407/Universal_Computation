/**
 * @file TreeComputation.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief This file contains a class which will calculate an expression value if we know its arguments values
 * @version 2.0
 * @date 2022-07-01
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef TREE_COMPUTATION_H
#define TREE_COMPUTATION_H

#include "ExpressionTreeObject.h"
#include "../ValueComputationProcessing/TreeExpressionCompute.cpp"

namespace ExpressionManagement
{
    typedef std::pair<std::string, ExpressionTreeObject> ArgumentSubTreeUnit;
    typedef std::pair<std::string, std::string> ArgumentSubString;
    class TreeComputation
    {
    private:
        ExpressionTreeObject MainExpression;
        ExpressionTreeObject TreeExpressionToCompute;    // Without any argument name
        std::vector<ArgumentSubTreeUnit> InputProcessor; // Data structure to store argument name and its subexpression
        std::unordered_map<std::string, double> ArgumentValueList;

    public:
        void InitializeMainExpression(std::string);
        void InitializeArgumentNameFromKeyBoard();
        void TreeExpressionInsertSubExpression();
        ArgumentSubTreeUnit GetInputArgumentStringKeyBoard(std::string);
        void GetInputArgumentStringGivenData();
        double OutputExpressionValueComputed();
        CustomTokenUnit OutputArgumentNameList();
        void TreeComputationInputAPI(std::string);
        void CreateArgumentValue(std::vector<ArgumentSubTreeUnit>);
    };
    typedef class TreeComputation TreeComputation;

    void TreeComputation::InitializeMainExpression(std::string StringExpressionInput)
    {
        MainExpression.TreeExpressionObjectInputAPI(StringExpressionInput);
    }

    void TreeComputation::InitializeArgumentNameFromKeyBoard()
    {
        CustomTokenUnit ArgumentName = MainExpression.OutputArgumentNameList();
        for (unsigned int i = 0; i < ArgumentName.size(); ++i)
            InputProcessor.push_back(GetInputArgumentStringKeyBoard(ArgumentName[i]));
    }

    /**
     * @brief It takes vector of pair (name, real value) to make an unordered_map of argument value
     * @param ArgumentValueListInput
     */
    void TreeComputation::CreateArgumentValue(std::vector<ArgumentSubTreeUnit> ArgumentValueListInput)
    {
        double ArgumentValueScanner = 0.0;
        if (ArgumentValueListInput.size() != this->ArgumentNameList.size())
            throw std::runtime_error("Not compatible between number of variables and number of input variable value!");
        for (unsigned int i = 0; i < this->ArgumentNameList.size(); ++i)
        {
            if (this->ArgumentNameList[i] != ArgumentValueListInput[i].first)
                throw std::runtime_error("Not compatible between variables name!");
            else
                this->ArgumentValueList[ArgumentNameList[i]] = ArgumentValueListInput[i].second;
        }
    }

    void TreeComputation::TreeExpressionInsertSubExpression()
    {
        for (unsigned int i = 0; i < InputProcessor.size(); ++i)
        {
            TreeExpressionToCompute.InputArgumentReplacer(InputProcessor[i].first, InputProcessor[i].second);
                }
    }

    /**
     * @brief GetInputArgumentStringKeyBoard() used to get argument subexpression from keyboard,
     * @brief it get string from keyboard, then it creates ExpressionTreeObject,
     * @brief finally, it forms a pair of string and ExpressionTreeObject,
     * @param ArgumentName is the argument name got from the main expression
     * @return ArgumentSubTreeUnit to make a vector of substring
     */
    ArgumentSubTreeUnit
    TreeComputation::GetInputArgumentStringKeyBoard(std::string ArgumentName)
    {
        std::string InputScanner = "";
        ExpressionTreeObject ArgumentInputObject;
        ArgumentSubTreeUnit InputNameFromKeyBoardBuilder;
        std::cout << "Enter values for variables " << ArgumentName << ": " << std::endl;
        std::getline(std::cin, InputScanner);
        if (IsValidExpression(InputScanner) == false)
            throw std::runtime_error("Invalid expression!");
        ArgumentInputObject.TreeExpressionObjectInputAPI(ArgumentName);
        InputNameFromKeyBoardBuilder(ArgumentName, ArgumentInputObject);
        return InputNameFromKeyBoardBuilder;
    }

    /**
     * @brief This function is an API to communicate with class TreeComputation
     * @brief then, it builds an expression tree and creates a list of argument name to get value later
     * @param StringExpressionInput
     */
    void TreeComputation::TreeComputationInputAPI(std::string StringExpressionInput)
    {
        this->TreeExpressionObjectInputAPI(StringExpressionInput);
        this->CreateArgumentName();
    }

    double TreeComputation::OutputExpressionValueComputed()
    {
        return ComputeExpressionValue(this->OutputExpressionTreeRoot(), this->ArgumentNameList, this->ArgumentValueList);
    }

    CustomTokenUnit TreeComputation::OutputArgumentNameList()
    {
        return this->ArgumentNameList;
    }
}

#endif