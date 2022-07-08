/**
 * @file ExpressionGetInput.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-07
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_GET_INPUT_H
#define EXPRESSION_GET_INPUT_H

#include "ExpressionDecomposition.h"

namespace ExpressionManagement
{
    // Data structures to store unit of a subexpression(argument name, argument infix vector, sub argument list)
    typedef std::tuple<std::string, CustomTokenUnit, CustomTokenUnit> ArgumentSubExpressionInputUnit;

    /**
     * @brief This class provides an API:
     * @brief StringExpressionInput is the expression to compute,
     * @brief vector of pair (name, sub expression tree) to compute
     * @brief
     */
    class ExpressionGetInput
    {
    private:
        CustomTokenUnit MainExpresionInfix;                                   // expression without any argument, will be convert later to postfix expression
        CustomTokenUnit InputArgumentNameTotal;                               // stores all argument name (get from outside) to put to main expression, it will be processed to be null
        ExpressionDecomposition MainExpression;                               // storage unit to be expresion that without any changes as initial input
        std::vector<ArgumentSubExpressionInputUnit> InputSubExpressionTriple; // data structure to store a pair of (name, sub expression tree)

        void CreateArgumentNameTotal();
        bool IsContainingArgument();
        ArgumentSubExpressionInputUnit ProcessArgumentSubExpression(std::string, std::string);

    public:
        void GetInputMainExpressionAPI(std::string);
        CustomTokenUnit OutputMainExpresionInfix();
    };
    typedef class ExpressionGetInput ExpressionGetInput;

    /**
     * @brief GetInputArgumentSubExpression() uses name from initial argument list.
     * @brief it decomposes this subexpression to infix vector and a sublist of argument name,
     * @brief then it creates a pair of (name, ExpressionDecomposition object)
     * @param ArgumentName the argument name to get.
     * @param SubExpression the input expression to replace argument name
     * @return ArgumentSubExpressionInputUnit as a builder for ArgumentInputUnit
     */
    ArgumentSubExpressionInputUnit ExpressionGetInput::ProcessArgumentSubExpression(std::string ArgumentName, std::string SubExpression)
    {
        ExpressionDecomposition ArgumentInputObject;
        ArgumentSubExpressionInputUnit InputNameFromKeyBoardBuilder;
        if (IsValidExpression(SubExpression) == false)
            throw std::runtime_error("Invalid expression!");
        ArgumentInputObject.ExpressionDecompositionInputAPI(SubExpression);
        InputNameFromKeyBoardBuilder = std::make_tuple(ArgumentName, ArgumentInputObject.OutputExpressionCustomTokenInfix(), ArgumentInputObject.OutputArgumentNameList());
        return InputNameFromKeyBoardBuilder;
    }

    /**
     * @brief GetInputMainExpressionAPI() is the input API to communicate with class ExpressionGetInput.
     * @brief first, it initialize main expression (remove space, decomposed and get argument name list).
     * @brief Second, from argument name list, it gets subexpression from keyboard and processes it as to MainExpression
     * @param ExpressionStringInput the expression to compute
     */
    void ExpressionGetInput::GetInputMainExpressionAPI(std::string ExpressionStringInput)
    {
        MainExpression.ExpressionDecompositionInputAPI(ExpressionStringInput);
        MainExpresionInfix = MainExpression.OutputExpressionCustomTokenInfix();
        InputArgumentNameTotal = MainExpression.OutputArgumentNameList();
        for (unsigned int i = 0; i < InputArgumentNameTotal.size(); ++i)
            std::cout << InputArgumentNameTotal[i] << std::endl;
        while (InputArgumentNameTotal.empty() != true)
        {
            std::vector<ArgumentSubExpressionInputUnit> InputSubExpressionTripleBuilder;
            ArgumentStringUnit SubExpressionScanner;
            for (unsigned int i = 0; i < InputArgumentNameTotal.size(); i++)
            {
                SubExpressionScanner = GetInputFromKeyBoard(InputArgumentNameTotal[i]);
                InputSubExpressionTripleBuilder.push_back(ProcessArgumentSubExpression(SubExpressionScanner.first, SubExpressionScanner.second));
                VectorReplacer(MainExpresionInfix, std::get<0>(InputSubExpressionTripleBuilder[i]), std::get<1>(InputSubExpressionTripleBuilder[i]));
            }
            InputSubExpressionTriple = InputSubExpressionTripleBuilder;
            CreateArgumentNameTotal();
        }
        return;
    }

    /**
     * @brief IsContainingArgument() checks whether InputArgumentNameTotal containing argument or not
     * @return true
     */
    bool ExpressionGetInput::IsContainingArgument()
    {
        for (unsigned int i = 0; i < InputArgumentNameTotal.size(); ++i)
        {
            if (IsArgument(InputArgumentNameTotal[i]) == false)
                continue;
            else
                return true;
        }
        return false;
    }

    /**
     * @brief CreateArgumentNameTotal() will create a list of total argument list from input subexpression
     */
    void ExpressionGetInput::CreateArgumentNameTotal()
    {
        CustomTokenUnit InputArgumentBuilder, InputArgumentScanner;
        for (unsigned int i = 0; i < InputSubExpressionTriple.size(); ++i)
        {
            InputArgumentScanner = std::get<2>(InputSubExpressionTriple[i]);
            InputArgumentBuilder.insert(InputArgumentBuilder.end(), InputArgumentScanner.begin(), InputArgumentScanner.end());
        }
        InputArgumentNameTotal = InputArgumentBuilder;
        InputArgumentNameTotal = RemoveIdenticalElement(InputArgumentNameTotal);
    }

    CustomTokenUnit ExpressionGetInput::OutputMainExpresionInfix()
    {
        return this->MainExpresionInfix;
    }
}

#endif