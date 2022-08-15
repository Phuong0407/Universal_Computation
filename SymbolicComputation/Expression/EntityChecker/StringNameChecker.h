/**
 * @file StringNameChecker.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-24
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef STRING_NAME_CHECKER_H
#define STRING_NAME_CHECKER_H

#include <cstring>
#include <iostream>

namespace Expression
{
    class StringNameChecker
    {
    public:
        static bool isStringName(std::string Input)
        {
            for (std::size_t i = 0; i < Input.length(); ++i)
            {
                if (Input[i] == '_' || (Input[i] >= 'a' && Input[i] <= 'z') || (Input[i] >= 'A' && Input[i] <= 'Z'))
                    continue;
                else
                    return false;
            }
            return true;
        }
    };
    typedef class StringNameChecker StringNameChecker;
}

#endif