/**
 * @file DStringPreProcessorAPI.h
 * @author Thanh Phuong Diep (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-13
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef STR_PRE_PROCESSOR_API_H
#define STR_PRE_PROCESSOR_API_H

#include <cstring>
#include <iostream>
#include "../AuxiliaryMethod/ADCustomTokenCreationID.h"
#include "../AuxiliaryMethod/ADInsideBracketExtraction.h"

namespace Expression
{
    class ExpressionPreProcessing
    {
    public:
        // Check if a character is an operator or not, serves as a checking method for preprocessing
        static bool isOperator(char Input)
        {
            if (Input == '^' || Input == '*' || Input == '/' || Input == '+' || Input == '-')
                return true;
            return false;
        }

        // Check if a character is an operator or not, serves as a checking method for preprocessing
        static bool isOperator(std::string Input)
        {
            if (Input == "^" || Input == "*" || Input == "/" || Input == "+" || Input == "-")
                return true;
            return false;
        }

        // Check if an expression is valid or not. Valid means syntax is suitable
        static bool isRegularExpression(std::string Input)
        {
            int CheckCounter = 0;
            for (unsigned int i = 0; i < Input.length(); i++)
            {
                if (isOperator(Input[i]) == true && isOperator(Input[i + 1]) == true)
                    return false;
                else if (isOperator(Input[i]) == true && (Input[i + 1] == ')' || Input[i + 1] == ']'))
                    return false;
                else if (isOperator(Input[i]) == true || isalpha(Input[i]) != 0 || isdigit(Input[i]) != 0)
                    CheckCounter++;
                else if (Input[i] == '_' || Input[i] == '.')
                    CheckCounter++;
                else if (Input[i] == '(' || Input[i] == ')' || Input[i] == '[' || Input[i] == ']')
                    CheckCounter++;
            }
            if (StringInsideBracketExtraction::isBalanceRoundBracket(Input) == false)
                return false;
            else if (StringInsideBracketExtraction::isBalanceSquareBracket(Input) == false)
                return false;
            else if (isOperator(Input[Input.length() - 1]) == true)
                return false;
            if (CheckCounter == Input.length())
                return true;
            else
                return false;
        }

        // First preprocessing method, because we work with non space string
        static std::string removeSpace(std::string Input)
        {
            do
            {
                Input.erase(remove(Input.begin(), Input.end(), ' '), Input.end());
            } while (Input.find(' ') != std::string::npos);
            return Input;
        }

        // Only removes + and - in the form +3 + 4 by transform to 0 + 3 + 4, for example
        // InputToRemove string to remove
        static std::string removeUnaryOperator(std::string InputToRemove)
        {
            std::string TempStringInsert = "";
            if (InputToRemove[0] == '+' || InputToRemove[0] == '-')
            {
                TempStringInsert += '0';
                TempStringInsert += InputToRemove;
                InputToRemove.assign(TempStringInsert);
            }
            for (unsigned int i = 0; i < InputToRemove.length(); ++i)
                if (InputToRemove[i] == '(' && (InputToRemove[i + 1] == '+' || InputToRemove[i + 1] == '-'))
                    InputToRemove.insert(i + 1, "0");
            return InputToRemove;
        }

        // static std::string createCompleteFormExpression(std::string Input)
        // {
        //     std::size_t iterator = 0;
        //     while (iterator < Input.size())
        //     {
        //         if (Input[i] == '(' && Input)
        //     }
        // }

    public:
        static std::string preprocessExpressionString(std::string Input)
        {
            Input = removeSpace(Input);
            if (isRegularExpression(Input) == false)
                throw std::runtime_error("Invalid expression, please enter expression again!");
            Input = removeUnaryOperator(Input);
            return Input;
        }
    };
    typedef class ExpressionPreProcessing ExpressionPreProcessing;
}

#endif

// int main()
// {
//     std::string s = "sin(x)-5";
//     std::string a = ExpressionManagement::ExpressionPreProcessing::InputCompleteFormAPI(s);
//     for (unsigned int j = 0; j < a.size(); ++j)
//         std::cout << a[j] << "__v" << std::endl;
// }