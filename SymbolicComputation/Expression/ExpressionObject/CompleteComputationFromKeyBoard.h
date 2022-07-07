
#pragma once
#ifndef COMPLETE_COMPUTATION_H
#define COMPLETE_COMPUTATION_H

#include "TreeComputation.h"

namespace ExpressionManagement
{
    typedef std::vector<std::string, std::string>;
    typedef std::pair<std::string, ExpressionTreeObject> InputExpressionUnit;

    class CompleteComputation
    {
    private:
        TreeComputation MainExpression;
        std::vector<InputExpressionUnit> InputProcessor;    // rename later to be more descriptive
        std::vector<std::string> InputArgumentFromKeyBoard; // depending on cases of user input

    public:
        void KeyBoardInputAPI(std::string);
        InputExpressionUnit GetInputArgumentExpression(std::string);
        void CreateListOfArgument();
    };
    typedef class CompleteComputation CompleteComputation;

    void CompleteComputation::KeyBoardInputAPI(std::string StringExpressionInput)
    {
        MainExpression.TreeComputationInputAPI(StringExpressionInput);
        CustomTokenUnit ArgumentNameToGetInput = MainExpression.OutputArgumentNameList();
        for (unsigned int i = 0; i < ArgumentNameToGetInput.size(); ++i)
        {
            InputProcessor.push_back(GetInputArgumentExpression(ArgumentNameToGetInput[i]));
        }
    }
    /**
     * @brief It builds a built-in data type consisting of a string and an ExpressionStringObject,
     * @brief to store argument-expression getting from keyboard, then it builds a sub expression tree
     * @param ArgumentNameToGet
     * @return InputExpressionUnit
     */
    InputExpressionUnit CompleteComputation::GetInputArgumentExpression(std::string ArgumentNameToGet)
    {
        std::string InputScanner = "";
        InputExpressionUnit InputNameFromKeyBoardBuilder;
        std::cout << "Enter values for variables " << ArgumentNameToGet << ": " << std::endl;
        std::getline(std::cin, InputScanner);
        if (IsValidExpression(InputScanner) == false)
            throw std::runtime_error("Invalid expression!");
        TreeComputation ArgumentInputObject;
        ArgumentInputObject.TreeComputationInputAPI(ArgumentNameToGet);
        InputNameFromKeyBoardBuilder(ArgumentNameToGet, ArgumentInputObject);
        return InputNameFromKeyBoardBuilder;
    }

}

#endif