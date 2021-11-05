// ============================================================================
// File: hw09f2.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
// 
// Description: contains the function definition for testReverse() as was
// prototyped within hw09.h
// ============================================================================
#include "hw09.h"



// if an int value of 1 is thrown, the file failed to open
// if an int value of 2 is thrown, the file input somehow failed to be stored within
//  the my_str object
void testReverse()
{
    std::ifstream in;
    my_str l; // default my_str object, set to ""

    // attempts to open the file and throws an exception if the file fails to open
    try
    {
        in.open("input.txt");
        if (in.fail())
            throw 1;
    }
    catch (int e)
    {
        throw e;
    }

    // attempt to read input from the user, throw an exception if something
    // goes wrong
	try
	{
		in >> l;
		if (in.fail())
			throw 2;
	}
	catch (int e)
	{
        in.close();
		throw e;
	}

	std::cout << copyConstructorTest(l)
		  << " " << l.length() << " "
		  << l.reverse() << std::endl;

    // closes the file
	in.close();

	return;
}

