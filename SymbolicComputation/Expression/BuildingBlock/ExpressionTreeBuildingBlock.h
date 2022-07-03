/**
 * @file ExpressionTreeBuildingBlock.h is header file for expression tree data structures
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief This file contains building block for expression tree and derivative expression tree
 * @version 2.0
 * @date 2022-06-30
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_TREE_NODE_H
#define EXPRESSION_TREE_NODE_H

#include <string>
#include <cstring>
#include <iostream>

/**
 * @brief This file contains building block to build expression tree
 * @brief We use binary tree to store expression tree information
 */
struct TreeExpressionBuildingBlock
{
    std::string Data = "";
    struct TreeExpressionBuildingBlock *Left = NULL;
    struct TreeExpressionBuildingBlock *Right = NULL;
};
typedef TreeExpressionBuildingBlock TreeExpressionBuildingBlock;

// Initialization tree expression building block
TreeExpressionBuildingBlock *CreateExpressionTreeBuildingBlock(std::string Data)
{
    TreeExpressionBuildingBlock *ExpressionTreeBuilder = new TreeExpressionBuildingBlock;
    ExpressionTreeBuilder->Data = Data;
    return ExpressionTreeBuilder;
}

/**
 * @brief CloneExpressionTree is method to copy a tree to another tree
 * @param Root is the expression tree to be copied
 * @return TreeExpressionBuildingBlock*
 */
TreeExpressionBuildingBlock *CloneExpressionTree(TreeExpressionBuildingBlock *Root)
{
    if (Root == NULL)
        return Root;
    else
    {
        TreeExpressionBuildingBlock *ExpressionTreeBuilder = new TreeExpressionBuildingBlock;
        ExpressionTreeBuilder->Data = Root->Data;
        ExpressionTreeBuilder->Left = CloneExpressionTree(Root->Left);
        ExpressionTreeBuilder->Right = CloneExpressionTree(Root->Right);
        return ExpressionTreeBuilder;
    }
}

/**
 * @brief FindSKeyExistence find whether a key exists in give expression tree
 * @param Root is the given expression tree to check
 * @param KeyToFind is the string to find existence
 * @return true
 * */
bool FindIfKeyExistence(TreeExpressionBuildingBlock *Root, std::string KeyToFind)
{
    bool Checker = false;
    if (Root == NULL)
        return false;
    if (Root->Data == KeyToFind)
        return true;
    Checker = FindIfKeyExistence(Root->Left, KeyToFind);
    if (Checker == true)
        return true;
    Checker = FindIfKeyExistence(Root->Right, KeyToFind);
    if (Checker == true)
        return true;
    return Checker;
}

#endif
