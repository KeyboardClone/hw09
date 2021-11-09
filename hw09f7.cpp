// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: contains the function definition for our version of strdup()
// as prototyped within hw09.h
// ============================================================================
#include "hw09.h"



// dynamically allocates a c-string within memory based on the non-dynamic c-string
// passed into the function's parameters
char *strdup(const char* s)
{
    // reserves enough space within the freestore/heap for newStr to point to
    char *newStr = (char *)malloc(strlen(s) + 1);
    // copies s into newStr's memory location
    strcpy(newStr, s);
    // returns the pointer to the newStr
    return newStr;
}