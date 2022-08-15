/**
 * @file BuiltInFunction.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-21
 * @copyright Copyright (c) 2022
 */

/**
 *
 *
 */

#pragma once
#ifndef BUILT_IN_FUNCTION_H
#define BUILT_IN_FUNCTION_H

#include "../BuildingBlock/BuildingBlock.h"

namespace Expression
{
    class BuiltInFunctionChecker
    {
    public:
        /**
         * @brief check if a name string is a built-in function or not.
         * @return 1 if it is a non-base function, 2 if it is a base function, and 0 otherwise.
         */
        static int isBuiltInFunction(std::string Input)
        {
            if (NoBaseBuiltInFunction.find(Input) != NoBaseBuiltInFunction.end())
                return 1;
            else if (BaseBuiltInFunction.find(Input) != BaseBuiltInFunction.end())
                return 2;
            else
                return 0;
        }
    };
    typedef class BuiltInFunctionChecker BuiltInFunctionChecker;
}

#endif