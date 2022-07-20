/**
 * @file ExpressionObjectStorage.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-16
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_OBJECT_STORAGE_H
#define EXPRESSION_OBJECT_STORAGE_H

#include <limits>
#include "../TreeManipulation/TreeComputation.h"

namespace Expression
{
    class ExpressionObjectStorage
    {
    public:
        std::string ExpressionString;
        CustomTokenExpression InfixExpression;
        CustomTokenExpression PostfixExpression;
        ArgumentName ArgumentNameList;
        TreeNode *TreeRoot = NULL;

        static void deleteTree(TreeNode *Root)
        {
            if (Root == NULL)
                return;
            if (Root->Left != NULL)
                deleteTree(Root->Left);
            if (Root->Right != NULL)
                deleteTree(Root->Right);
            delete Root;
        }

        static ArgumentName createArgumentNameList(TreeNode *Root, std::unordered_set<std::string> &VariableNameSet)
        {
            if (Root == NULL)
                throw std::runtime_error("No expression found!");
            std::string ArgumentNameScanner;
            ArgumentName ArgumentNameList;
            ArgumentName ArgumentNameListBuilder;
            if (Root->Left == NULL && Root->Right == NULL)
            {
                if (Root->Data.first == VariableID && VariableNameSet.find(Root->Data.second) == VariableNameSet.end())
                {
                    ArgumentNameScanner = Root->Data.second;
                    ArgumentNameList.push_back(ArgumentNameScanner);
                    VariableNameSet.insert(ArgumentNameScanner);
                }
            }
            if (Root->Left != NULL)
            {
                ArgumentNameListBuilder = createArgumentNameList(Root->Left, VariableNameSet);
                ArgumentNameList.insert(ArgumentNameList.end(), ArgumentNameListBuilder.begin(), ArgumentNameListBuilder.end());
            }
            if (Root->Right != NULL)
            {
                ArgumentNameListBuilder = createArgumentNameList(Root->Right, VariableNameSet);
                ArgumentNameList.insert(ArgumentNameList.end(), ArgumentNameListBuilder.begin(), ArgumentNameListBuilder.end());
            }
            return ArgumentNameList;
        }

        static std::string getInputArgumentKeyBoard(std::string ArgumentNameList)
        {
            std::string InputKeyBoardScanner;
            std::cout << "For variable " << ArgumentNameList << ", enter input:" << std::endl;
            std::getline(std::cin, InputKeyBoardScanner);
            return InputKeyBoardScanner;
        }

        static ArgumentName concatenateArgumentName(ArgumentName FirstInput, ArgumentName SecondInput)
        {
            ArgumentName ConcatenatedArgumentName;
            std::unordered_set<std::string> RepeatArgumentName;
            for (std::size_t i = 0; i < FirstInput.size(); ++i)
                if (RepeatArgumentName.find(FirstInput[i]) == RepeatArgumentName.end())
                {
                    ConcatenatedArgumentName.push_back(FirstInput[i]);
                    RepeatArgumentName.insert(FirstInput[i]);
                }
            for (unsigned int i = 0; i < SecondInput.size(); ++i)
                if (RepeatArgumentName.find(SecondInput[i]) == RepeatArgumentName.end())
                {
                    ConcatenatedArgumentName.push_back(SecondInput[i]);
                    RepeatArgumentName.insert(SecondInput[i]);
                }
            return ConcatenatedArgumentName;
        }

        /**
         * @brief Create value for argument, we process so that input can enter recursively.
         * This means that, you can enter another expression for input, the process will stop until the arguments do not have any argument.
         * @param ExpressionArgumentName The list of variable from an expression to get value.
         * @return ArgumentValueUnit as a list of pair (argument name, argument value)
         */
        static ArgumentValueUnit createValuedArgument(ArgumentName ExpressionArgumentName)
        {
            ArgumentName InputArgumentName;
            ArgumentName InputArgumentExpression;
            ArgumentValueUnit TempInputSubArgumentValue;
            for (std::size_t i = 0; i < ExpressionArgumentName.size(); ++i)
            {
                std::unordered_set<std::string> RepeatedArgumentChecker;
                std::string InputExpressionScanner = getInputArgumentKeyBoard(ExpressionArgumentName[i]);
                InputArgumentExpression.push_back(InputExpressionScanner);
                TreeNode *InputExpressionRoot = TreeConstruction::convertStringTreeExpression(InputExpressionScanner);
                ArgumentName InputSubArgumentName = createArgumentNameList(InputExpressionRoot, RepeatedArgumentChecker);
                InputArgumentName = concatenateArgumentName(InputArgumentName, InputSubArgumentName);
                // deleteTree(InputExpressionRoot);
            }
            if (InputArgumentName.empty() != true)
            {
                ArgumentValueUnit InputSubArgumentValue = createValuedArgument(InputArgumentName);
                ValueMap InputSubExpressionValueMap;
                for (std::size_t i = 0; i < InputArgumentName.size(); i++)
                    InputSubExpressionValueMap.insert({InputSubArgumentValue[i].first, InputSubArgumentValue[i].second});
                for (std::size_t i = 0; i < ExpressionArgumentName.size(); ++i)
                {
                    TreeNode *InputExpressionRoot = TreeConstruction::convertStringTreeExpression(InputArgumentExpression[i]);
                    double SubExpressionValue = TreeComputation::computeTreeExpression(InputExpressionRoot, InputSubExpressionValueMap);
                    ArgumentUnit TempArgumentValue = std::make_pair(ExpressionArgumentName[i], SubExpressionValue);
                    TempInputSubArgumentValue.push_back(TempArgumentValue);
                    // deleteTree(InputExpressionRoot);
                }
            }
            else if (InputArgumentName.empty() == true)
            {
                for (std::size_t i = 0; i < ExpressionArgumentName.size(); ++i)
                {
                    ValueMap InputSubExpressionValueMap;
                    TreeNode *SubExpressionRoot = TreeConstruction::convertStringTreeExpression(InputArgumentExpression[i]);
                    double SubExpressionValue = TreeComputation::computeTreeExpression(SubExpressionRoot, InputSubExpressionValueMap);
                    ArgumentUnit TempArgumentValue = std::make_pair(ExpressionArgumentName[i], SubExpressionValue);
                    TempInputSubArgumentValue.push_back(TempArgumentValue);
                    // deleteTree(SubExpressionRoot);
                }
            }
            return TempInputSubArgumentValue;
        }

    public:
        ~ExpressionObjectStorage()
        {
            if (TreeRoot != NULL)
                deleteTree(TreeRoot);
        }

        void ExpressionObjectStorageInputAPI(std::string Input)
        {
            std::unordered_set<std::string> ArgumentNameMap;
            TreeRoot = TreeConstruction::TreeConstruction::convertStringTreeExpression(Input);
            ArgumentNameList = createArgumentNameList(TreeRoot, ArgumentNameMap);
        }

        double computeExpression()
        {
            ValueMap ArgumentValueMap;
            ArgumentValueUnit ArgumentValueList = createValuedArgument(ArgumentNameList);
            for (unsigned i = 0; i < ArgumentValueList.size(); ++i)
                ArgumentValueMap.insert({ArgumentValueList[i].first, ArgumentValueList[i].second});
            return TreeComputation::computeTreeExpression(TreeRoot, ArgumentValueMap);
        }
    };
    typedef class ExpressionObjectStorage ExpressionObjectStorage;
}

#endif
using namespace std;
using namespace Expression;

int main()
{
    string s;
    std::getline(std::cin, s);
    ExpressionObjectStorage O;
    O.ExpressionObjectStorageInputAPI(s);
    ArgumentName a = O.ArgumentNameList;
    cout << O.computeExpression() << endl;
    // for (unsigned int i = 0; i < a.size(); ++i)
    // cout << a[i] << endl;
    // cin >> a;
    return 0;
}