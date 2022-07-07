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

    class TreeComputation : public ExpressionTreeObject
    {
    protected:
        CustomTokenUnit ArgumentNameList;
        std::unordered_map<std::string, double> ArgumentValueList;

    public:
        void CreateArgumentName();
        double OutputExpressionValueComputed();
        CustomTokenUnit OutputArgumentNameList();
        void TreeComputationInputAPI(std::string);
        void CreateArgumentValue(std::vector<ArgumentPairUnit>);
    };
    typedef class TreeComputation TreeComputation;

    /**
     * @brief This function will create a CustomTokenUnit,
     * @brief It creates and stores argument name to get value later
     */
    void TreeComputation::CreateArgumentName()
    {
        std::string ArgumentNameBuilder = "";
        CustomTokenUnit OperandsList = this->OutputExpressionCustomTokenInfix();
        if (OperandsList.empty() == true)
            throw std::invalid_argument("Wrong in algorithm or invalid expression!");
        for (unsigned int i = 0; i < OperandsList.size(); ++i)
        {
            if (IsDigit(OperandsList[i]) == true)
                continue;
            else if (IsBuiltInFunctions(OperandsList[i]) == true)
                continue;
            else if (IsConstant(OperandsList[i]) == true)
                continue;
            else if (IsOperator(OperandsList[i]) == true)
                continue;
            else if (OperandsList[i] == "(" || OperandsList[i] == ")")
                continue;
            else
            {
                ArgumentNameBuilder = OperandsList[i];
                ArgumentNameList.push_back(ArgumentNameBuilder);
            }
        }
    }
    /**
     * @brief It takes vector of pair (name, real value) to make an unordered_map of argument value
     * @param ArgumentValueListInput
     */
    void TreeComputation::CreateArgumentValue(std::vector<ArgumentPairUnit> ArgumentValueListInput)
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