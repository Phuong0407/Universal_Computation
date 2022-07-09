/**
 * @file ExpressionCompleteComputation.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-08
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_COMPLETE_COMPUTATION_H
#define EXPRESSION_COMPLETE_COMPUTATION_H

#include "ExpressionTree.h"

namespace ExpressionManagement
{
    /**
     * @brief Class ExpressionCompleteComputation inherits from ExpressionTree, it computes expression from an expression string.
     * @brief API: ExpressionComputationCompleteInputAPI() gets input string to compute.
     * @brief API: ComputeExpression() return double as result.
     */
    class ExpressionCompleteComputation : public ExpressionTree
    {
    public:
        void ExpressionComputationCompleteInputAPI(std::string);
        double ComputeExpression();
    };
    typedef class ExpressionCompleteComputation ExpressionCompleteComputation;

    /**
     * @brief Gets input string to compute.
     * @param StringExpressionInput 
     */
    void ExpressionCompleteComputation::ExpressionComputationCompleteInputAPI(std::string StringExpressionInput)
    {
        this->TreeExpressionInputAPI(StringExpressionInput);
    }

    /**
     * @brief Using ComputeExpressionValue(), a method built-in to compute only for expression tree without undefined operands (argument without value)!
     * @return double as result.
     */
    double ExpressionCompleteComputation::ComputeExpression()
    {
        return ComputeExpressionValue(this->OutputExpressionTreeRoot());
    }
}

#endif