// ============================================================================
// File: hw09f11.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: Defines the str2dup() function as prototyped within hw09.h
// ============================================================================
#include "hw09.h"



// returns a dynamically allocated string that is a concatenation of str1 and str2
char *str2dup(const char *str1, const char *str2)
{
    char newCatStr[strlen(str1) + strlen(str2)];

    // the following ifs with regards to nullptrs exist to handle scenarios where
    // either str1 or str2 point to null, in which case call that's copied into the strings
    // are ""
    if (str1 == nullptr)
        strcpy(newCatStr, "");
    else
        strcpy(newCatStr, str1);

    if (str2 == nullptr)
        strcat(newCatStr, str2);
    else
        strcat(newCatStr, str2);

    // returns a dynamically allocated c-string of the concatenated strings
    return strdup(newCatStr);
}