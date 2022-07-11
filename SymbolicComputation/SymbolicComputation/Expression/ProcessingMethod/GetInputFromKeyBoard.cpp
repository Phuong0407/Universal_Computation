/**
 * @file GetInputFromKeyBoard.cpp
 * @author Phuong Diep Thanh (diepthanhphuong0407@gmail.com)
 * @version 2.0
 * @date 2022-07-08
 * @copyright Copyright (c) 2022
 */

#pragma once
#ifndef GET_INPUT_FROM_KEYBOARD_CPP
#define GET_INPUT_FROM_KEYBOARD_CPP

#include "../BuildingBlock/ExpressionPlainBuildingBlock.h"

namespace ExpressionManagement
{
    /**
     * @brief Gets subexpression string from keyboard
     * @param ArgumentName string to get subexpression
     * @return ArgumentStringUnit as a pair of (argument name, argument substring)
     */
    ArgumentStringUnit GetInputFromKeyBoard(std::string ArgumentName)
    {
        std::string ArgumentNameScanner;
        std::cout << "     Enter value for argument " << ArgumentName << " = ";
        std::getline(std::cin, ArgumentNameScanner);
        ArgumentStringUnit ArgumentNameBuilder = std::make_pair(ArgumentName, ArgumentNameScanner);
        return ArgumentNameBuilder;
    }
}
#endif