/**
 * @file ExpressionTreeComputationAuxiliaryMethod.h is the header file derive from ExpressionBuildingBlock.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief This file contains auxiliary methods to calculate
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 */

/**
 * @brief ExpressionManagement namespace control all the operations related to expression exploitation
 */
#pragma once
#ifndef EXPRESSION_TREE_COMPUTATION_AUXILIARY_METHOD_H
#define EXPRESSION_TREE_COMPUTATION_AUXILIARY_METHOD_H

#include "ExpressionBuildingBlock.h"

/**
 * @brief ExpressionManagement namespace control all the operations related to expression exploitation
 * @brief This file contains method to check if a string is a proper number, convert this string to double, and a compute the function value
 */
namespace ExpressionManagement
{
    double NumberStringToDouble(std::string);
    double BuiltInFunctionsComputation(double, std::string);
}

#endif