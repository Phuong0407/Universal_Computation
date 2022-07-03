/**
 * @file ExpressionManagement.h is header file in order to manage expression in string
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief Header file derives from ExpressionBuildingBlock.h
 * @brief Provides methods to decompose expression input
 * @brief Expression input provided as a no blank string
 * @version 2.0
 * @date 2022-06-29
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef PROCESS_EXPRESSION_DECOMPOSITION_H
#define PROCESS_EXPRESSION_DECOMPOSITION_H

#include "ExpressionBuildingBlock.h"

/**
 * @brief ExpressionManagement namespace control all the operations related to expression exploitation
 * @brief It contains class ExpressionStringDecomposition
 */
namespace ExpressionManagement
{
    /**
     * @brief ExpressionStringDecomposition process primary operations such as transform unary operations and remove blank characters
     * @brief ExpressionInput will be the initial input from keyboard or other source (develop later) without any process
     * @brief ExpressionInputNoBlank contains input after removing space
     * @brief ExpressionStringDecomposition method assign input string and remove all space
     * @brief RemoveUnaryOperator removes only two unary operators '+' and '-' in case of positive number, for instance +3/4 or negative number after parentheses like (-3 + 4)
     * @brief Two output methods for private data protected in derive classes
     */
    class ExpressionStringDecomposition
    {
    private:
        std::string ExpressionInputInitial;
        std::string ExpressionInputNoBlank;

        void RemoveUnaryOperator();

    public:
        std::string OutputExpressionInitial();
        std::string OutputExpressionNoBlank();
        void ExpressionStringDecompositionInitialization(std::string);
    };
}

#endif
