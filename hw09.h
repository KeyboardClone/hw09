// ============================================================================
// File: hw09.h
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
//
// Description: Contains header information and class prototypes for the hw09
// my_str assignment
// ============================================================================
#ifndef	HW09_H
#define	HW09_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <exception>
#include <utility>

// Class prototypes
class my_str;

// Class definitions
class my_str
{
	private:
	char* buffer;
	size_t capacity;

	public:

	// one parameter constructor constructs this object from a c-string s
	// (s is an array of char terminated by '\0') 
	// parameter, s, defaults to the empty string ""
	// write and use strdup() to implement this constructor
	// it allocates a new array, then uses strcpy() to copy chars from
	// array s to the new array
	my_str(const char *s = "");
	
	// copy constructor for a my_str, must make a deep copy of s for this
	// (you can use strdup() you wrote)
	my_str(const my_str &s);

	// move constructor
	my_str(my_str &&s) noexcept;

	// assigns this my_str from my_str s (perform deep assignment
	// remember, both this and s have been previously constructed
	// so they each have storage pointed to by buf
	my_str& operator=(const my_str & s);

	// move assignment operator overloaded
	my_str& operator=(my_str && s) noexcept;

	// returns a reference to the char at position index, 0 is
	// the first element and so on
	// index must be in bounds
	char& operator[](const int index);

	size_t length() const;

	// returns the index of the first occurance of c in this my_str
	// indices range from o to length()-1
	// returns -1 if the character c is not in this my_str
	int indexOf(char c) const;

	// returns the index of the first occurrence of pat in this my_str
	// indices range from 0 to length() - 1
	// returns -1 if the character string pat is not in this my_str
	// write and use strstr() to implement this function
	int indexOf(const my_str & pat) const;

	// true if both my_str objects contain the same chars in same position
	// .. e.g, "abc" == "abc" returns true
	// write and use strcmp to implement this function
	bool operator==(const my_str &s) const;

    // true if the my_str object and the c-string contain the same chars in same positions
    // .. e.g. "abc" == "abc" evaluates true
    // write and use strcmp to implement this function
    bool operator==(const char* s) const;

	// concatenates this and s to make a new my_str
	// e.g., "abc" + "def" returns "abcdef"
	// write and use str2dup() to implement this function,
	// it should allocate a new array then call strcpy() and strcat()
	my_str operator+(const my_str & s) const;

	// concatenates s onto end of this
	// e.g., s = "abc"; s+="def" now s is "abcdef"
	// use str2dup()
	my_str& operator+=(const my_str & s);

	// returns another my_str that is the reverse of this my_str
	// e.g., s = "abc"; s.reverse() returns "cba"
	// write sttrev(char *dest, char *src) like strcpy() but
	// copies the reverse of src into dest, then use it
	my_str reverse() const;

	// prints out this my_str to the ostream out
	void print(std::ostream & out) const;

	// reads a word from the istream in and this my_str
	// becomes the same as the characters in that word
	// use getline() to implement read()
	void read(std::istream & in);

	// destruct a my_str, must free up each node in the head list
	~my_str();
};

// function prototypes

// these two I/O methods are complete as long as you define
// print and read methods correctly
inline std::ostream& operator<<(std::ostream& out, const my_str& str)
{       
    str.print(out);
    return out;
}       

inline std::istream& operator>>(std::istream& in, my_str& str)
{
	str.read(in);
	return in;
}



// write all these testing functions and add more of your own
// follow the example and write a function to test each method.
// Name each of these functions so they clearly indicate what they
// are testing
my_str copyConstructorTest(my_str l);

void testReverse();

void testIndexOf();

void testConcat();

void testCompare();

// write more test function prototytpes here



#endif
