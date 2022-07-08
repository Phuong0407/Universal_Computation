/**
 * @file ExpressionConversionToPostfix.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-07
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_CONVERSION_POSTFIX_H
#define EXPRESSION_CONVERSION_POSTFIX_H

#include "ExpressionGetInput.h"

namespace ExpressionManagement
{
    class ExpressionConversionToPostfix : public ExpressionGetInput
    {
    private:
        CustomTokenUnit ExpressionCustomTokenPostfix;

    public:
        void ExpressionConversionToPostfixInputAPI(std::string);
        CustomTokenUnit OutputPostfixExpression();
    };
    typedef class ExpressionConversionToPostfix ExpressionConversionToPostfix;

    void ExpressionConversionToPostfix::ExpressionConversionToPostfixInputAPI(std::string InputExpressionString)
    {
        this->GetInputMainExpressionAPI(InputExpressionString);
        this->ExpressionCustomTokenPostfix = InfixToPostfixConversion(this->OutputMainExpresionInfix());
    }
    CustomTokenUnit ExpressionConversionToPostfix::OutputPostfixExpression()
    {
        return this->ExpressionCustomTokenPostfix;
    }
}

#endif