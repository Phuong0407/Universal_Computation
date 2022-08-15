/**
 * @file ExpressionEntity.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-21
 * @copyright Copyright (c) 2022
 */

/**
 * Store all the entities for expression manipulation.
 * Entities for expressions are operands (numbers, constants, and variables), operators (+ - * / ^), built-in functions and brackets (round, square).
 * Built-in functions have two kinds, base and no base. Base built-in functions are functions with additional parameter:
 * + trigonometry[deg/rad](expression) used to compute trigonometric functions in unit of degree/radian (radian can be omitted by default).
 * + logarithm[expression_base](expression) used to compute logarithm functions with expression_base value (must have positive value) (logarithm of base 10 can be omitted by default).
 * + sqrt[expression_base](expression) used to compute root of order of expression_base (root of order two, square root, can be omitted by default).
 * Expression can be grouped by round brackets pair to emphasize order of computation, we only accept round brackets, square brackets are used only for additional parameter of built-in functions.
 * Numbers are represent by default mathematical form (ex: -0.123056789) or scientific form (ex: -1.2343434E-8, E is capitalized only).
 * Arguments of expression are case-sensitive, it contains only alphabet and underscore, for example, A1 is invalid.
 * String name are the set of variables, constants and built-in functions (which contains just alphabets and underscores).
 * We do not accepts most kind of multiplication sign omitted. Just the following cases are allowed:
 * + Number-function. Entity-left round bracket. Right round bracket-entity. Right round bracket-left round bracket.
 * + The other cases if processed will slow down the performance too much.
 * + The patters 3x are not recognized as 3*x but as a unique 3x.
 */

#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <tuple>
#include <ctype.h>
#include <utility>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

namespace Expression
{

    // Store all the number character for normal number checker.
    static const std::unordered_set<char> NormalNumberNotation = {
        '+',
        '-',
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        '.',
    };

    // Store all the number character for scientific number checker.
    static const std::unordered_set<char> ScientificNumberNotation = {
        '+',
        '-',
        '0',
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9',
        '.',
        'E',
    };

    // Store all the built-in functions without base symbols in string.
    const std::unordered_set<std::string> NoBaseBuiltInFunction = {
        "abs",
        "ln",
        "sinh",
        "cosh",
        "tanh",
        "coth",
        "argsinh",
        "argcosh",
        "argtanh",
        "argcoth",
    };

    // Store all the built-in functions with base symbols in string.
    // Base are base of logarithms, unit of trigonometric functions, order of root.
    const std::unordered_set<std::string> BaseBuiltInFunction = {
        "log",
        "sqrt",
        "sin",
        "cos",
        "tan",
        "cotan",
        "arcsin",
        "arccos",
        "arctan",
        "arccotan",
    };

    // Store all the constants for calculation.
    // Constant are unit of trigonometric function (rad and deg), pi, e, and 40 physical constants.
    const std::unordered_map<std::string, double> UniversalConstant = {
        {"rad", 1.0},
        {"deg", 3.1415926535897932384626433832795028841972 / 180.0},
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
}

#endif