/**
 * @file IsBalance.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 0.1
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef IS_BALANCED_H
#define IS_BALANCED_H

#include "../../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    bool IsBalance(std::string);
    bool IsBalance(CustomTokenUnit);
}

#endif