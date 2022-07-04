/**
 * @file ExpressionStringStorage.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_STRING_STORAGE_H
#define EXPRESSION_STRING_STORAGE_H

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"

// ExpressionManagement namespace control all the operations related to expression exploitation
namespace ExpressionManagement
{
    /**
     * @brief ExpressionStringStorage process primary operations to expression strings
     * @brief RemoveUnaryOperator removes only two unary operators '+' and '-' in case of positive number,
     * @brief for instance +3/4 or negative number after parentheses like (-3 + 4)
     */
    class ExpressionStringStorage
    {
    private:
        std::string ExpressionInputInitial;
        std::string ExpressionInputNoBlank;

        void RemoveUnaryOperator();

    protected:
        void ExpressionStringStorageInputAPI(std::string);

    public:
        std::string OutputExpressionInitial();
        std::string OutputExpressionNoBlank();
    };
    typedef class ExpressionStringStorage ExpressionStringStorage;
}

#endif
