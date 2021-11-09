// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: contains the function definition for our version of strrev()
// as was prototyped within hw09.h
// ============================================================================
#include "hw09.h"


// performs a strcpy process between src and dest, but in reverse order
void strrev(char *dest, char *src)
{
    // reverse copies the string within src into dest
    for (int i = 0; i < strlen(src); i++)
        dest[i] = src[strlen(src) - (1 + i)];

    return;
}