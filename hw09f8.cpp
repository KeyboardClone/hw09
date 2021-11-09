// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: contains the function definition for our version of strstr() as
// was prototyped within hw09.h
// ============================================================================
#include "hw09.h"



const char *strstr(const char *str1, const char *str2)
{
    // breaking out of this loop indicates that str2 is not within str1 and that we should
    // return a nullptr
    for (size_t i = 0; i <= strlen(str1) - strlen(str2); i++)
    {
        size_t x = 1;
        // being able to enter this loop should only occur if we can find a matching initial
        // character, followed by a matching "next" character that changes with each iteration.
        // additionally, if x ever exceeds the length of str2, then we can guarantee we've found
        // str2 within str1 as that indicates we were not stopped by a failed comparison
        while (str1[i] == str2[0] && str1[i + x] == str2[x])
        {
            x++;
            if (x >= strlen(str2))
                return &str1[i];
        }
    }

    // by default, this function returns a nullptr to indicate that the str2 could not be found within
    // str1
    return nullptr;
}