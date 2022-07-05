/**
 * @file ExpressionTreeBuildingBlock.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_TREE_BUILDING_BLOCK_H
#define EXPRESSION_TREE_BUILDING_BLOCK_H

#include <string>
#include <cstring>
#include <iostream>

// struct pointer initialized to NULL, do not initialize again
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
 * @brief CloneExpressionTree copies a tree to another tree
 * @param Root is the expression tree to be copied
 * @return TreeExpressionBuildingBlock* pointer
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
 * @brief FindKeyExistence find whether a key exists in give expression tree
 * @param Root is the given expression tree to check
 * @param KeyToFind is the string to check existence
 * @return true
 */
bool CheckIfKeyExistence(TreeExpressionBuildingBlock *Root, std::string KeyToFind)
{
    bool Checker = false;
    if (Root == NULL)
        return false;
    if (Root->Data == KeyToFind)
        return true;
    Checker = CheckIfKeyExistence(Root->Left, KeyToFind);
    if (Checker == true)
        return true;
    Checker = CheckIfKeyExistence(Root->Right, KeyToFind);
    if (Checker == true)
        return true;
    return Checker;
}

void InOrderTraversal(TreeExpressionBuildingBlock *Root)
{
    InOrderTraversal(Root->Left);
    std::cout << Root->Data << std::endl;
    InOrderTraversal(Root->Right);
}

void PreOrderTraversal(TreeExpressionBuildingBlock *Root)
{
    std::cout << Root->Data << std::endl;
    PreOrderTraversal(Root->Left);
    PreOrderTraversal(Root->Right);
}

void PostOrderTraversal(TreeExpressionBuildingBlock *Root)
{
    PostOrderTraversal(Root->Left);
    PostOrderTraversal(Root->Right);
    std::cout << Root->Data << std::endl;
}

#endif
