// ============================================================================
// File: hw09f3.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: contains the function definition for testConcat() as was
// prototyped within hw09.h
// ============================================================================
#include "hw09.h"



void testConcat()
{
    my_str firstStr("abc");
    my_str secStr("def");
    my_str newStr;

    std::cout << "firstStr = " << firstStr << std::endl;
    std::cout << "secStr = " << secStr << std::endl;

    // concatenates firstStr and secStr into a new c-string, giving the value to newStr
    newStr = firstStr + secStr;

    std::cout << "newStr = firstStr + secStr => " << newStr << std::endl;

    newStr += firstStr;
    std::cout << "newStr += firstStr => " << newStr << std::endl;

    return;
}