/**
 * @file ADCustomTokenUnitIDCreation.h
 * @author Thanh Phuong Diep (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-13
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef AD_CUSTOM_TOKEN_CREATE_ID_H
#define AD_CUSTOM_TOKEN_CREATE_ID_H

#include <ctype.h>
#include <utility>
#include "../BuildingBlock/BuildingBlock.h"

namespace Expression
{
    class CustomTokenUnitIDCreation
    {
    public:
        static bool isNumber(std::string Input)
        {
            int PointCounter = 0;
            int StringCounter = 0;
            if (Input[0] == '-' || Input[0] == '+' || isdigit(Input[0]) == true)
                StringCounter++;
            for (unsigned int Iterator = 1; Iterator < Input.length(); ++Iterator)
            {
                if (isdigit(Input[Iterator]) == true)
                    StringCounter++;
                else if (Input[Iterator] == '.')
                {
                    PointCounter++;
                    StringCounter++;
                }
                else
                    continue;
            }
            if (PointCounter > 1 || StringCounter < Input.length())
                return false;
            return true;
        }

        static bool isConstant(std::string Input)
        {
            auto Search = UniversalConstant.find(Input);
            if (Search != UniversalConstant.end())
                return true;
            else
                return false;
        }

        static bool isArgument(std::string Input)
        {
            int StringCounter = 0;
            if (isalpha(Input[0]) != 0 || Input[0] == '_')
                StringCounter++;
            for (unsigned int i = 1; i < Input.length(); ++i)
            {
                if (isalpha(Input[i]) != 0 || Input[i] == '_' || isdigit(Input[i]) == true)
                    StringCounter++;
                else
                    continue;
            }
            if (StringCounter == Input.length())
                return true;
            else
                return false;
        }

        // return 0 if it is not a built-in function
        // return 1 if it is built-in function
        // return 2 if it is a built-in function without square brackets
        // return 3 if it is a built-in function with square brackets
        static int isBuiltInFunction(std::string Input)
        {
            std::string FunctionNotation = "";
            for (unsigned int i = 0; i < Input.length(); i++)
            {
                if (Input[i] != '[')
                    FunctionNotation += Input[i];
                else
                    break;
            }
            if (OptionalParameterizedBuiltInFunctions.find(FunctionNotation) != OptionalParameterizedBuiltInFunctions.end() && FunctionNotation != Input)
                return 3;
            else if (OptionalParameterizedBuiltInFunctions.find(FunctionNotation) != OptionalParameterizedBuiltInFunctions.end() && FunctionNotation == Input)
                return 2;
            else if (NonParameterBuiltInFunctions.find(FunctionNotation) != NonParameterBuiltInFunctions.end())
                return 1;
            return 0;
        }

        // General operand are number, built-in function, variable, constant
        static bool isGeneralOperand(char Input)
        {
            if (isalpha(Input) != 0)
                return true;
            else if (Input == '_')
                return true;
            else if (isdigit(Input) != 0)
                return true;
            else if (Input == '.')
                return true;
            else
                return false;
        }

        static CustomToken createExpressionUnitID(std::string Input)
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
            else if (isBuiltInFunction(Input) == 1 || isBuiltInFunction(Input) == 2)
                TempStringPair = std::make_pair(FunctionID, Input);
            else if (isBuiltInFunction(Input) == 3)
                TempStringPair = std::make_pair(ParaOptFunctionID, Input);
            else if (isConstant(Input) == true)
                TempStringPair = std::make_pair(ConstantID, Input);
            else if (isNumber(Input) == true)
                TempStringPair = std::make_pair(NumberID, Input);
            else if (isArgument(Input) == true)
                TempStringPair = std::make_pair(VariableID, Input);
            else
                TempStringPair = std::make_pair(InvalidStringID, Input);
            return TempStringPair;
        }
    };
    typedef class CustomTokenUnitIDCreation CustomTokenUnitIDCreation;
}

#endif

// int main()
// {
// }