/**
 * @file Decomposition.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef DECOMPOSITION_TO_INFIX_H
#define DECOMPOSITION_TO_INFIX_H

#include "../../ExpressionString/ExpressionStringStorage.h"
#include "../../ExpressionString/ExpressionStringStorage.cpp"
#include "../AuxiliaryMethod/DecompositionAuxiliaryMethodAPI.cpp"

namespace ExpressionManagement
{
    /**
     * @brief Decomposition is class to decompose string expression to CustomTokenUnit
     * @brief We give two output API, one input API and decompose expression to infix expression
     */
    class DecompositionToInfix : public ExpressionStringStorage
    {
    private:
        // std::vector<std::string> OperandsList;

        CustomTokenUnit DecompositionToInfixCustomToken(std::string);
        // CustomTokenUnit InfixToPostfixConversion(CustomTokenUnit);
        // void CreateOperandsList();

    protected:
    public:
        CustomTokenUnit InfixExpressionCustomToken;
        void DecompositionToInfixInputAPI(std::string);
        CustomTokenUnit DecompositionToInfixOutputAPI();
        // std::vector<std::string> OutputOperandsList();
    };
    typedef class DecompositionToInfix DecompositionToInfix;
}
#endif