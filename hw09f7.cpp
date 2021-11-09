// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: contains the function definition for our version of strdup()
// as prototyped within hw09.h
// ============================================================================
#include "hw09.h"



// dynamically allocates a c-string within memory
char *strdup(const char* s)
{
    char *newStr = (char *)malloc(strlen(s) + 1);
    strcpy(newStr, s);
    return newStr;
}