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



void testReverse()
{
	std::ifstream in("input.txt");
	my_str l;

	
	try
	{
		in >> l;
		if (in.fail())
			throw 1;
	}
	catch (int e)
	{
		throw e;
	}

	std::cout << copyConstructorTest(l)
		  << " " << l.length() << " "
		  << l.reverse() << std::endl;
	
	in.close();

	std::cout << "Before return" << std::endl;
	return;
}

