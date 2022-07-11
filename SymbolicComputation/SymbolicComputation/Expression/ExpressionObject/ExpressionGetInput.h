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
     * @brief API: gets input string, decomposes to infix expression and output postfix expression without any arguments.
     */
    class ExpressionGetInput
    {
    private:
        ExpressionDecomposition MainExpression;                               // storage unit to be expresion that without any changes as initial input
        CustomTokenUnit MainExpresionInfix;                                   // expression without any argument, will be convert later to postfix expression
        CustomTokenUnit InputArgumentNameTotal;                               // stores all argument name (get from outside) to put to main expression
        std::vector<ArgumentSubExpressionInputUnit> InputSubExpressionTriple; // stores data for input argument, serving as a unit for recursive input request

        void CreateArgumentNameTotal();
        bool IsContainingArgument();
        ArgumentSubExpressionInputUnit ProcessArgumentSubExpression(std::string, std::string);

    public:
        void GetInputMainExpressionAPI(std::string);
        CustomTokenUnit OutputMainExpresionInfix();
    };
    typedef class ExpressionGetInput ExpressionGetInput;

    /**
     * @brief Decomposes subexpression to infix vector and a sublist of argument name
     * @param ArgumentName the argument name to get
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
     * @brief it initializes main expression, gets subexpression, creates list of sub arguments until getting subexpression without arguments
     * @param ExpressionStringInput the expression to compute
     */
    void ExpressionGetInput::GetInputMainExpressionAPI(std::string ExpressionStringInput)
    {
        MainExpression.ExpressionDecompositionInputAPI(ExpressionStringInput);
        MainExpresionInfix = MainExpression.OutputExpressionCustomTokenInfix();
        InputArgumentNameTotal = MainExpression.OutputArgumentNameList();
        std::cout <<"For expression "<< MainExpression.OutputExpressionNoBlank() <<std::endl;
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
     * @brief checks whether InputArgumentNameTotal containing argument or not
     * @return true if InputArgumentNameTotal contains argument(s)
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
     * @brief Creates a list of total argument list from input subexpression
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

    /**
     * @return CustomTokenUnit as infix expression without any arguments
     */
    CustomTokenUnit ExpressionGetInput::OutputMainExpresionInfix()
    {
        return this->MainExpresionInfix;
    }
}

#endif