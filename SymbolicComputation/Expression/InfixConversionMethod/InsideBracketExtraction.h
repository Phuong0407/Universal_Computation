/**
 * @file InsideBracketExtraction.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-13
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef STRING_INSIDE_BRACKET_EXTRACTION_H
#define STRING_INSIDE_BRACKET_EXTRACTION_H

#include <stack>
#include "../BuildingBlock/BuildingBlock.h"
// #include "../BuildingBlock/InvalidExpressionException.h"

namespace Expression
{
    class InsideBracketExtraction
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
        static std::string extractInsideRoundBracket(std::string Input, std::size_t Index = 0)
        {
            char InputScanner;
            size_t Iterator = Index;
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
                    return InsideParenthesesBuilder;
            }
            throw std::runtime_error("Unbalanced brackets, please enter a corrected-form expression");
        }

        /**
         * @brief extract expression inside parentheses,
         * @param Input expression to get, it will be remove size
         * @return as expression inside parentheses in the form ---]
         */
        static std::string extractInsideSquareBracket(std::string Input, std::size_t Index = 0)
        {
            char InputScanner;
            size_t Iterator = Index;
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
                    return InsideSquareBracketBuilder;
            }
            throw std::runtime_error("Unbalanced brackets, please enter a corrected-form expression");
        }

    public:
        // BracketChoice is the kind of bracket to get expression, only two type '(', '['.
        // Input string is reduced in size
        static std::string extractInsideBracket(std::string &Input, std::size_t Index = 0, std ::string BracketChoice = "(")
        {
            if (BracketChoice == "(")
                return extractInsideRoundBracket(Input, Index);
            else if (BracketChoice == "[")
                return extractInsideSquareBracket(Input, Index);
            else
                return Input;
        }
    };
    typedef class InsideBracketExtraction InsideBracketExtraction;
}
#endif

// using namespace std;
// using namespace Expression;

// int main()
// {
//     std::string s = "sin(x))(z-4)";
//     // std::string a = ExpressionManagement::GetInsideParentheses::GetInsideBracketsExpression(s);
//     // for (unsigned int i = 0; i < a.length(); i++)
//     //     std::cout << a[i];

//     std::string a;
//     a = Expression::InsideBracketExtraction::extractInsideBracket(s, 0, "(");
//     for (unsigned int i = 0; i < a.length(); i++)
//         std::cout << a[i];
//     std::cout << std::endl;
//     for (unsigned int i = 0; i < s.length(); i++)
//         std::cout << s[i];
// }