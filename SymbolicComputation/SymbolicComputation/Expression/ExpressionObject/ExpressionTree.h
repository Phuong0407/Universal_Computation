/**
 * @file ExpressionTree.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-05
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include "ExpressionConversionToPostfix.h"

namespace ExpressionManagement
{
    /**
     * @brief class ExpressionTree inherit from ExpressionConversionToPostfix,
     * @brief It will get expression input, and build a tree for further calculation,
     * @brief contains a tree in TreeExpressionBuildingBlock (defined-data structure)
     * @brief API: TreeExpressionInputAPI() get input string to build tree.
     * @brief API: Three kinds of output, printing tree (InOrder, PreOrder, PostOrder) to debug code!
     * @brief API: OutputExpressionTreeRoot() outputs tree root for further calculation.
     */
    class ExpressionTree : public ExpressionConversionToPostfix
    {
    private:
        TreeExpressionBuildingBlock *ExpressionTreeRoot = NULL;

    public:
        void TreeExpressionInputAPI(std::string);
        void OutputExpressionTreeInOrderTraversal();
        void OutputExpressionTreePreOrderTraversal();
        void OutputExpressionTreePostOrderTraversal();
        TreeExpressionBuildingBlock *OutputExpressionTreeRoot();
    };
    typedef class ExpressionTree ExpressionTree;

    /**
     * @brief Gets string input to create an expression tree
     * @param StringExpressionInput string to get
     */
    void ExpressionTree::TreeExpressionInputAPI(std::string StringExpressionInput)
    {
        this->ExpressionConversionToPostfixInputAPI(StringExpressionInput);
        this->ExpressionTreeRoot = BuildExpressionTree(this->OutputPostfixExpression());
    }

    /**
     * @brief Outputs tree structure for debugging purposes
     */
    void ExpressionTree::OutputExpressionTreeInOrderTraversal()
    {
        InOrderTraversal(this->ExpressionTreeRoot);
    }

    /**
     * @brief Outputs tree structure for debugging purposes
     */
    void ExpressionTree::OutputExpressionTreePreOrderTraversal()
    {
        PreOrderTraversal(this->ExpressionTreeRoot);
    }

    /**
     * @brief Outputs tree structure for debugging purposes
     */
    void ExpressionTree::OutputExpressionTreePostOrderTraversal()
    {
        PostOrderTraversal(this->ExpressionTreeRoot);
    }

    /**
     * @brief Outputs tree root for further calculation
     * @return TreeExpressionBuildingBlock* as expression tree
     */
    TreeExpressionBuildingBlock *ExpressionTree::OutputExpressionTreeRoot()
    {
        return this->ExpressionTreeRoot;
    }
}
#endif