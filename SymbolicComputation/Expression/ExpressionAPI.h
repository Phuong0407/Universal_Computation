/**
 * @file ExpressionAPI.h
 * @author THANH PHUONG DIEP (diepthanhphuong0407@gmail.com)
 * @version 3.0
 * @date 2022-07-21
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef EXPRESSION_API_H
#define EXPRESSION_API_H

#include "ExpressionObject/ExpressionObjectStorage.h"

namespace Expression
{
    double ExpressionComputationAPI(std::string ExpressionInput)
    {
        ExpressionObjectStorage E;
        E.ExpressionObjectStorageInputAPI(ExpressionInput);
        return E.computeExpression();
    }
}

#endif

// int main()
// {
// }