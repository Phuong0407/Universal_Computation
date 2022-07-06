/**
 * @file TreeObjectComputation.h is the
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

    class TreeObjectComputation : public ExpressionTreeObject
    {
    private:
        CustomTokenUnit ArgumentNameList;
        std::unordered_map<std::string, double> ArgumentValueList;
        double ExpressionValue = 0.0;

        void CreateArgumentName();
        void CreateArgumentValueFromKeyBoard();
        void CreateArgumentValueFromGivenData(std::vector<ArgumentPairUnit>);

    public:
        double OutputExpressionValueComputed();
        void TreeComputationInputAPI(std::string, bool, std::vector<ArgumentPairUnit>);
    };
    typedef class TreeObjectComputation TreeObjectComputation;

    void TreeObjectComputation::CreateArgumentName()
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

    void TreeObjectComputation::CreateArgumentValueFromKeyBoard()
    {
        double ArgumentValueScanner = 0.0;
        std::cout << "Calculate expression " << this->OutputExpressionInitial() << std::endl;
        if (this->ArgumentNameList.empty() == false)
        {
            std::cout << "Enter values for variables: " << std::endl;
            for (unsigned int i = 0; i < this->ArgumentNameList.size(); ++i)
            {
                if (this->ArgumentValueList.find(this->ArgumentNameList[i]) == this->ArgumentValueList.end())
                {
                    std::cout << "Enter value for " << this->ArgumentNameList[i] << " = ";
                    std::cin >> ArgumentValueScanner;
                    this->ArgumentValueList[ArgumentNameList[i]] = ArgumentValueScanner;
                }
                else
                    continue;
            }
        }
    }

    void TreeObjectComputation::CreateArgumentValueFromGivenData(std::vector<ArgumentPairUnit> ArgumentValueListInput)
    {
        double ArgumentValueScanner = 0.0;
        if (ArgumentValueListInput.size() != this->ArgumentNameList.size())
            throw std::runtime_error("Not compatible between number of variables and number of input variable value");
        for (unsigned int i = 0; i < this->ArgumentNameList.size(); ++i)
        {
            if (this->ArgumentNameList[i] != ArgumentValueListInput[i].first)
                throw std::runtime_error("Not compatible between number of variables and number of input variable value");
            else
                this->ArgumentValueList[ArgumentNameList[i]] = ArgumentValueListInput[i].second;
        }
    }

    void TreeObjectComputation::TreeComputationInputAPI(std::string ExpressionStringInput, bool GetDataFromKeyboard, std::vector<ArgumentPairUnit> ArgumentValueListInput)
    {
        if (IsValidExpression(ExpressionStringInput) == false)
            throw std::runtime_error("Invalid expression!");
        this->TreeExpressionObjectInputAPI(ExpressionStringInput);
        this->CreateArgumentName();
        if (GetDataFromKeyboard == true)
            this->CreateArgumentValueFromKeyBoard();
        else
            this->CreateArgumentValueFromGivenData(ArgumentValueListInput);
    }
    double TreeObjectComputation::OutputExpressionValueComputed()
    {
        return ComputeExpressionValue(this->OutputExpressionTreeRoot(), this->ArgumentNameList, this->ArgumentValueList);
    }
}

#endif