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
    /**
     * @brief Class ExpressionConversionToPostfix inherits public from class ExpressionGetInput.
     * @brief It contains one internal data to store input expression token unit in postfix form (without any arguments)
     * @brief API: ExpressionConversionToPostfixInputAPI() gets expression as a string to compute,
     * @brief API: then it transforms input to get a postfix form expression in CustomTokenUnit.
     * @brief API: OutputPostfixExpression() outputs postfix expression to build expression tree.
     */
    class ExpressionConversionToPostfix : public ExpressionGetInput
    {
    private:
        CustomTokenUnit ExpressionCustomTokenPostfix;

    public:
        void ExpressionConversionToPostfixInputAPI(std::string);
        CustomTokenUnit OutputPostfixExpression();
    };
    typedef class ExpressionConversionToPostfix ExpressionConversionToPostfix;

    /**
     * @brief ExpressionConversionToPostfixInputAPI() gets expression as a string to compute,
     * @brief It process expression (remove space, get input, build infix expression) and then transform it to postfix form
     * @param InputExpressionString 
     */
    void ExpressionConversionToPostfix::ExpressionConversionToPostfixInputAPI(std::string InputExpressionString)
    {
        this->GetInputMainExpressionAPI(InputExpressionString);
        this->ExpressionCustomTokenPostfix = InfixToPostfixConversion(this->OutputMainExpresionInfix());
    }
    
    /**
     * @brief OutputPostfixExpression() outputs postfix expression to build expression tree.
     * @return CustomTokenUnit as postfix form expression
     */
    CustomTokenUnit ExpressionConversionToPostfix::OutputPostfixExpression()
    {
        return this->ExpressionCustomTokenPostfix;
    }
}

#endif