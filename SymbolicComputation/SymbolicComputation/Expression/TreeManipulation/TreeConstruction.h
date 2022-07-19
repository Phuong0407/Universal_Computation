/**
 * @file TreeConstruction.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-15
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef TREE_CONSTRUCTION_H
#define TREE_CONSTRUCTION_H

#include "../PostfixConversionMethod/PInfixToPostfixConversion.h"

namespace Expression
{
    struct TreeNode
    {
        CustomToken Data;
        struct TreeNode *Left = NULL;
        struct TreeNode *Right = NULL;
        explicit TreeNode(CustomToken InputData) { Data = InputData; }
        explicit TreeNode() {}
    };
    typedef struct TreeNode TreeNode;

    class TreeConstruction
    {
    private:
        static std::string getFunctionNotation(std::string &Input)
        {
            char InputStringScanner;
            std::string FunctionNotation = "";
            for (unsigned int i = 0; i < Input.length(); ++i)
            {
                InputStringScanner = StringToInfixConversion::extractFirstCharacter(Input);
                if (InputStringScanner == '[')
                    break;
                FunctionNotation += InputStringScanner;
                StringToInfixConversion::extractFirstCharacter(Input, 1);
            }
            return FunctionNotation;
        }

    public:
        static TreeNode *constructTreeExpression(CustomTokenExpression PostfixInput)
        {
            TreeNode *ExpressionTreeRoot = NULL;
            std::stack<TreeNode *> ExpressionTreeStack;
            for (std::size_t i = 0; i < PostfixInput.size(); ++i)
            {
                if (PostfixInput[i].first >= PowerOperatorID && PostfixInput[i].first <= AddSubOperatorID)
                {
                    ExpressionTreeRoot = new TreeNode(PostfixInput[i]);
                    TreeNode *RightSubTreeExpression = ExpressionTreeStack.top();
                    ExpressionTreeStack.pop();
                    TreeNode *LeftSubTreeExpression = ExpressionTreeStack.top();
                    ExpressionTreeStack.pop();
                    ExpressionTreeRoot->Right = RightSubTreeExpression;
                    ExpressionTreeRoot->Left = LeftSubTreeExpression;
                    ExpressionTreeStack.push(ExpressionTreeRoot);
                }
                else if (PostfixInput[i].first >= FunctionID && PostfixInput[i].first <= ParaOptFunctionID)
                {
                    if (PostfixInput[i].first == ParaOptFunctionID)
                    {
                        std::string PostfixInputTemp = PostfixInput[i].second;
                        std::string FunctionNoBrackets = getFunctionNotation(PostfixInputTemp);
                        ExpressionTreeRoot = new TreeNode(CustomTokenUnitIDCreation::createExpressionUnitID(FunctionNoBrackets));
                        CustomTokenExpression LeftSubPostfix = InfixToPostfixConversion::convertStringToPostfix(PostfixInputTemp);
                        TreeNode *LeftSubTreeExpression = constructTreeExpression(LeftSubPostfix);
                        ExpressionTreeRoot->Left = LeftSubTreeExpression;
                        TreeNode *RightSubTreeExpression = ExpressionTreeStack.top();
                        ExpressionTreeStack.pop();
                        ExpressionTreeRoot->Right = RightSubTreeExpression;
                        ExpressionTreeStack.push(ExpressionTreeRoot);
                    }
                    else
                    {
                        ExpressionTreeRoot = new TreeNode(PostfixInput[i]);
                        TreeNode *RightSubTreeExpression = ExpressionTreeStack.top();
                        ExpressionTreeStack.pop();
                        ExpressionTreeRoot->Right = RightSubTreeExpression;
                        ExpressionTreeStack.push(ExpressionTreeRoot);
                    }
                }
                else
                {
                    ExpressionTreeRoot = new TreeNode(PostfixInput[i]);
                    ExpressionTreeStack.push(ExpressionTreeRoot);
                }
            }
            ExpressionTreeRoot = ExpressionTreeStack.top();
            ExpressionTreeStack.pop();
            if (ExpressionTreeStack.empty() == false)
                throw std::runtime_error("Stack is not empty after building expression tree, wrong algorithms, please check the file TreeConstruction.cpp.");
            return ExpressionTreeRoot;
        }

        static TreeNode *convertStringTreeExpression(std::string InputExpression)
        {
            CustomTokenExpression PostfixExpression = InfixToPostfixConversion::convertStringToPostfix(InputExpression);
            TreeNode *Root = TreeConstruction::constructTreeExpression(PostfixExpression);
            return Root;
        }

        // Use to debug
        static void InOrderTraversal(TreeNode *Root)
        {
            if (Root == NULL)
                return;
            InOrderTraversal(Root->Left);
            std::cout << Root->Data.second;
            InOrderTraversal(Root->Right);
        }
        // Use to debug
        static void PreOrderTraversal(TreeNode *Root)
        {
            if (Root == NULL)
                return;
            std::cout << Root->Data.second;
            PreOrderTraversal(Root->Left);
            PreOrderTraversal(Root->Right);
        }
        // Use to debug
        static void PostOrderTraversal(TreeNode *Root)
        {
            if (Root == NULL)
                return;
            PostOrderTraversal(Root->Left);
            PostOrderTraversal(Root->Right);
            std::cout << Root->Data.second;
        }
    };
    typedef class TreeConstruction TreeConstruction;
}

#endif
// using namespace std;
// using namespace Expression;

// int main()
// {
//     std::string s = "cos[rad](x-4)*sinh(tan(y)+12.213213213)-fineStruct^2+log[pi](a)";
//     CustomTokenExpression a = StringToInfixConversion::decomposeStringToInfix(s);
//     // for (unsigned int i = 0; i < a.size(); i++)
//     //     cout << a[i].second;
//     CustomTokenExpression b = InfixToPostfixConversion::convertInfixToPostfix(a);
//     TreeNode *root = TreeConstruction::constructTreeExpression(b);
//     TreeConstruction::InOrderTraversal(root);
// }