/**
 * @file ExpressionTreeConstruct.h is used for construct an expression tree from postfix expression string
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief This help construct an expression tree, derives from ExpressionTreeBuildingBlock.h
 * @version 2.0
 * @date 2022-06-30
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_TREE_CONSTRUCTION_H
#define EXPRESSION_TREE_CONSTRUCTION_H

#include "../../BuildingBlock/ExpressionTreeBuildingBlock.h"
#include "../../ProcessExpressionPlain/ExpressionCustomToken/ExpressionTokenCustomStorage.cpp"

/**
 * @brief ExpressionManagement namespace control all the operations related to expression exploitation
 */
namespace ExpressionManagement
{
    /**
     * @brief Class TreeExpressionConstruction derives protected from class ExpressionCustomTokenDecomposition
     * @brief This contains only one class, TreeExpressionConstruction
     * @brief This will build an expression tree from postfix expression
     * @brief Derives from class ExpressionCustomTokenDecomposition
     * @brief Can be developed in future
     */
    TreeExpressionBuildingBlock *BuildExpressionTree(CustomTokenUnit);
}
#endif

int main()
{
}