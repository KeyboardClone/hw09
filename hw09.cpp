// ============================================================================
// File: hw09.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
// 
// Description: a test driver for the my_str class's functionality
// ============================================================================
#include "hw09.h"



int main()
{
	// this try/catch will catch any exception thrown by
	// my_str::error() while calling test functions
	
	try
	{
		testReverse();	// if we throw an error of 1, the input failed
				//	when trying to read from the file
		// put more test function calls here written just above
		std::cout << "after testReverse()" << std::endl;
	}
	catch (int i)
	{
		std::cout << "Got an exception: " << i << std::endl;
	}

	// std::cerr << "Net memory allocated at program end: "
	//    	  << std::NumAllocations << std::endl;
	// std::cerr << "(should be zero... ";
	// std::cerr << "positive = mem leak, negative = duplicate delete)\n";

	return 0;
}
