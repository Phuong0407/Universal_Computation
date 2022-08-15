/**
 * @file ADInsideBracketExtraction.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-15
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef AP_INSIDE_BRACKET_EXTRACTION_H
#define AP_INSIDE_BRACKET_EXTRACTION_H

#include <stack>
#include <algorithm>
#include "../BuildingBlock/BuildingBlock.h"

namespace Expression
{
    class CustomTokenInsideBracketExtraction
    {
    public:
        // Balance means parentheses goes in pair, like ()(()())
        static bool isBalanceRoundBracket(CustomTokenExpression Input)
        {
            bool Checker = true;
            CustomToken InputScanner;
            std::stack<CustomToken> ParenthesesStack;
            for (unsigned int i = 0; i < Input.size(); ++i)
            {
                if (Input[i].second == "(")
                    ParenthesesStack.push(Input[i]);
                else if (Input[i].second == ")")
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
        static bool isBalanceSquareBracket(CustomTokenExpression Input)
        {
            bool Checker = true;
            CustomToken InputScanner;
            std::stack<CustomToken> ParenthesesStack;
            for (unsigned int i = 0; i < Input.size(); ++i)
            {
                if (Input[i].second == "[")
                    ParenthesesStack.push(Input[i]);
                else if (Input[i].second == "]")
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

        /**
         * @brief extract expression inside round bracket,
         * @param Input expression to get, it will be remove size
         * @return as expression inside parentheses in the form ---)
         */
        static CustomTokenExpression extractInsideRoundBracket(CustomTokenExpression &Input)
        {
            unsigned int Iterator = 0;
            CustomToken InputScanner;
            CustomTokenExpression InsideParenthesesBuilder;
            while (Iterator < Input.size())
            {
                while (Input[Iterator].second != ")")
                {
                    InputScanner = Input[Iterator];
                    InsideParenthesesBuilder.push_back(InputScanner);
                    Iterator++;
                }
                InputScanner = Input[Iterator];
                InsideParenthesesBuilder.push_back(InputScanner);
                Iterator++;
                if (isBalanceRoundBracket(InsideParenthesesBuilder) == true)
                {
                    Input.assign(Input.begin() + InsideParenthesesBuilder.size(), Input.end());
                    return InsideParenthesesBuilder;
                }
            }
            throw std::runtime_error("Unbalance round bracket expression");
        }

        /**
         * @brief extract expression inside square bracket,
         * @param Input expression to get, it will be remove size
         * @return as expression inside parentheses in the form ---]
         */
        static CustomTokenExpression extractInsideSquareBracket(CustomTokenExpression &Input)
        {
            unsigned int Iterator = 0;
            CustomTokenExpression InsideParenthesesBuilder;
            CustomToken InputScanner;
            while (Iterator < Input.size())
            {
                while (Input[Iterator].second != "]")
                {
                    InputScanner = Input[Iterator];
                    InsideParenthesesBuilder.push_back(InputScanner);
                    Iterator++;
                }
                InputScanner = Input[Iterator];
                InsideParenthesesBuilder.push_back(InputScanner);
                Iterator++;
                if (isBalanceSquareBracket(InsideParenthesesBuilder) == true)
                {
                    Input.assign(Input.begin() + InsideParenthesesBuilder.size(), Input.end());
                    return InsideParenthesesBuilder;
                }
            }
            throw std::runtime_error("Unbalance round bracket expression");
        }

    public:
        // BracketChoice is the kind of bracket to get expression, only two type '(', '['.
        static CustomTokenExpression extractInsideBracket(CustomTokenExpression &Input, std::string BracketChoice = "(")
        {
            if (BracketChoice == "(")
                return extractInsideRoundBracket(Input);
            else if (BracketChoice == "[")
                return extractInsideSquareBracket(Input);
            else
                throw std::runtime_error("Pass wrong argument for BracketChoice");
        }
    };
    typedef class CustomTokenInsideBracketExtraction CustomTokenInsideBracketExtraction;
}

#endif
// using namespace std;
// using namespace Expression;

// int main()
// {
//     CustomTokenExpression s;
//     s.push_back({1, "sin"});
//     s.push_back({1, "("});
//     s.push_back({1, "x"});
//     s.push_back({1, ")"});
//     s.push_back({1, ")"});
//     // s.push_back({1, "-"});
//     // s.push_back({1, "anh"});
//     // s.push_back({1, "+"});
//     // s.push_back({1, "va"});
//     // s.push_back({1, "-"});

//     for (unsigned int i = 0; i < s.size(); i++)
//         cout << s[i].second;
//     cout << endl;
//     CustomTokenExpression a = Expression::CustomTokenInsideBracketExtraction::extractInsideBracket(s, "(");
//     for (unsigned int i = 0; i < a.size(); i++)
//         cout << a[i].second;
//     cout << endl;
//     for (unsigned int i = 0; i < s.size(); i++)
//         cout << s[i].second;
//     cout << endl;
// }