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
    class ExpressionTree : public ExpressionConversionToPostfix
    {
    private:
        TreeExpressionBuildingBlock *ExpressionTreeRoot = NULL;

    protected:
    public:
        void TreeExpressionInputAPI(std::string);
        void OutputExpressionTreeInOrderTraversal();
        void OutputExpressionTreePreOrderTraversal();
        void OutputExpressionTreePostOrderTraversal();
        TreeExpressionBuildingBlock *OutputExpressionTreeRoot();
    };
    typedef class ExpressionTree ExpressionTree;

    /**
     * @brief This function will get string input to create an expression tree,
     * @brief from that it will create expression tree.
     * @param ExpressionInput string to get
     */
    void ExpressionTree::TreeExpressionInputAPI(std::string ExpressionInput)
    {
        this->ExpressionConversionToPostfixInputAPI(ExpressionInput);
        this->ExpressionTreeRoot = BuildExpressionTree(this->OutputPostfixExpression());
    }

    void ExpressionTree::OutputExpressionTreeInOrderTraversal()
    {
        InOrderTraversal(this->ExpressionTreeRoot);
    }
    void ExpressionTree::OutputExpressionTreePreOrderTraversal()
    {
        PreOrderTraversal(this->ExpressionTreeRoot);
    }
    void ExpressionTree::OutputExpressionTreePostOrderTraversal()
    {
        PostOrderTraversal(this->ExpressionTreeRoot);
    }
    TreeExpressionBuildingBlock *ExpressionTree::OutputExpressionTreeRoot()
    {
        return this->ExpressionTreeRoot;
    }
}
#endif