/**
 * @file ADInsideBracketExtraction.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-13
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef AD_INSIDE_BRACKET_EXTRACTION_H
#define AD_INSIDE_BRACKET_EXTRACTION_H

#include <stack>
#include "../BuildingBlock/BuildingBlock.h"
// #include "../BuildingBlock/InvalidExpressionException.h"

namespace Expression
{
    class StringInsideBracketExtraction
    {
    public:
        // Balance means parentheses goes in pair, like ()(()())
        static bool isBalanceRoundBracket(std::string Input)
        {
            bool Checker = true;
            char InputScanner;
            std::stack<char> ParenthesesStack;
            for (unsigned int i = 0; i < Input.length(); ++i)
            {
                if (Input[i] == '(')
                    ParenthesesStack.push(Input[i]);
                else if (Input[i] == ')')
                {
                    if (ParenthesesStack.empty() == true)
                        bool Checker = false;
                    else
                        ParenthesesStack.pop();
                }
                else
                    continue;
            }
            if (ParenthesesStack.empty() == true)
                Checker = true;
            else
                Checker = false;
            return Checker;
        }

        // Balance means brackets goes in pair, like [][[][]]
        static bool isBalanceSquareBracket(std::string Input)
        {
            bool Checker = true;
            char InputScanner;
            std::stack<char> BracketsStack;
            for (unsigned int i = 0; i < Input.length(); ++i)
            {
                if (Input[i] == '[')
                    BracketsStack.push(Input[i]);
                else if (Input[i] == ']')
                {
                    if (BracketsStack.empty() == true)
                        bool Checker = false;
                    else
                        BracketsStack.pop();
                }
                else
                    continue;
            }
            if (BracketsStack.empty() == true)
                Checker = true;
            else
                Checker = false;
            return Checker;
        }

        /**
         * @brief extract expression inside parentheses,
         * @param Input expression to get, it will be remove size
         * @return as expression inside parentheses in the form ---)
         */
        static std::string extractInsideRoundBracket(std::string &Input)
        {
            char InputScanner;
            size_t Iterator = 0;
            std::string InsideParenthesesBuilder = "";
            while (Iterator < Input.length())
            {
                while (Input[Iterator] != ')')
                {
                    InputScanner = Input[Iterator];
                    InsideParenthesesBuilder += InputScanner;
                    Iterator++;
                }
                InputScanner = Input[Iterator];
                InsideParenthesesBuilder += InputScanner;
                Iterator++;
                std::string CheckingBalance = "(";
                CheckingBalance += InsideParenthesesBuilder;
                if (isBalanceRoundBracket(CheckingBalance) == true)
                {
                    Input = Input.substr(InsideParenthesesBuilder.length(), Input.length());
                    return InsideParenthesesBuilder;
                }
            }
            throw std::runtime_error("Unbalanced brackets, please enter a corrected-form expression");
        }

        /**
         * @brief extract expression inside parentheses,
         * @param Input expression to get, it will be remove size
         * @return as expression inside parentheses in the form ---]
         */
        static std::string extractInsideSquareBracket(std::string &Input)
        {
            char InputScanner;
            size_t Iterator = 0;
            std::string InsideSquareBracketBuilder = "";
            while (Iterator < Input.length())
            {
                while (Input[Iterator] != ']')
                {
                    InputScanner = Input[Iterator];
                    InsideSquareBracketBuilder += InputScanner;
                    Iterator++;
                }
                InputScanner = Input[Iterator];
                InsideSquareBracketBuilder += InputScanner;
                Iterator++;
                std::string CheckingBalance = "[";
                CheckingBalance += InsideSquareBracketBuilder;
                if (isBalanceSquareBracket(CheckingBalance) == true)
                {
                    Input = Input.substr(InsideSquareBracketBuilder.length(), Input.length());
                    return InsideSquareBracketBuilder;
                }
            }
            throw std::runtime_error("Unbalanced brackets, please enter a corrected-form expression");
        }

    public:
        // BracketChoice is the kind of bracket to get expression, only two type '(', '['.
        // Input string is reduced in size
        static std::string extractInsideBracket(std::string &Input, std::string BracketChoice = "(")
        {
            if (BracketChoice == "(")
                return extractInsideRoundBracket(Input);
            else if (BracketChoice == "[")
                return extractInsideSquareBracket(Input);
            else
                return Input;
        }
    };
    typedef class StringInsideBracketExtraction StringInsideBracketExtraction;
}

#endif

// int main()
// {
//     std::string s = "sin(x)(z-4)";
//     // std::string a = ExpressionManagement::GetInsideParentheses::GetInsideBracketsExpression(s);
//     // for (unsigned int i = 0; i < a.length(); i++)
//     //     std::cout << a[i];

//     std::string a;
//     a = Expression::StringInsideBracketExtraction::extractInsideBracket(s, "(");
//     for (unsigned int i = 0; i < a.length(); i++)
//         std::cout << a[i];
//     std::cout << std::endl;
//     for (unsigned int i = 0; i < s.length(); i++)
//         std::cout << s[i];
// }