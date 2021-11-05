// ============================================================================
// File: hw09f5.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: contains the function definition for testCompare() as was
// prototyped within hw09.h
// ============================================================================
#include "hw09.h"



void testCompare()
{
    my_str str1, str2;

    // attempt to retrieve 2 strings from the user for comparison, throwing
    // error codes as necessary
    try
    {
        std::cout << "Enter str1: ";
        std::cin >> str1;

        if (std::cin.fail())
            throw 6;
        if (str1 == "")
            throw 7;

        std::cout << "Enter str2: ";
        std::cin >> str2;

        if (std::cin.fail())
            throw 6;
        if (str2 == "")
            throw 7;
    }
    catch (int e)
    {
        throw e;
    }

    // display the results of performing the comparison
    std::cout << "\"" << str1 << "\"";
    if (str1 == str2)
        std::cout << " == ";
    else
        std::cout << " != ";
    std::cout << "\"" << str2 << "\"" << std::endl;

    return;
}