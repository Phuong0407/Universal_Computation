/**
 * @file StringToInfixConversion.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-22
 * @copyright Copyright (c) 2022
 */

#ifndef STRING_TO_INFIX_CONVERSION_METHOD_H
#define STRING_TO_INFIX_CONVERSION_METHOD_H

#include "../EntityChecker/EntityChecker.h"
#include "NumberExtraction.h"
#include "FirstCharExtraction.h"
#include "StringNameExtraction.h"
#include "InsideBracketExtraction.h"
#include "CreationID.h"

namespace Expression
{
    class StringToInfixConversion
    {
    private:
    public:
        /**
         * @brief We need to create ID for entity inside this functions, because we want to reduce time complexity.
         * Each argument name need a unique ID, because when compute expression tree, we could use a valued array of argument value instead of using a map!
         * ArgumentID and index of value array relates with an offset number of 12.
         * In previous version, we use a unordered_map<string, double> to pass to functions, too complex!
         * @param ExpressionNoBlank is string without space.
         * @return StringExpression
         */
        static CustomTokenExpression convertStringToInfix(std::string ExpressionNoBlank)
        {
            std::size_t Index = 0;
            std::size_t InputStringLength = ExpressionNoBlank.length();
            CustomTokenExpression StringInfixBuilder;
            while (Index < InputStringLength)
            {
                if (Index == InputStringLength - 1)
                {
                    if (ExpressionNoBlank[Index] == ')' || isalpha(ExpressionNoBlank[Index]) != 0)
                    {
                        std::string LastCharacterString = "";
                        LastCharacterString += ExpressionNoBlank[Index];
                        StringInfixBuilder.push_back(CreationID::createExpressionUnitID(LastCharacterString));
                        Index++;
                    }
                    else
                    {
                        Index++;
                        throw std::runtime_error("Invalid expression!");
                    }
                }
                else
                {
                    char ExpressionScanner = ExpressionNoBlank[Index];
                    if (StringNameExtraction::isStringName(ExpressionScanner) == true)
                    {
                        std::string StringName = StringNameExtraction::extractStringName(ExpressionNoBlank, Index);
                        Index += StringName.length();
                        {
                            ExpressionScanner = ExpressionNoBlank[Index];
                            if (ExpressionScanner == '[')
                            {
                                Index++;
                                StringName += "[";
                                std::string InsideSquareBracket = InsideBracketExtraction::extractInsideBracket(ExpressionNoBlank, Index, "[");
                                Index += InsideSquareBracket.length();
                                StringName += InsideSquareBracket;
                            }
                        }
                        StringInfixBuilder.push_back(CreationID::createExpressionUnitID(StringName));
                    }
                    else
                    {
                        ExpressionScanner = ExpressionNoBlank[Index];
                        if (OperatorChecker::isOperator(ExpressionScanner) == true)
                        {
                            std::string OperatorString = "";
                            OperatorString += ExpressionScanner;
                            StringInfixBuilder.push_back(CreationID::createExpressionUnitID(OperatorString));
                            Index += OperatorString.length();
                        }
                        else if (isdigit(ExpressionScanner) != 0 || ExpressionScanner == '+' || ExpressionScanner == '-' || ExpressionScanner == 'E' || ExpressionScanner == '.')
                        {
                            std::string NumberString = NumberExtraction::extractNumber(ExpressionNoBlank, Index);
                            StringInfixBuilder.push_back(CreationID::createExpressionUnitID(NumberString));
                            Index += NumberString.length();
                        }
                        else if (ExpressionScanner == '(' || ExpressionScanner == '[')
                        {
                            std::string LeftBracket = "";
                            LeftBracket += ExpressionScanner;
                            StringInfixBuilder.push_back(CreationID::createExpressionUnitID(LeftBracket));
                            Index++;
                        }
                        else if (ExpressionScanner == ')' || ExpressionScanner == ']')
                        {
                            std::string RightBracket = "";
                            RightBracket += ExpressionScanner;
                            StringInfixBuilder.push_back(CreationID::createExpressionUnitID(RightBracket));
                            Index++;
                        }
                        else
                            throw std::runtime_error("Invalid expression!");
                    }
                }
            }
            return StringInfixBuilder;
        }
    };
    typedef class StringToInfixConversion StringToInfixConversion;
}
#endif

// using namespace std;
// using namespace Expression;
// int main()
// {
//     string s = "cos(log(log(log(x-5)*4+3*tanh(x)-abs(c-x))))";
//     CustomTokenExpression a = StringToInfixConversion::convertStringToInfix(s);
//     for (int i = 0; i < a.size(); i++)
//         cout << a[i].second;
//     cout << endl
//          << a.size();
//     // for (int i = 0; i < a.size(); i++)
//     //     cout << a[i].second;
//     // for (int i = 0; i < s.size(); i++)
//     //     cout << s[i];
// }