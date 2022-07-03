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
#ifndef PROCESS_EXPRESSION_DECOMPOSITION_TOKEN_AUXILIARY_METHOD_H
#define PROCESS_EXPRESSION_DECOMPOSITION_TOKEN_AUXILIARY_METHOD_H

#include "./BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    bool IsDigit(std::string);

    bool IsOperand(char);
    
    bool IsOperator(char);
    bool IsOperator(std::string);

    bool IsConstant(std::string);

    int PriorityOrder(char);
    int PriorityOrder(std::string);

    bool IsBalance(std::string);
    bool IsBalance(CustomTokenUnit);

    bool IsBuiltInFunctions(std::string);

    std::string GetInsideParentheses(std::string);
    CustomTokenUnit GetInsideParentheses(CustomTokenUnit);
}
#endif