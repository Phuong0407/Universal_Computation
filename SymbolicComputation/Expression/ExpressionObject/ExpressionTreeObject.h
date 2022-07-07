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
        CustomTokenUnit ArgumentNameList;
        TreeExpressionBuildingBlock *ExpressionTreeRoot = NULL;

    protected:
    public:
        void CreateArgumentName();
        void CreateArgumentNameTree(TreeExpressionBuildingBlock *);
        void OutputExpressionTreeInOrderTraversal();
        void OutputExpressionTreePreOrderTraversal();
        void OutputExpressionTreePostOrderTraversal();
        void TreeExpressionObjectInputAPI(std::string);
        void InputArgumentReplacer(std::string, TreeExpressionBuildingBlock *);
        CustomTokenUnit OutputArgumentNameList();
        TreeExpressionBuildingBlock *OutputExpressionTreeRoot();
    };
    typedef class ExpressionTreeObject ExpressionTreeObject;

    /**
     * @brief This function will get string input to create an expression tree,
     * @brief from that it will create expression tree,
     * @brief then it will create argument name list
     * @param ExpressionInput string to get
     */
    void ExpressionTreeObject::TreeExpressionObjectInputAPI(std::string ExpressionInput)
    {
        this->ExpressionCustomTokenInputAPI(ExpressionInput);
        this->ExpressionTreeRoot = BuildExpressionTree(this->OutputExpressionCustomTokenPostfix());
        this->CreateArgumentName();
    }
    /**
     * @brief This function will create a CustomTokenUnit,
     * @brief It creates and stores argument name to get value later
     */
    void ExpressionTreeObject::CreateArgumentName()
    {
        std::string ArgumentNameBuilder = "";
        CustomTokenUnit OperandsList = this->OutputExpressionCustomTokenInfix();
        if (OperandsList.empty() == true)
            throw std::invalid_argument("Wrong in algorithm or invalid expression!");
        for (unsigned int i = 0; i < OperandsList.size(); ++i)
        {
            if (IsArgument(OperandsList[i]) == true)
            {
                ArgumentNameBuilder = OperandsList[i];
                ArgumentNameList.push_back(ArgumentNameBuilder);
            }
        }
    }

    void ExpressionTreeObject::CreateArgumentNameTree(BuildExpressionTree *ExpressionTreeRoot)
    {
        if (ExpressionTreeRoot == NULL)
            return;
    }

    void ExpressionTreeObject::InputArgumentReplacer(std::string ArgumentName, BuildExpressionTree *SubTree)
    {
        ExpressionTreeRoot = SubTreeReplacement(ExpressionTreeRoot, ArgumentName, SubTree);
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
    TreeExpressionBuildingBlock *ExpressionTreeObject::OutputExpressionTreeRoot()
    {
        return this->ExpressionTreeRoot;
    }
    CustomTokenUnit *ExpressionTreeObject::OutputArgumentNameList()
    {
        return this->ArgumentNameList;
    }
}

#endif