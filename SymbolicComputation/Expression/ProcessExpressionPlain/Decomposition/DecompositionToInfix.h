/**
 * @file Decomposition.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef DECOMPOSITION_TO_INFIX_H
#define DECOMPOSITION_TO_INFIX_H

#include "../../ProcessExpressionPlain/AuxiliaryMethod/DecompositionAuxiliaryMethodAPI.cpp"

namespace ExpressionManagement
{
    CustomTokenUnit DecompositionToInfixCustomToken(std::string);
}
#endif