/**
 * @file TreeComputationComplete.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#ifndef TREE_COMPUTATION_COMPLETE_H
#define TREE_COMPUTATION_COMPLETE_H

#include "TreeComputation.h"

namespace ExpressionManagement
{
    typedef std::pair<std::string, ExpressionTreeObject> InputExpressionUnit;

    class TreeComputationComplete
    {
    private:
        TreeComputation MainExpresion;
        TreeComputation AuxiliaryExpresion;
        InputExpressionUnit InputSubExpression;
        InputExpressionUnit GetInputArgumentExpression(std::string);

    public:
        void TreeComputationCompleteInputAPI(std::string);
    };
    typedef class TreeComputationComplete TreeComputationComplete;

    void TreeComputationComplete::TreeComputationCompleteInputAPI(std::string StringInputExpression)
    {
        this->MainExpresion.TreeComputationInputAPI(StringInputExpression);
        CustomTokenUnit ArgumentNameToGetInput = MainExpression.OutputArgumentNameList();
        for (unsigned int i = 0; i < ArgumentNameToGetInput.size(); ++i)
            InputProcessor.push_back(GetInputArgumentExpression(ArgumentNameToGetInput[i]));
    }

    InputExpressionUnit TreeComputationComplete::GetInputArgumentExpression(std::string ArgumentNameToGet)
    {
        std::string InputScanner = "";
        TreeComputation ArgumentInputObject;
        InputExpressionUnit InputNameFromKeyBoardBuilder;
        std::cout << "Enter values for variables " << ArgumentNameToGet << ": " << std::endl;
        std::getline(std::cin, InputScanner);
        if (IsValidExpression(InputScanner) == false)
            throw std::runtime_error("Invalid expression!");
        ArgumentInputObject.TreeComputationInputAPI(ArgumentNameToGet);
        InputNameFromKeyBoardBuilder(ArgumentNameToGet, ArgumentInputObject);
        return InputNameFromKeyBoardBuilder;
    }
}
#endif