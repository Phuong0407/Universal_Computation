/**
 * @file extractCheckingCharacter.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-23
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef CHECKING_CHAR_EXTRACTION_H
#define CHECKING_CHAR_EXTRACTION_H

#include <iostream>
#include <cstring>

namespace Expression
{
    class FirstCharExtraction
    {
    public:
        /**
         * @brief extract the first character of a string and reduce input size.
         * @return char as first character.
         */
        static char extractCheckingCharacter(std::string &Input)
        {
            if (Input.length() == 0)
                throw std::runtime_error("Input string is empty!");
            char FirstCharacter = Input[0];
            if (Input.length() == 1)
                Input = "";
            else if (Input.length() > 1)
                Input = Input.substr(1, Input.length());
            return FirstCharacter;
        }
    };
    typedef class FirstCharExtraction FirstCharExtraction;
}

#endif