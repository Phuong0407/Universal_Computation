/**
 * @file StringToInfixConversion.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-13
 * @copyright Copyright (c) 2022
 */

#ifndef IS_INFIX_CONVERSION_METHOD_H
#define IS_INFIX_CONVERSION_METHOD_H

#include "../AuxiliaryMethod/ADCustomTokenCreationID.h"
#include "../AuxiliaryMethod/ADInsideBracketExtraction.h"

namespace Expression
{
    class StringToInfixConversion
    {
    private:
        static const int NonBuiltInFunctionID = 0;
        static const int BuiltInFunctionBracketRequiredID = 2;

    public:
        static char extractFirstCharacter(std::string &Input, int ReducedStringSize = 0)
        {
            if (Input.length() == 0)
                throw std::runtime_error("Input string is empty!");
            char FirstCharacter = Input[0];
            if (ReducedStringSize != 0)
            {
                if (Input.length() > 1)
                    Input = Input.substr(1, Input.length());
                else if (Input.length() == 1)
                    Input = "";
            }
            return FirstCharacter;
        }

        static std::string extractGeneralOperand(std::string &Input)
        {
            std::string GeneralOperand = "";
            for (std::size_t i = 0; i < Input.length(); i++)
                if (CustomTokenUnitIDCreation::isGeneralOperand(Input[i]) == true)
                    GeneralOperand += Input[i];
                else
                    break;
            Input = Input.substr(GeneralOperand.length(), Input.length());
            return GeneralOperand;
        }

        static std::string createBuiltInFunctionSquareBracket(std::string FunctionNotation, std::string FinalSquareWrappedExpression)
        {
            if (CustomTokenUnitIDCreation::isBuiltInFunction(FunctionNotation) != 2)
                throw std::runtime_error("Wrong in algorithm!");
            FunctionNotation += "[";
            FunctionNotation += FinalSquareWrappedExpression;
            return FunctionNotation;
        }

    public:
        static CustomTokenExpression decomposeStringToInfix(std::string ExpressionStringNoBlank, int CompleteDecomposition = 0)
        {
            char ExpressionScanner;
            CustomTokenExpression InfixExpression;
            while (ExpressionStringNoBlank.length() > 0)
            {
                ExpressionScanner = extractFirstCharacter(ExpressionStringNoBlank);
                if (CustomTokenUnitIDCreation::isGeneralOperand(ExpressionScanner) == true)
                {
                    std::string GeneralOperand = extractGeneralOperand(ExpressionStringNoBlank);
                    if (ExpressionStringNoBlank.length() != 0)
                        ExpressionScanner = extractFirstCharacter(ExpressionStringNoBlank);
                    if (CustomTokenUnitIDCreation::isBuiltInFunction(GeneralOperand) == BuiltInFunctionBracketRequiredID && ExpressionScanner == '[')
                    {
                        extractFirstCharacter(ExpressionStringNoBlank, 1);
                        std::string InsideSquareBracket = StringInsideBracketExtraction::extractInsideBracket(ExpressionStringNoBlank, "[");
                        GeneralOperand = createBuiltInFunctionSquareBracket(GeneralOperand, InsideSquareBracket);
                    }
                    InfixExpression.push_back(CustomTokenUnitIDCreation::createExpressionUnitID(GeneralOperand));
                    CustomTokenExpression SubExpressionCustomToken = decomposeStringToInfix(ExpressionStringNoBlank);
                    InfixExpression.insert(InfixExpression.end(), SubExpressionCustomToken.begin(), SubExpressionCustomToken.end());
                    ExpressionStringNoBlank = "";
                }
                if (ExpressionStringNoBlank.length() != 0)
                {
                    ExpressionScanner = extractFirstCharacter(ExpressionStringNoBlank, 1);
                    std::string InfixExpressionBuilder = "";
                    InfixExpressionBuilder += ExpressionScanner;
                    CustomToken InfixExpressionUnit = CustomTokenUnitIDCreation::createExpressionUnitID(InfixExpressionBuilder);
                    if (InfixExpressionUnit.first == LeftRoundBracketID || InfixExpressionUnit.first == LeftSquareBracketID)
                    {
                        InfixExpression.push_back(InfixExpressionUnit);
                        std::string InsideBracketExpression = StringInsideBracketExtraction::extractInsideBracket(ExpressionStringNoBlank, InfixExpressionUnit.second);
                        CustomTokenExpression InsideBracketCustomToken = decomposeStringToInfix(InsideBracketExpression);
                        InfixExpression.insert(InfixExpression.end(), InsideBracketCustomToken.begin(), InsideBracketCustomToken.end());
                        CustomTokenExpression RemainedExpressionInfix = decomposeStringToInfix(ExpressionStringNoBlank);
                        InfixExpression.insert(InfixExpression.end(), RemainedExpressionInfix.begin(), RemainedExpressionInfix.end());
                        ExpressionStringNoBlank = "";
                    }
                    else if (InfixExpressionUnit.first == RightRoundBracketID || InfixExpressionUnit.first == RightSquareBracketID)
                        InfixExpression.push_back(InfixExpressionUnit);
                    else if (InfixExpressionUnit.first >= PowerOperatorID && InfixExpressionUnit.first <= AddSubOperatorID)
                    {
                        InfixExpression.push_back(InfixExpressionUnit);
                        CustomTokenExpression RemainedExpressionInfix = decomposeStringToInfix(ExpressionStringNoBlank);
                        InfixExpression.insert(InfixExpression.end(), RemainedExpressionInfix.begin(), RemainedExpressionInfix.end());
                        ExpressionStringNoBlank = "";
                    }
                    else
                        throw std::runtime_error("Invalid expression!");
                }
            }
            return InfixExpression;
        }

