/**
 * @file ExpressionStringObject.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-03
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_STRING_OBJECT_H
#define EXPRESSION_STRING_OBJECT_H

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief ExpressionStringStorage process primary operations to expression strings
     * @brief RemoveUnaryOperator removes only two unary operators '+' and '-' in case of positive number,
     * @brief for instance +3/4 or negative number after parentheses like (-3 + 4)
     */
    class ExpressionStringObject
    {
    private:
        std::string ExpressionInputInitial;
        std::string ExpressionInputNoBlank;

    protected:
        void RemoveUnaryOperator();
        std::string OutputExpressionInitial();
        std::string OutputExpressionNoBlank();
        void ExpressionStringObjectInputAPI(std::string);
    };
    typedef class ExpressionStringObject ExpressionStringObject;

    void ExpressionStringObject::RemoveUnaryOperator()
    {
        if (this->ExpressionInputNoBlank[0] == '+' || this->ExpressionInputNoBlank[0] == '-')
        {
            std::string TempStringInsert = "";
            TempStringInsert += '0';
            TempStringInsert += this->ExpressionInputNoBlank;
            this->ExpressionInputNoBlank.assign(TempStringInsert);
        }
        for (unsigned int i = 0; i < this->ExpressionInputNoBlank.length(); ++i)
            if (this->ExpressionInputNoBlank[i] == '(' && (this->ExpressionInputNoBlank[i + 1] == '+' || this->ExpressionInputNoBlank[i + 1] == '-'))
                this->ExpressionInputNoBlank.insert(i + 1, "0");
    }

    std::string ExpressionStringObject::OutputExpressionInitial()
    {
        return this->ExpressionInputInitial;
    }

    std::string ExpressionStringObject::OutputExpressionNoBlank()
    {
        return this->ExpressionInputNoBlank;
    }

    void ExpressionStringObject::ExpressionStringObjectInputAPI(std::string ExpressionStringInput)
    {
        this->ExpressionInputInitial = ExpressionStringInput;
        do
        {
            ExpressionStringInput.erase(remove(ExpressionStringInput.begin(), ExpressionStringInput.end(), ' '), ExpressionStringInput.end());
        } while (ExpressionStringInput.find(' ') == ExpressionStringInput.length());
        this->ExpressionInputNoBlank = ExpressionStringInput;
        this->RemoveUnaryOperator();
    }
}
#endif