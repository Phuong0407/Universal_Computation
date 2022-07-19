/**
 * @file InvalidExpressionException.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 0.1
 * @date 2022-07-17
 * @copyright Copyright (c) 2022
 */

#ifndef INVALID_EXPRESSION_EXCEPTION_H
#define INVALID_EXPRESSION_EXCEPTION_H

#include <cstring>
#include <iostream>
#include <exception>

namespace Expression
{
    class InvalidExpressionException : public std::exception
    {
    private:
        std::string InvalidExpressionMessage = "You enter an invalid expression, please enter again the valid expression!";
        std::string ValidExpressionFormMessage = "A valid expression contains operators, functions, variables, constants, numbers, round bracket pair and square bracket pair.\n There is no two consecutive operators, variables, constants, or number.";

    public:
        std::string ErrorMessage()
        {
            return InvalidExpressionException;
        }
    };
    typedef class InvalidExpressionException InvalidExpressionException;
}

#endif