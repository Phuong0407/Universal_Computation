/**
 * @file NumberExtraction.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-23
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef NUMBER_EXTRACTION_H
#define NUMBER_EXTRACTION_H

#include "../EntityChecker/EntityChecker.h"

namespace Expression
{
    class NumberExtraction
    {
    private:
        static std::string extractNormalNumber(std::string Input, std::size_t Index = 0)
        {
            if (Index >= Input.length() || Input.length() == 0)
                throw std::runtime_error("No number string!");
            std::string NormalNumberString = "";
            for (std::size_t i = Index; i < Input.length(); ++i)
            {
                if (isdigit(Input[i]) != 0)
                    NormalNumberString += Input[i];
                else if (Input[i] == '.')
                    NormalNumberString += Input[i];
                else if ((Input[i] == '+' || Input[i] == '-') && i == Index)
                    NormalNumberString += Input[i];
                else if ((Input[i] == '+' || Input[i] == '-') && i != Index)
                    break;
            }
            if (NumberChecker::isNumber(NormalNumberString) != 0)
                return NormalNumberString;
            else
                throw std::runtime_error("Invalid number format");
        }

        static std::string extractScientificNumber(std::string Input, std::size_t Index = 0)
        {
            if (Index >= Input.length() || Input.length() == 0)
                throw std::runtime_error("No number string!");
            std::string ScientificNumber = "";
            for (std::size_t i = Index; i < Input.length(); ++i)
            {
                if (isdigit(Input[i]) != 0)
                    ScientificNumber += Input[i];
                else if (Input[i] == '.')
                    ScientificNumber += Input[i];
                else if (Input[i] == 'E')
                    ScientificNumber += Input[i];
                else if ((Input[i] == '+' || Input[i] == '-') && i == Index)
                    ScientificNumber += Input[i];
                else if ((Input[i] == '+' || Input[i] == '-') && Input[i - 1] == 'E')
                    ScientificNumber += Input[i];
                else
                    break;
            }
            if (NumberChecker::isNumber(ScientificNumber) != 0)
                return ScientificNumber;
            else
                throw std::runtime_error("Invalid scientific number format");
        }

    public:
        static std::string extractNumber(std::string Input, std::size_t Index = 0)
        {
            std::string ExtractedNumber = extractScientificNumber(Input, Index);
            return ExtractedNumber;
        }
    };
    typedef class NumberExtraction NumberExtraction;
}

#endif

// using namespace std;
// using namespace Expression;

// int main()
// {
//     string s = "qwewew-233243242.23233232432412312321321jjsiokdnsfdsskafflfssdafjj";
//     cout << NumberExtraction::extractNumber(s, 6) << endl;
//     cout << s << endl;
// }