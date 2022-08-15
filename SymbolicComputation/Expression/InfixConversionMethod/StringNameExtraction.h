/**
 * @file StringNameExtraction.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-23
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef STRING_NAME_EXTRACTION_H
#define STRING_NAME_EXTRACTION_H

#include <ctype.h>
#include <cstring>
#include <iostream>

namespace Expression
{
    class StringNameExtraction
    {
    public:
        /**
         * @brief String name are string with alphabet or underscore (argument, constants or built-in functions).
         * We also reduce input string length, used as auxiliary method for string to infix conversion.
         * @return std::string as String name.
         */
        static std::string extractStringName(std::string Input, std::size_t Index = 0)
        {
            std::string StringNameBuilder = "";
            for (std::size_t StringNameIndex = Index; StringNameIndex < Input.length(); StringNameIndex++)
                if (isalpha(Input[StringNameIndex]) != 0 || Input[StringNameIndex] == '_')
                    StringNameBuilder += Input[StringNameIndex];
                else
                    break;
            return StringNameBuilder;
        }

        /**
         * @brief check if a char is a string name or not, string name are alphabet or underscore (argument, constants or built-in functions).
         * used as auxiliary method for string to infix conversion.
         */
        static bool isStringName(char Input)
        {
            if (isalpha(Input) != 0 || Input == '_')
                return true;
            else
                return false;
        }
    };
    typedef class StringNameExtraction StringNameExtraction;
}

#endif

// using namespace std;
// using namespace Expression;

// int main()
// {
//     string s = "dfghijknj*jsiokdnsfdsskafflfssdafjj";
//     cout << StringNameExtraction::extractStringName(s) << endl;
//     cout << s << endl;
// }