/**
 * @file GetInsideParentheses.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef GET_INSIDE_PARENTHESES_H
#define GET_INSIDE_PARENTHESES_H

#include "../../BuildingBlock/ExpressionPlainBuildingBlock.h"
#include "IsBalance.h"
namespace ExpressionManagement
{
    std::string GetInsideParentheses(std::string);
    CustomTokenUnit GetInsideParentheses(CustomTokenUnit);
}

#endif