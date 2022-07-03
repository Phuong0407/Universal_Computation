/**
 * @file ExpressionStringDecomposition.cpp is implementation file for ExpressionStringDecomposition.h
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-06-29
 * @copyright Copyright (c) 2022
 */

#include "ExpressionStringDecomposition.h"

/**
 * @brief ExpressionManagement namespace control all the operations related to expression exploitation
 */
namespace ExpressionManagement
{
    /**
     * @brief This is the only one API to process with others object
     * @brief ExpressionStringDecompositionInitialization assigns expression for two class variables
     * @brief First, assign for two strings data, then remove space in second string, then removes unary operators
     * @param ExpressionInputString is the input from keyboard or other sources (develop later)
     */
    void ExpressionStringDecomposition::ExpressionStringDecompositionInitialization(std::string ExpressionInputString)
    {
        this->ExpressionInputInitial = ExpressionInputString;
        this->ExpressionInputNoBlank = ExpressionInputString;
        do
        {
            this->ExpressionInputNoBlank.erase(remove(this->ExpressionInputNoBlank.begin(), this->ExpressionInputNoBlank.end(), ' '), this->ExpressionInputNoBlank.end());
        } while (this->ExpressionInputNoBlank.find(' ') == this->ExpressionInputNoBlank.length());
        this->RemoveUnaryOperator();
    }

    /**
     * @brief RemoveUnaryOperator will help build expression processor easier
     * @brief Where we remove special cases of unary operators like -3 + 4 or + 1 - 3
     * @brief We only insert 0, this will help build expression tree later by avoiding
     */
    void ExpressionStringDecomposition::RemoveUnaryOperator()
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

    std::string ExpressionStringDecomposition::OutputExpressionInitial()
    {
        return this->ExpressionInputInitial;
    }

    std::string ExpressionStringDecomposition::OutputExpressionNoBlank()
    {
        return this->ExpressionInputNoBlank;
    }
}