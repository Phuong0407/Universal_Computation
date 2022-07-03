/**
 * @file ExpressionCustomTokenDecomposition.h is header file in order to manage expression in CustomTokenUnit
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief Header file derives from ExpressionStringDecomposition.h
 * @brief Provides methods to decompose expression input
 * @version 2.0
 * @date 2022-06-30
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef PROCESS_EXPRESSION_DECOMPOSITION_TOKEN_UNIT_H
#define PROCESS_EXPRESSION_DECOMPOSITION_TOKEN_UNIT_H

#include "ExpressionStringDecomposition.h"
#include "ExpressionCustomTokenDecompositionAuxiliaryMethod.h"

/**
 * @brief ExpressionManagement namespace control all the operations related to expression exploitation
 */
namespace ExpressionManagement
{
    /**
     * @brief Protected inheritance from ExpressionStringDecomposition
     * @brief Main unit to exploit expression calculation in future
     * @brief Two methods DecompositionToInfixCustomToken() and InfixToPostfixConversion() is the mains method of this class
     * @brief OperandsList is the list of operands name, we will filter it later to create list of variables
     * @brief All other protected class serve as auxiliary method
     */
    class ExpressionCustomTokenDecomposition : public ExpressionStringDecomposition
    {
    private:
        std::vector<std::string> OperandsList;
        CustomTokenUnit InfixDecompositionCustomToken;
        CustomTokenUnit PostfixDecompositionCustomToken;

        CustomTokenUnit InfixToPostfixConversion(CustomTokenUnit);
        CustomTokenUnit DecompositionToInfixCustomToken(std::string);
        void CreateOperandsList();

    protected:
        void DecompositionToInfixCustomTokenInitialization(std::string);

    public:
        CustomTokenUnit OutputInfixDecompositionCustomToken();
        CustomTokenUnit OutputPostfixDecompositionCustomToken();
        std::vector<std::string> OutputOperandsList();
    };
}
#endif