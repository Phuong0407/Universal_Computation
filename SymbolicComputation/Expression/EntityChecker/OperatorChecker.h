/**
 * @file OperatorChecker.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-21
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef OPERATOR_CHECKER_H
#define OPERATOR_CHECKER_H

namespace Expression
{
    class OperatorChecker
    {
    public:
        static bool isOperator(char Input)
        {
            if (Input == '+')
                return true;
            else if (Input == '-')
                return true;
            else if (Input == '*')
                return true;
            else if (Input == '/')
                return true;
            else if (Input == '^')
                return true;
            else
                return false;
        }
    };
    typedef class OperatorChecker OperatorChecker;
}

#endif