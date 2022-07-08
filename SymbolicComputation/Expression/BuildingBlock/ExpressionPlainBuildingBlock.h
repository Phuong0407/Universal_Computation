/**
 * @file ExpressionBuildingBlock.h is header file for plain expression structures
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief Building block file from that we call all predefined data structure to process plain expression (in string form)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_BUILDING_BLOCK_H
#define EXPRESSION_BUILDING_BLOCK_H

#include <cmath>
#include <tuple>
#include <stack>
#include <cctype>
#include <locale>
#include <vector>
#include <string>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>

// Custom unit to build plain expression
typedef std::vector<std::string> CustomTokenUnit;

//  Custom unit to compute expression
typedef std::pair<std::string, double> ArgumentValueUnit;

// Custom unit for subexpression get method
typedef std::pair<std::string, std::string> ArgumentStringUnit;

// Built-in functions contains absolute value, logarithm, trigonometry functions, hyperbolic functions, square root
// More built-in functions will be add later
std::unordered_set<std::string> BuiltInFunctions{
    "abs",

    "log",
    "ln",

    "sin",
    "cos",
    "tan",
    "cotan",
    "arcsin",
    "arccos",
    "arctan",
    "arccotan",

    "sinh",
    "cosh",
    "tanh",
    "coth",
    "argsinh",
    "argcosh",
    "argtanh",
    "argcoth",

    "sqrt",
};

// Constant contains 40 important physical constants, more constants will be added later
std::unordered_map<std::string, double> Constant = {
    {"pi", 3.1415926535897932384626433832795028841972},
    {"e", 2.7182818284590452353602874713526624977572},

    {"mp", 1.672621637e-27},
    {"mn", 1.674927211e-27},
    {"me", 9.01938215e-31},
    {"mm", 1.8835313e-28},
    {"a0", 5.291772086e-11},
    {"planck", 6.62607004e-34},
    {"nucMag", 5.05078324e-27},
    {"boMag", 927.400915e-26},
    {"dirac", 1.054571629e-34},
    {"fineStruct", 7.2973525376e-3},

    {"elRadi", 2.8179402894e-15},
    {"CompLength", 2.4263102175e-12},
    {"ProGyrRatio", 2.675222099e8},
    {"ProCompWaveLength", 1.321409845e-15},
    {"NeuCompWaveLength", 1.319590907e-15},
    {"RydConst", 10973731.568528},
    {"MassUnit", 1.660538782e-27},
    {"ProMagMom", 1.410606662e-26},
    {"ElMagMom", -928.476377e-26},
    {"NeuMagMom", -0.96623641e-26},

    {"MuonMagMom", -4.49044786e-26},
    {"Faraday", 96485.3329},
    {"EleCharge", 1.602176487e-19},
    {"Na", 6.0221412927e23},
    {"k", 1.38064852e-23},
    {"Vm", 0.022413996},
    {"R", 8.314472},
    {"LightSpeed", 299792458},
    {"FirstRadiConst", 3.74177118e-16},
    {"SecondRadiConst", 0.014387752},

    {"StefanBoltz", 5.670373e-8},
    {"VaPermit", 8.854187817e-12},
    {"VaPerm", 1.2566370621219e-6},
    {"MagFluxQuantum", 2.067833848e-15},
    {"GraAcc", 9.90665},
    {"VaCond", 7.748091729e-5},
    {"AbsTemp", 273.15},
    {"GraConst", 6.67428e-11},
    {"Atm", 101325},
    {"CharImpVa", 376.7303135},
};

/**
 * @brief VectorReplacer() is the method to replace a unit of an infix vector with another infix vector
 * @param InfixToReplace the vector to replace a unit,
 * @param NameToCheck the unit to be replaced
 * @param InfixReplacer the replacer
 * @return CustomTokenUnit
 */
void VectorReplacer(CustomTokenUnit &InfixToReplace, std::string NameToReplace, CustomTokenUnit InfixReplacer)
{
    unsigned int Index = 0;
    do
    {
        if (InfixToReplace[Index] == NameToReplace)
        {
            InfixToReplace.insert(InfixToReplace.begin() + Index, InfixReplacer.begin(), InfixReplacer.end());
            Index += InfixReplacer.size();
            InfixToReplace.erase(InfixToReplace.begin() + Index);
        }
        else
            Index++;
    } while (Index < InfixToReplace.size());
}

/**
 * @brief RemoveIdenticalElement() will remove all the identical unit in an CustomTokenUnit input, and
 * @brief only works for argument name list.
 * @brief It keeps only one unit of any unit.
 * @param Input pass by reference
 * @return CustomTokenUnit
 */
void RemoveIdenticalElement(CustomTokenUnit &Input)
{
    CustomTokenUnit::iterator Scanner = Input.begin();
    std::unordered_set<std::string> TokenStorageUnit;
    for (auto CurrentPosition = Input.begin(); CurrentPosition != Input.end(); ++CurrentPosition)
        if (TokenStorageUnit.insert(*CurrentPosition).second)
            *Scanner++ = *CurrentPosition;
    Input.erase(Scanner, Input.end());
}
#endif