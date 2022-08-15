/**
 * @file IDCreation.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-13
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef CREATE_ID_H
#define CREATE_ID_H

#include <ctype.h>
#include <utility>
#include "../EntityChecker/EntityChecker.h"

namespace Expression
{
    class CreationID
    {
    private:
        // return 0 if it is not a built-in function
        // return 1 if it is non-base built-in function
        // return 2 if it is a base built-in function without square brackets
        // return 3 if it is a base built-in function with square brackets
        static int checkBuiltInFunctionSquareBracket(std::string Input)
        {
            if (BuiltInFunctionChecker::isBuiltInFunction(Input) == 1)
                return 1;
            std::string FunctionNotation = "";
            for (std::size_t i = 0; i < Input.length(); i++)
            {
                if (Input[i] != '[')
                    FunctionNotation += Input[i];
                else
                    break;
            }
            if (BuiltInFunctionChecker::isBuiltInFunction(FunctionNotation) == 2 && FunctionNotation == Input)
                return 2;
            else if (BuiltInFunctionChecker::isBuiltInFunction(FunctionNotation) == 2 && FunctionNotation != Input)
                return 3;
            else
                return 0;
        }

    public:
        static CustomToken createExpressionUnitID(std::string Input, int ArgumentID = -1)
        {
            CustomToken TempStringPair;
            if (Input == "^")
                TempStringPair = std::make_pair(PowerOperatorID, Input);
            else if (Input == "*" || Input == "/")
                TempStringPair = std::make_pair(MulDivOperatorID, Input);
            else if (Input == "+" || Input == "-")
                TempStringPair = std::make_pair(AddSubOperatorID, Input);
            else if (Input == "(")
                TempStringPair = std::make_pair(LeftRoundBracketID, Input);
            else if (Input == ")")
                TempStringPair = std::make_pair(RightRoundBracketID, Input);
            else if (Input == "[")
                TempStringPair = std::make_pair(LeftSquareBracketID, Input);
            else if (Input == "]")
                TempStringPair = std::make_pair(RightSquareBracketID, Input);
            else if (checkBuiltInFunctionSquareBracket(Input) == 1 || checkBuiltInFunctionSquareBracket(Input) == 2)
                TempStringPair = std::make_pair(NoBaseFunctionID, Input);
            else if (checkBuiltInFunctionSquareBracket(Input) == 3)
                TempStringPair = std::make_pair(BaseFunctionID, Input);
            else if (ConstantChecker::isConstant(Input) == true)
                TempStringPair = std::make_pair(ConstantID, Input);
            else if (NumberChecker::isNumber(Input) == 1)
                TempStringPair = std::make_pair(NormalNumberID, Input);
            else if (NumberChecker::isNumber(Input) == 2)
                TempStringPair = std::make_pair(ScientificNumberID, Input);
            else if (ArgumentChecker::isArgument(Input) == true && (ArgumentID = -1 || ArgumentID >= 12))
                TempStringPair = std::make_pair(ArgumentID, Input);
            else
                throw std::runtime_error("Invalid expression!");
            return TempStringPair;
        }
    };
    typedef class CreationID CreationID;
}

#endif

// int main()
// {
// }