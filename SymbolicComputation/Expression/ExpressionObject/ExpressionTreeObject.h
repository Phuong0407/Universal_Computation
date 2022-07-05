/**
 * @file ExpressionTreeObject.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-05
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef EXPRESSION_TREE_OBJECT_H
#define EXPRESSION_TREE_OBJECT_H

#include "ExpressionCustomTokenObject.h"

namespace ExpressionManagement
{
    class ExpressionTreeObject : public ExpressionCustomTokenObject
    {
    private:
        TreeExpressionBuildingBlock *ExpressionTreeRoot = NULL;

    protected:
    public:
        void TreeExpressionStorageInputAPI(std::string);
        void OutputExpressionTreeInOrderTraversal();
        void OutputExpressionTreePreOrderTraversal();
        void OutputExpressionTreePostOrderTraversal();
    };
    typedef class ExpressionTreeObject ExpressionTreeObject;

    void ExpressionTreeObject::TreeExpressionStorageInputAPI(std::string ExpressionInput)
    {
        this->ExpressionCustomTokenInputAPI(ExpressionInput);
        // this->ExpressionTreeRoot = new TreeExpressionBuildingBlock;
        this->ExpressionTreeRoot = BuildExpressionTree(this->OutputExpressionCustomTokenPostfix());
    }
    void ExpressionTreeObject::OutputExpressionTreeInOrderTraversal()
    {
        InOrderTraversal(this->ExpressionTreeRoot);
    }
    void ExpressionTreeObject::OutputExpressionTreePreOrderTraversal()
    {
        PreOrderTraversal(this->ExpressionTreeRoot);
    }
    void ExpressionTreeObject::OutputExpressionTreePostOrderTraversal()
    {
        PostOrderTraversal(this->ExpressionTreeRoot);
    }
}

#endif