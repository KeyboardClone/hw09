// ============================================================================
// File: hw09f6.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: contains the function definition for testIndexAccess() as was
// prototyped within hw09.h
// ============================================================================
#include "hw09.h"



void testIndexAccess()
{
    my_str someStr("A random String");
    int indexInput;

    // retrieve an index from the user to access the contents of "A random String"
    // throws exceptions for main to handle as necessary
    try
    {
        std::cout << "Enter an index to access within the string \"" << someStr << "\": ";
        std::cin >> indexInput;

        if (std::cin.fail())
            throw 8;

        char charAtIndex = someStr[indexInput];
        std::cout << "The character at index " << indexInput << " is \'" << charAtIndex << "\'" << std::endl;
    }
    catch (int e)
    {
        throw e;
    }
    catch(std::out_of_range &e)
    {
        throw 9;
    }

    return;
}