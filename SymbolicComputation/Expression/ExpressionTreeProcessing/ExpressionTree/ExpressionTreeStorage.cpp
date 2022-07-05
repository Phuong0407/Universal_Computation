/**
 * @file ExpressionTreeStorage.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-05
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef EXPRESSION_TREE_STORAGE_CPP
#define EXPRESSION_TREE_STORAGE_CPP

#include "ExpressionTreeStorage.h"

namespace ExpressionManagement
{
    void ExpressionTreeStorage::TreeExpressionStorageInputAPI(std::string ExpressionStringInput)
    {
        this->ExpressionCustomTokenInputAPI(ExpressionStringInput);
        this->ExpressionTreeRoot = BuildExpressionTree(this->OutputExpressionCustomTokenPostfix());
    }

    void ExpressionTreeStorage::OutputExpressionTreeInOrderTraversal()
    {
        InOrder(this->ExpressionTreeRoot);
    }
    void ExpressionTreeStorage::OutputExpressionTreePreOrderTraversal()
    {
        PreOrder(this->ExpressionTreeRoot);
    }
    void ExpressionTreeStorage::OutputExpressionTreePostOrderTraversal()
    {
        PostOrder(this->ExpressionTreeRoot);
    }
}

#endif

// int main()
// {
// }