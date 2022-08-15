/**
 * @file ArgumentChecker.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-24
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef ARGUMENT_CHECKER_H
#define ARGUMENT_CHECKER_H

#include "StringNameChecker.h"
#include "BuiltInFunctionChecker.h"
#include "ConstantChecker.h"

namespace Expression
{
    class ArgumentChecker
    {
    public:
        static bool isArgument(std::string Input)
        {
            if (StringNameChecker::isStringName(Input) == false)
                return false;
            else if (BuiltInFunctionChecker::isBuiltInFunction(Input) != 0)
                return false;
            else if (ConstantChecker::isConstant(Input) == true)
                return false;
            else
                return true;
        }
    };
    typedef class ArgumentChecker ArgumentChecker;
}

#endif