/**
 * @file NumberChecker.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-21
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef NUMBER_CHECKER_H
#define NUMBER_CHECKER_H

#include "../BuildingBlock/BuildingBlock.h"

namespace Expression
{
    class NumberChecker
    {
    private:
        static bool isNormalNumber(std::string Input)
        {
            if (Input.length() == 0)
                return false;
            else if (Input == "-." || Input == "+.")
                return false;
            else
            {
                int PointCount = 0;
                for (size_t i = 0; i < Input.length(); i++)
                {
                    if (Input[i] == '.')
                    {
                        if (PointCount == 1)
                            return false;
                        else
                            PointCount++;
                    }
                    else if (isdigit(Input[i]) != 0)
                        continue;
                    else if ((Input[i] == '+' || Input[i] == '-') && i == 0)
                        continue;
                    else if ((Input[i] == '+' || Input[i] == '-') && i != 0)
                        return false;
                    else
                        return false;
                }
                return true;
            }
        }

        static bool isScientificNumber(std::string Input)
        {
            int EPosition = Input.find('E');
            if (EPosition == std::string::npos)
                return false;
            if (EPosition == 0 || EPosition == Input.length())
                return false;
            std::string BaseNumberString = Input.substr(0, EPosition);
            std::string PowNumberString = Input.substr(EPosition + 1, Input.length());
            if (isNormalNumber(BaseNumberString) == true && isNormalNumber(PowNumberString) == true)
                return true;
            return false;
        }

    public:
        /**
         * @brief check whether a string is a number or not.
         * @return int 1 for normal number, 2 for scientific number and 0 if input is not a number.
         */
        static int isNumber(std::string Input)
        {
            if (isNormalNumber(Input) == true)
                return 1;
            else if (isScientificNumber(Input) == true)
                return 2;
            else
                return 0;
        }
    };
    typedef class NumberChecker NumberChecker;
}

#endif

// using namespace std;
// using namespace Expression;

// int main()
// {
//     cout << NumberChecker::isNumber("-1.223434123213");
// }