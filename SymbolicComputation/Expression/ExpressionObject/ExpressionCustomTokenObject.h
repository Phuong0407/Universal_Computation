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
        std::string ExpressionInputInitial;
        std::string ExpressionInputNoBlank;
        CustomTokenUnit ExpressionCustomTokenInfix;
        CustomTokenUnit ExpressionCustomTokenPostfix;

    protected:
        void RemoveUnaryOperator();
        std::string OutputExpressionInitial();
        std::string OutputExpressionNoBlank();
        void ExpressionCustomTokenInputAPI(std::string);
        CustomTokenUnit OutputExpressionCustomTokenInfix();
        CustomTokenUnit OutputExpressionCustomTokenPostfix();
    };
    typedef class ExpressionCustomTokenObject ExpressionCustomTokenObject;

    void ExpressionCustomTokenObject::RemoveUnaryOperator()
    {
        if (this->ExpressionInputNoBlank[0] == '+' || this->ExpressionInputNoBlank[0] == '-')
        {
            std::string TempStringInsert = "";
            TempStringInsert += '0';
            TempStringInsert += this->ExpressionInputNoBlank;
            this->ExpressionInputNoBlank.assign(TempStringInsert);
        }
        for (unsigned int i = 0; i < this->ExpressionInputNoBlank.length(); ++i)
            if (this->ExpressionInputNoBlank[i] == '(' && (this->ExpressionInputNoBlank[i + 1] == '+' || this->ExpressionInputNoBlank[i + 1] == '-'))
                this->ExpressionInputNoBlank.insert(i + 1, "0");
    }

    void ExpressionCustomTokenObject::ExpressionCustomTokenInputAPI(std::string ExpressionStringInput)
    {
        this->ExpressionInputInitial = ExpressionStringInput;
        do
        {
            ExpressionStringInput.erase(remove(ExpressionStringInput.begin(), ExpressionStringInput.end(), ' '), ExpressionStringInput.end());
        } while (ExpressionStringInput.find(' ') == ExpressionStringInput.length());
        this->ExpressionInputNoBlank = ExpressionStringInput;
        this->RemoveUnaryOperator();
        this->ExpressionCustomTokenInfix = DecompositionToInfixCustomToken(this->OutputExpressionNoBlank());
        this->ExpressionCustomTokenPostfix = InfixToPostfixConversion(this->OutputExpressionCustomTokenInfix());
    }

    std::string ExpressionCustomTokenObject::OutputExpressionInitial()
    {
        return this->ExpressionInputInitial;
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