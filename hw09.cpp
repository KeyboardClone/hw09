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
		testReverse();	// if we throw an error of 1, the file failed to
                        //  open properly
                        // if we throw an error of 2, the input failed
				        //	when trying to read from the file
        testIndexOf();
        testConcat();
        testCompare();
        testIndexAccess();
	}
	catch (int i)
	{
		std::cout << "Got an exception: ";

        // exception message display, interprets the error code it was given and
        // displays a corresponding error message
        switch(i)
        {
            case 1:
                std::cout << "Unable to open the input file" << std::endl;
                break;
            case 2:
                std::cout << "Unable to read input into my_str in testReverse()" << std::endl;
                break;
            case 3:
                std::cout << "Unable to read input into a my_str in testIndexOf()" << std::endl;
                break;
            case 4:
                std::cout << "Entered blank input into a my_str within testIndexOf()" << std::endl;
                break;
            case 5:
                std::cout << "Unable to read input into char in testIndexOf()" << std::endl;
                break;
            case 6:
                std::cout << "Unable to read input into a my_str in testCompare()" << std::endl;
                break;
            case 7:
                std::cout << "Entered blank input into a my_str within testCompare()" << std::endl;
                break;
            case 8:
                std::cout << "Entered an invalid int value within testIndexAccess()" << std::endl;
                break;
            case 9:
                std::cout << "Attempted to access an out of bounds character within the my_str buffer in testIndexAccess()" << std::endl;
                break;

            default:
                std::cout << "Error code " << i << std::endl;
        }
	}
    catch (std::out_of_range &e)
    {
        std::cout << "Out of range exception: " << e.what() << std::endl;
    }

	std::cerr << "Net memory allocated at program end: "
	   	  << my_str::NumAllocations << std::endl;
	std::cerr << "(should be zero... ";
	std::cerr << "positive = mem leak, negative = duplicate delete)\n";

	return 0;
}
