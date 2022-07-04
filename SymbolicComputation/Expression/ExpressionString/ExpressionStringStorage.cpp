/**
 * @file ExpressionStringStorage.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-06-29
 * @copyright Copyright (c) 2022
 */
#pragma once
#ifndef EXPRESSION_STRING_STORAGE_CPP
#define EXPRESSION_STRING_STORAGE_CPP

#include "ExpressionStringStorage.h"

namespace ExpressionManagement
{
    /**
     * @brief This is the only one API to process with others object
     * @brief ExpressionStringStorageInputAPI assigns expression for two class variables
     * @brief First, assign for two strings data, then remove space in second string, then removes unary operators
     * @param ExpressionInputString is the input from keyboard or other sources (develop later)
     */
    void ExpressionStringStorage::ExpressionStringStorageInputAPI(std::string ExpressionInputString)
    {
        this->ExpressionInputInitial = ExpressionInputString;
        do
        {
            ExpressionInputString.erase(remove(ExpressionInputString.begin(), ExpressionInputString.end(), ' '), ExpressionInputString.end());
        } while (ExpressionInputString.find(' ') == ExpressionInputString.length());
        this->ExpressionInputNoBlank = ExpressionInputString;
        this->RemoveUnaryOperator();
    }

    /**
     * @brief RemoveUnaryOperator will help build expression processor easier
     * @brief Where we remove special cases of unary operators like -3 + 4 or + 1 - 3
     * @brief We only insert 0, this will help build expression tree later by avoiding
     */
    void ExpressionStringStorage::RemoveUnaryOperator()
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

    std::string ExpressionStringStorage::OutputExpressionInitial()
    {
        return this->ExpressionInputInitial;
    }

    std::string ExpressionStringStorage::OutputExpressionNoBlank()
    {
        return this->ExpressionInputNoBlank;
    }
}
#endif