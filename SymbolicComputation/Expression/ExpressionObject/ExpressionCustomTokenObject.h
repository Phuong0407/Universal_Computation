/**
 * @file ExpressionCustomTokenObject.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_CUSTOM_TOKEN_OBJECT_H
#define EXPRESSION_CUSTOM_TOKEN_OBJECT_H

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "../ProcessingMethod/ProcessingMainMethodAPI.cpp"

namespace ExpressionManagement
{

    class ExpressionCustomTokenObject
    {
    private:
        std::string ExpressionInputNoBlank;
        CustomTokenUnit ExpressionCustomTokenInfix;
        CustomTokenUnit ExpressionCustomTokenPostfix;
        CustomTokenUnit ArgumentNameList;

    protected:
        void GetArgumentNameList();
        void ExpressionCustomTokenInputAPI(std::string);

        std::string OutputExpressionNoBlank();
        CustomTokenUnit OutputExpressionCustomTokenInfix();
        CustomTokenUnit OutputExpressionCustomTokenPostfix();
    };
    typedef class ExpressionCustomTokenObject ExpressionCustomTokenObject;

    void ExpressionCustomTokenObject::GetArgumentNameList()
    {
        std::string ArgumentNameBuilder = "";
        if (ExpressionCustomTokenInfix.empty() == true)
            throw std::invalid_argument("Wrong in algorithm or invalid expression!");
        for (unsigned int i = 0; i < ExpressionCustomTokenInfix.size(); ++i)
        {
            if (IsArgument(ExpressionCustomTokenInfix[i]) == true)
            {
                ArgumentNameBuilder = ExpressionCustomTokenInfix[i];
                ArgumentNameList.push_back(ArgumentNameBuilder);
            }
        }
    }

    void ExpressionCustomTokenObject::ExpressionCustomTokenInputAPI(std::string ExpressionStringInput)
    {
        do
        {
            ExpressionStringInput.erase(remove(ExpressionStringInput.begin(), ExpressionStringInput.end(), ' '), ExpressionStringInput.end());
        } while (ExpressionStringInput.find(' ') == ExpressionStringInput.length());
        ExpressionInputNoBlank = RemoveUnaryOperator(ExpressionStringInput);
        ExpressionCustomTokenInfix = DecompositionToInfixCustomToken(OutputExpressionNoBlank());
        GetArgumentNameList();
    }

    std::string ExpressionCustomTokenObject::OutputExpressionNoBlank()
    {
        return this->ExpressionInputNoBlank;
    }

    CustomTokenUnit ExpressionCustomTokenObject::OutputExpressionCustomTokenInfix()
    {
        return this->ExpressionCustomTokenInfix;
    }

    CustomTokenUnit ExpressionCustomTokenObject::OutputExpressionCustomTokenPostfix()
    {
        return this->ExpressionCustomTokenPostfix;
    }
}

#endif