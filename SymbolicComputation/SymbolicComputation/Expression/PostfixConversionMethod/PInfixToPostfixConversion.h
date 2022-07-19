/**
 * @file PInfixToPostfixConversion.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-15
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef P_INFIX_TO_POSTFIX_H
#define P_INFIX_TO_POSTFIX_H

#include <stack>
#include "../AuxiliaryMethod/APInsideBracketExtraction.h"
#include "../InfixConversionMethod/StringToInfixConversion.h"
#include "../StringProcessingMethod/StringPreProcessorAPI.h"

namespace Expression
{
    class InfixToPostfixConversion
    {
    public:
        // Get element from custom token infix,
        // remove this element if RemoveChoice != 0
        static CustomToken extractFirstUnitCustomToken(CustomTokenExpression &Input, int RemoveChoice = 0)
        {
            CustomToken FirstUnit = Input[0];
            if (RemoveChoice != 0)
                Input.erase(Input.begin());
            return FirstUnit;
        }

        static CustomTokenExpression convertInfixToPostfix(CustomTokenExpression InfixInput)
        {
            CustomToken InfixScanner;
            CustomTokenExpression PostfixExpression;
            std::stack<CustomToken> PostfixConversionStack;
            while (InfixInput.size() != 0)
            {
                InfixScanner = extractFirstUnitCustomToken(InfixInput, 1);
                if (InfixScanner.first >= FunctionID && InfixScanner.first <= ParaOptFunctionID)
                {
                    CustomTokenExpression InsideParentheses = CustomTokenInsideBracketExtraction::extractInsideBracket(InfixInput);
                    CustomTokenExpression InsideParenthesesConversion = convertInfixToPostfix(InsideParentheses);
                    PostfixExpression.insert(PostfixExpression.end(), InsideParenthesesConversion.begin(), InsideParenthesesConversion.end());
                    PostfixExpression.push_back(InfixScanner);
                }
                else if (InfixScanner.first == LeftRoundBracketID || InfixScanner.first == LeftSquareBracketID)
                    PostfixConversionStack.push(InfixScanner);
                else if (InfixScanner.first == RightRoundBracketID)
                {
                    while (PostfixConversionStack.top().first != LeftRoundBracketID)
                    {
                        PostfixExpression.push_back(PostfixConversionStack.top());
                        PostfixConversionStack.pop();
                    }
                    PostfixConversionStack.pop();
                }
                else if (InfixScanner.first == RightSquareBracketID)
                {
                    while (PostfixConversionStack.top().first != LeftSquareBracketID)
                    {
                        PostfixExpression.push_back(PostfixConversionStack.top());
                        PostfixConversionStack.pop();
                    }
                    PostfixConversionStack.pop();
                }
                else if (InfixScanner.first >= PowerOperatorID && InfixScanner.first <= AddSubOperatorID)
                {
                    while ((PostfixConversionStack.empty() == false) && (InfixScanner.first >= PostfixConversionStack.top().first))
                    {
                        PostfixExpression.push_back(PostfixConversionStack.top());
                        PostfixConversionStack.pop();
                    }
                    PostfixConversionStack.push(InfixScanner);
                }
                else
                    PostfixExpression.push_back(InfixScanner);
            }
            while (PostfixConversionStack.empty() == false)
            {
                PostfixExpression.push_back(PostfixConversionStack.top());
                PostfixConversionStack.pop();
            }
            return PostfixExpression;
        }

        static CustomTokenExpression convertStringToPostfix(std::string Input)
        {
            Input = ExpressionPreProcessing::preprocessExpressionString(Input);
            CustomTokenExpression InfixExpression = StringToInfixConversion::decomposeStringToInfix(Input);
            InfixExpression = StringToInfixConversion::createCompleteFormInfix(InfixExpression);
            CustomTokenExpression PostfixExpression = convertInfixToPostfix(InfixExpression);
            return PostfixExpression;
        }
    };
    typedef class InfixToPostfixConversion InfixToPostfixConversion;
}

#endif
// using namespace std;
// using namespace Expression;

// int main()
// {
//     // std::string s = "[sin(x)]";
//     // std::string s = "log[sin(x)-5](x-5)";
//     std::string s = "cos[rad](x-4)*sinh(tan(y)+12.213213213)-fineStruct^2+log[pi](a)";
//     CustomTokenExpression a = StringToInfixConversion::decomposeStringToInfix(s);
//     CustomTokenExpression b = InfixToPostfixConversion::convertInfixToPostfix(a);
//     for (unsigned int i = 0; i < b.size(); i++)
//         std::cout << b[i].second << std::endl;
// }