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
    class ExpressionCompleteComputation : public ExpressionTree
    {
    private:
    public:
        void ExpressionComputationCompleteInputAPI(std::string);
        double ComputeExpression();
    };
    typedef class ExpressionCompleteComputation ExpressionCompleteComputation;

    void ExpressionCompleteComputation::ExpressionComputationCompleteInputAPI(std::string StringExpressionInput)
    {
        this->TreeExpressionInputAPI(StringExpressionInput);
    }

    double ExpressionCompleteComputation::ComputeExpression()
    {
        return ComputeExpressionValue(this->OutputExpressionTreeRoot());
    }
}

#endif