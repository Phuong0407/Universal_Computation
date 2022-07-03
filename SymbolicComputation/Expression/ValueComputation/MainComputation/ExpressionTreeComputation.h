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

#include "ExpressionTreeConstruction.h"
#include "ExpressionTreeComputationAuxiliaryMethod.h"
#include <limits.h>

/**
 * @brief ExpressionManagement namespace control all the operations related to expression exploitation
 * @brief Class ExpressionTreeComputation derives public from TreeExpressionConstruction
 * @brief In this class, we provides two parameters, ArgumentNameList and ArgumentValueList
 * @brief The first one is use for manipulating argument name
 * @brief The second is to put argument name and argument value
 * @brief We use unordered_map to improve search time
 * @brief We provides two API methods, that are ComputeExpressionValuesInitialization
 * @brief That builds expression tree and start CreateListOfArgumentsName() to create argument name
 * @brief CreateListOfArgumentValue...() is used depending on further development
 * @brief IsValidExpression() is used here, not at the ExpressionStringDecomposition.h because we want to reduce number of initialization if the expression is not valid
 */
namespace ExpressionManagement
{
    class ExpressionTreeComputation : public TreeExpressionConstruction
    {
    private:
        std::vector<std::string> ArgumentNameList;
        std::unordered_map<std::string, double> ArgumentValueList;
        double ExpressionValue = 0.0;

        bool IsValidExpression(std::string);
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