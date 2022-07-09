/**
 * @file ExpressionDecomposition.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_DECOMPOSITION_H
#define EXPRESSION_DECOMPOSITION_H

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "../ProcessingMethod/ProcessingMainMethodAPI.cpp"

/**
 * @brief Namespace ExpressionManagement contains all manipulations relating to expression processing
 */
namespace ExpressionManagement
{
    /**
     * @brief class ExpressionDecomposition is the base class for all symbolic computation
     * @brief API: ExpressionDecompositionInputAPI() is the input API
     * @brief API: OutputExpressionCustomTokenInfix() outputs infix expression
     * @brief API: OutputExpressionNoBlank() outputs expression without space
     * @brief API: OutputArgumentNameList() outputs argument names list
     */
    class ExpressionDecomposition
    {
    private:
        std::string ExpressionInputNoBlank;          // Main storage unit for expression string
        CustomTokenUnit ExpressionCustomTokenInfix;  // Main storage unit for infix form of expression 
        CustomTokenUnit ArgumentNameList;            // Contains all argument names of expression string

    public:
        void ExpressionDecompositionInputAPI(std::string);
        std::string OutputExpressionNoBlank();
        CustomTokenUnit OutputArgumentNameList();
        CustomTokenUnit OutputExpressionCustomTokenInfix();
    };
    typedef class ExpressionDecomposition ExpressionDecomposition;

    /**
     * @brief remove space and unary operators, using DecompositionToInfixCustomToken() to decompose expression to CustomTokenUnit,
     * and creates an argument name list
     * @param ExpressionStringInput
     */
    void ExpressionDecomposition::ExpressionDecompositionInputAPI(std::string ExpressionStringInput)
    {
        do
        {
            ExpressionStringInput.erase(remove(ExpressionStringInput.begin(), ExpressionStringInput.end(), ' '), ExpressionStringInput.end());
        } while (ExpressionStringInput.find(' ') == ExpressionStringInput.length());
        if (ExpressionStringInput == this->OutputExpressionNoBlank())
            return;
        ExpressionInputNoBlank = RemoveUnaryOperator(ExpressionStringInput);
        ExpressionCustomTokenInfix = DecompositionToInfixCustomToken(this->OutputExpressionNoBlank());
        ArgumentNameList = CreateArgumentNameList(ExpressionCustomTokenInfix);
    }

    /**
     * @brief Outputs expression string without any blanks
     * @return std::string as string expression
     */
    std::string ExpressionDecomposition::OutputExpressionNoBlank()
    {
        return this->ExpressionInputNoBlank;
    }

    /**
     * @brief Outputs infix expression in CustomTokenUnit 
     * @return CustomTokenUnit
     */
    CustomTokenUnit ExpressionDecomposition::OutputExpressionCustomTokenInfix()
    {
        return this->ExpressionCustomTokenInfix;
    }

    /**
     * @brief Outputs argument names list
     * @return CustomTokenUnit 
     */
    CustomTokenUnit ExpressionDecomposition::OutputArgumentNameList()
    {
        return this->ArgumentNameList;
    }
}

#endif