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

#include "ExpressionStringObject.h"
#include "../ProcessingMethod/ProcessingMainMethodAPI.cpp"

namespace ExpressionManagement
{
    class ExpressionCustomTokenObject : public ExpressionStringObject
    {
    private:
        CustomTokenUnit ExpressionCustomTokenInfix;
        CustomTokenUnit ExpressionCustomTokenPostfix;

    protected:
        void ExpressionCustomTokenInputAPI(std::string);
        CustomTokenUnit OutputExpressionCustomTokenInfix();
        CustomTokenUnit OutputExpressionCustomTokenPostfix();
    };
    typedef class ExpressionCustomTokenObject ExpressionCustomTokenObject;

    void ExpressionCustomTokenObject::ExpressionCustomTokenInputAPI(std::string ExpressionStringInput)
    {
        this->ExpressionStringObjectInputAPI(ExpressionStringInput);
        this->ExpressionCustomTokenInfix = DecompositionToInfixCustomToken(this->OutputExpressionNoBlank());
        this->ExpressionCustomTokenPostfix = InfixToPostfixConversion(this->OutputExpressionCustomTokenInfix());
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