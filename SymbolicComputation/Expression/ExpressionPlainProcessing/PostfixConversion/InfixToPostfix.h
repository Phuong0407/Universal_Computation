/**
 * @file InfixToPostfix.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-04
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef INFIX_TO_POSTFIX_CONVERSION_H
#define INFIX_TO_POSTFIX_CONVERSION_H

#include "../../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "../AuxiliaryMethod/DecompositionAuxiliaryMethodAPI.cpp"
namespace ExpressionManagement
{
    CustomTokenUnit InfixToPostfixConversion(CustomTokenUnit);
}

#endif