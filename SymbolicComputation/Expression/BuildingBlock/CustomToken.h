/**
 * @file CustomToken.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-21
 * @copyright Copyright (c) 2022
 */

/**
 * StringExpression stores an expression as a set of entities (ExpressionEntity.h) without entity ID (used only for convert from string expression to infix expression).
 * CustomTokenExpression stores an expression as a set of entities with IDs:
 * + ID for operators is its priority order (used for convert from infix to postfix), then multiplication and division has the same ID (the same argument applied for addition and subtraction)
 * + ID for built-in functions is its type (without additional parameter, and  with addition parameter).
 * + ID for numbers, constants are the same for all of those (just to reduce checking method calling-time).
 * + ID for brackets are four value for left-right and square-round.
 * + Invalid entity has ID 0, if we found it, we will throw exception and send message to re-enter expression again.
 * ValuedArgument stores value of argument for tree computation.
 */

#pragma once
#ifndef CUSTOM_TOKEN_H
#define CUSTOM_TOKEN_H

#include <tuple>
#include <vector>
#include <utility>
#include <cstring>
#include <iostream>

namespace Expression
{
    // Define an expression in an array (vector) of string (no ID)
    typedef std::vector<std::string> StringExpression;

    // Define a token unit, int is ID and std::string is name
    typedef std::pair<int, std::string> CustomToken;

    // Define an expression in CustomToken (ID specified)
    typedef std::vector<CustomToken> CustomTokenExpression;

    // Define a unit for arguments, std::string is name, double is value
    typedef std::pair<std::string, double> ValuedArgumentUnit;

    // Define an array (vector) of argument, used to compute tree expression
    typedef std::vector<ValuedArgumentUnit> ValuedArgument;

    const int PowerOperatorID = 0;
    const int MulDivOperatorID = 1;
    const int AddSubOperatorID = 2;
    const int LeftRoundBracketID = 3;
    const int RightRoundBracketID = 4;
    const int LeftSquareBracketID = 5;
    const int RightSquareBracketID = 6;
    const int NoBaseFunctionID = 7;
    const int BaseFunctionID = 8;
    const int NormalNumberID = 9;
    const int ScientificNumberID = 10;
    const int ConstantID = 11;
    const int VariableID = 12;
}

#endif