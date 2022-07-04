/**
 * @file IsOperator.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef IS_OPERATOR_H
#define IS_OPERATOR_H

#include "../../BuildingBlock/ExpressionPlainBuildingBlock.h"
namespace ExpressionManagement
{
    bool IsOperator(char);
    bool IsOperator(std::string);
}

#endif