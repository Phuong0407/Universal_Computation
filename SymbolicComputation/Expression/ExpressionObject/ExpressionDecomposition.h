/**
 * @file ExpressionDecomposition.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_DECOMPOSITION_H
#define EXPRESSION_DECOMPOSITION_H

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "../ProcessingMethod/ProcessingMainMethodAPI.cpp"

namespace ExpressionManagement
{
    class ExpressionDecomposition
    {
    private:
        std::string ExpressionInputNoBlank;
        CustomTokenUnit ExpressionCustomTokenInfix;
        CustomTokenUnit ArgumentNameList;

    public:
        void ExpressionDecompositionInputAPI(std::string);
        std::string OutputExpressionNoBlank();
        CustomTokenUnit OutputArgumentNameList();
        CustomTokenUnit OutputExpressionCustomTokenInfix();
    };
    typedef class ExpressionDecomposition ExpressionDecomposition;

    void ExpressionDecomposition::ExpressionDecompositionInputAPI(std::string ExpressionStringInput)
    {
        do
        {
            ExpressionStringInput.erase(remove(ExpressionStringInput.begin(), ExpressionStringInput.end(), ' '), ExpressionStringInput.end());
        } while (ExpressionStringInput.find(' ') == ExpressionStringInput.length());
        if (ExpressionStringInput == this->OutputExpressionNoBlank())
            return;
        ExpressionInputNoBlank = RemoveUnaryOperator(ExpressionStringInput);
        ExpressionCustomTokenInfix = DecompositionToInfixCustomToken(this->OutputExpressionNoBlank());
        ArgumentNameList = CreateArgumentNameList(ExpressionCustomTokenInfix);
    }

    std::string ExpressionDecomposition::OutputExpressionNoBlank()
    {
        return this->ExpressionInputNoBlank;
    }

    CustomTokenUnit ExpressionDecomposition::OutputExpressionCustomTokenInfix()
    {
        return this->ExpressionCustomTokenInfix;
    }

    CustomTokenUnit ExpressionDecomposition::OutputArgumentNameList()
    {
        return this->ArgumentNameList;
    }
}

#endif