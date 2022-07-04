/**
 * @file ExpressionTokenCustomStorage.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_TOKEN_CUSTOM_STORAGE_CPP
#define EXPRESSION_TOKEN_CUSTOM_STORAGE_CPP

#include "ExpressionTokenCustomStorage.h"

namespace ExpressionManagement
{

    void ExpressionTokenCustomStorage::ExpressionCustomTokenInputAPI(std::string ExpressionStringInput)
    {
        this->ExpressionStringStorageInputAPI(ExpressionStringInput);
        this->ExpressionCustomTokenInfix = DecompositionToInfixCustomToken(this->OutputExpressionNoBlank());
        this->ExpressionCustomTokenPostfix = InfixToPostfixConversion(this->OutputExpressionCustomTokenInfix());
    }

    CustomTokenUnit ExpressionTokenCustomStorage::OutputExpressionCustomTokenInfix()
    {
        return this->ExpressionCustomTokenInfix;
    }
    CustomTokenUnit ExpressionTokenCustomStorage::OutputExpressionCustomTokenPostfix()
    {
        return this->ExpressionCustomTokenPostfix;
    }
}

#endif