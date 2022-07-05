/**
 * @file ExpressionTreeStorage.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-05
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef EXPRESSION_TREE_STORAGE_H
#define EXPRESSION_TREE_STORAGE_H

#include "../../ProcessExpressionPlain/ProcessExpressionPlainAPI.cpp"

namespace ExpressionManagement
{
    class ExpressionTreeStorage : public ExpressionTokenCustomStorage
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
    typedef class ExpressionTreeStorage ExpressionTreeStorage;
}

#endif