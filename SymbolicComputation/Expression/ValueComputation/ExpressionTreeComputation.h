/**
 * @file ExpressionTreeComputation.h is the
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @brief This file contains a class which will calculate an expression value if we know its arguments values
 * @version 2.0
 * @date 2022-07-01
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_TREE_COMPUTATION_H
#define EXPRESSION_TREE_COMPUTATION_H

#include "../../ExpressionObject/ExpressionTreeObject.h"
#include <limits.h>

namespace ExpressionManagement
{
    class ExpressionTreeComputation : public ExpressionTreeObject
    {
    private:
        CustomTokenUnit ArgumentNameList;
        std::unordered_map<std::string, double> ArgumentValueList;
        double ExpressionValue = 0.0;

        void CreateListOfArgumentName();
        void CreateListOfArgumentValueFromKeyBoard();
        void CreateListOfArgumentValueFromGivenData(std::vector<double>);
        bool IsArgumentExistence(std::string);
        double FindValueFromArgumentName(std::string);

    protected:
    public:
        double OutputExpressionValue();
        std::vector<std::string> OutputArgumentListName();
        std::unordered_map<std::string, double> OutputArgumentListValue();
        void ComputeExpressionValueInitialization(std::string, std::vector<double>, bool);
        double ComputeExpressionValue(std::unordered_map<std::string, double>, TreeExpressionBuildingBlock *);
    };
}

#endif