/**
 * @file ExpressionTokenCustomStorage.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_TOKEN_CUSTOM_STORAGE_H
#define EXPRESSION_TOKEN_CUSTOM_STORAGE_H

#include "../Decomposition/DecompositionAPI.cpp"
#include "../PostfixConversion/InfixToPostfixAPI.cpp"
#include "../ExpressionString/ExpressionStringStorage.h"
#include "../ExpressionString/ExpressionStringStorage.cpp"

namespace ExpressionManagement
{
    class ExpressionTokenCustomStorage : public ExpressionStringStorage
    {
    private:
        CustomTokenUnit ExpressionCustomTokenInfix;
        CustomTokenUnit ExpressionCustomTokenPostfix;

    protected:
    public:
        void ExpressionCustomTokenInputAPI(std::string);
        CustomTokenUnit OutputExpressionCustomTokenInfix();
        CustomTokenUnit OutputExpressionCustomTokenPostfix();
    };
    typedef class ExpressionTokenCustomStorage ExpressionTokenCustomStorage;
}

#endif