        static CustomTokenExpression createCompleteFormInfix(CustomTokenExpression ExpressionInfix)
        {
            std::size_t i = 0;
            while (i < ExpressionInfix.size())
            {
                CustomToken MulOperatorUnit = CustomTokenUnitIDCreation::createExpressionUnitID("*");
                if (ExpressionInfix[i].first == RightRoundBracketID && ExpressionInfix[i + 1].first == LeftRoundBracketID)
                    ExpressionInfix.insert(ExpressionInfix.begin() + i + 1, MulOperatorUnit);
                else if (ExpressionInfix[i].first == VariableID && ExpressionInfix[i + 1].first == LeftRoundBracketID)
                    ExpressionInfix.insert(ExpressionInfix.begin() + i + 1, MulOperatorUnit);
                else if (ExpressionInfix[i].first == ConstantID && ExpressionInfix[i + 1].first == LeftRoundBracketID)
                    ExpressionInfix.insert(ExpressionInfix.begin() + i + 1, MulOperatorUnit);
                else if (ExpressionInfix[i].first == NumberID && ExpressionInfix[i + 1].first == LeftRoundBracketID)
                    ExpressionInfix.insert(ExpressionInfix.begin() + i + 1, MulOperatorUnit);
                else if (ExpressionInfix[i].first == RightRoundBracketID && ExpressionInfix[i + 1].first == VariableID)
                    ExpressionInfix.insert(ExpressionInfix.begin() + i + 1, MulOperatorUnit);
                else if (ExpressionInfix[i].first == RightRoundBracketID && ExpressionInfix[i + 1].first == NumberID)
                    ExpressionInfix.insert(ExpressionInfix.begin() + i + 1, MulOperatorUnit);
                else if (ExpressionInfix[i].first == RightRoundBracketID && ExpressionInfix[i + 1].first == ConstantID)
                    ExpressionInfix.insert(ExpressionInfix.begin() + i + 1, MulOperatorUnit);
                i++;
            }
            return ExpressionInfix;
        }
    };
    typedef class StringToInfixConversion StringToInfixConversion;
}
#endif

// using namespace std;
// using namespace Expression;
// int main()
// {
//     string s = "sin((x-2)(x-3))a";
//     // std::getline(std::cin, s);
//     CustomTokenExpression a = StringToInfixConversion::decomposeStringToInfix(s);
//     for (int i = 0; i < a.size(); i++)
//         cout << a[i].second;
//     cout << endl;
//     a = StringToInfixConversion ::createCompleteFormInfix(a);
//     cout << a.size();
//     for (int i = 0; i < a.size(); i++)
//         cout << a[i].second;
//     // for (int i = 0; i < s.size(); i++)
//     //     cout << s[i];
// }