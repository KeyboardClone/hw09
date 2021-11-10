// ============================================================================
// File: hw09f10.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: Defines the strcmp() function as prototyped within hw09.h
// ============================================================================
#include "hw09.h"



int strcmp(const char* str1, const char* str2)
{
    // if str1 and str2 differ in length somehow, we immediately know that
    // the comparison will not evaluate to true and can short circuit the process
    // with these if statements
    if (strlen(str1) < strlen(str2))
        return -(int)str2[strlen(str1) - 1];

    if (strlen(str1) > strlen(str2))
        return (int)str1[strlen(str2) - 1];

    int index = 0;

    // continue to search through each string so long as they have equivalent characters, if
    // they don't somewhere this loop ends
    while (str1[index] == str2[index])
    {
        index++;
        // if index is able to scroll through both c-strings without
        // encountering a non-matching character, then both of the strings
        // are matching
        if (index >= strlen(str1))
            return 0;
    }

    // returns the difference between str1[index] and str2[index]
    return (int)str1[index] - (int)str2[index];
}