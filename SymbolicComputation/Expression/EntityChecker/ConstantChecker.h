/**
 * @file ConstantChecker.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-22
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef CONSTANTS_CHECKER_H
#define CONSTANTS_CHECKER_H

namespace Expression
{
    class ConstantChecker
    {
    public:
        static bool isConstant(std::string Input)
        {
            if (UniversalConstant.find(Input) != UniversalConstant.end())
                return true;
            else
                return false;
        }
    };
    typedef class ConstantChecker ConstantChecker;
}

#endif