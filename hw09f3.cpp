// ============================================================================
// File: hw09f3.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: contains the function definition for testIndexOf() as was
// prototyped within hw09.h
// ============================================================================
#include "hw09.h"


void testIndexOf()
{
    my_str userInput, searchForStr;
    char searchForC;
    int index;

    // prompt the user for a c-string to store within userInput
    try
    {
        std::cout << "Enter a string: ";
        std::cin >> userInput;

        if (std::cin.fail())
            throw 3;
        if (userInput == "")
            throw 4;
    }
    catch(int e)
    {
        throw e;
    }

    // prompt the user for a character to search for within userInput
    try
    {
        std::cout << "Enter a character to search for in \"" << userInput << "\": ";
        std::cin >> searchForC;

        if (std::cin.fail())
            throw 5;
    }
    catch(int e)
    {
        throw e;
    }

    // clear the input for the next cin call since it uses getline() within my_str
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    // determine the index of searchForC within userInput
    index = userInput.indexOf(searchForC);

    // display the results of the search
    if (index != -1)
        std::cout << "\'" << searchForC << "\' found at index " << index << std::endl;
    else
        std::cout << "\'" << searchForC << "\' is not within \"" << userInput << "\"" << std::endl;

    // prompt the user with a string to search for within userInput
    try
    {
        std::cout << "Enter a string to search for in \"" << userInput << "\": ";
        std::cin >> searchForStr;

        if (std::cin.fail())
            throw 3;
        if (searchForStr == "")
            throw 4;
    }
    catch(int e)
    {
        throw e;
    }

    // determine what the index of searchForStr is within userInput
    index = userInput.indexOf(searchForStr);

    if (index != -1)
        std::cout << "\"" << searchForStr << "\" found at index " << index << std::endl;
    else
        std::cout << "\"" << searchForStr << "\" not found in \"" << userInput << "\"" << std::endl;

    return;
}