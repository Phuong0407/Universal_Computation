/**
 * @file ExpressionTreeConstruction.cpp is implementation file for ExpressionTreeConstruction.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief We define here two necessary method to build and communicate with other object
 * @version 2.0
 * @date 2022-06-30
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_TREE_CONSTRUCTION_CPP
#define EXPRESSION_TREE_CONSTRUCTION_CPP

#include <stack>
#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "../BuildingBlock/ExpressionTreeBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief Recursively builds expression tree from postfix expression
     * Using exception handling to check if construction is fail or not
     */
    TreeExpressionBuildingBlock *BuildExpressionTree(CustomTokenUnit PostfixExpressionCustomTokenUnit)
    {
        std::stack<TreeExpressionBuildingBlock *> ExpressionTreeStack;
        TreeExpressionBuildingBlock *ExpressionTreeRoot = NULL;
        TreeExpressionBuildingBlock *LeftSubTreeExpression = new TreeExpressionBuildingBlock;
        TreeExpressionBuildingBlock *RightSubTreeExpression = new TreeExpressionBuildingBlock;
        CustomTokenUnit PostfixExpressionBuildingUnit = PostfixExpressionCustomTokenUnit;
        for (unsigned int i = 0; i < PostfixExpressionBuildingUnit.size(); ++i)
        {
            ExpressionTreeRoot = new TreeExpressionBuildingBlock;
            if (IsOperator(PostfixExpressionBuildingUnit[i]) == true)
            {
                CreateExpressionTreeBuildingBlock(PostfixExpressionBuildingUnit[i], ExpressionTreeRoot);
                LeftSubTreeExpression = ExpressionTreeStack.top();
                ExpressionTreeStack.pop();
                RightSubTreeExpression = ExpressionTreeStack.top();
                ExpressionTreeStack.pop();
                ExpressionTreeRoot->Right = LeftSubTreeExpression;
                ExpressionTreeRoot->Left = RightSubTreeExpression;
                ExpressionTreeStack.push(ExpressionTreeRoot);
            }
            else if (IsBuiltInFunctions(PostfixExpressionBuildingUnit[i]) == true)
            {
                CreateExpressionTreeBuildingBlock(PostfixExpressionBuildingUnit[i], ExpressionTreeRoot);
                RightSubTreeExpression = ExpressionTreeStack.top();
                ExpressionTreeStack.pop();
                ExpressionTreeRoot->Right = RightSubTreeExpression;
                ExpressionTreeStack.push(ExpressionTreeRoot);
            }
            else
            {
                CreateExpressionTreeBuildingBlock(PostfixExpressionBuildingUnit[i], ExpressionTreeRoot);
                ExpressionTreeStack.push(ExpressionTreeRoot);
            }
            delete ExpressionTreeRoot;
        }
        ExpressionTreeRoot = ExpressionTreeStack.top();
        ExpressionTreeStack.pop();
        if (ExpressionTreeStack.empty() == false)
            throw std::runtime_error("Stack is not empty after building expression tree, wrong algorithms, please check the file ExpressionTreeConstruction.cpp.");
        return ExpressionTreeRoot;
    }
}
#endif