// ============================================================================
// File: hw09f.cpp
// ============================================================================
// Programmer: Jonathan Hungate
// Class: CS1C
// Instructor: Domingos Begalli
// 
// Description: Further defines hw09.h's function and class prototypes
// ============================================================================
#include "hw09.h"



// Single Parameter constructor
// Dynamically allocates a c-string on the freestore based on the contents of 
// the dereferenced s
my_str::my_str(const char *s)
{
    // dynamically allocates a single c-string into memory, setting this buffer
    // to point to it
	this->buffer = strdup(s);
	this->capacity = strlen(s);
}



// copy constructor
my_str::my_str(const my_str & s)
{
    // cleanup of prior c-string buffer held
	if (this->buffer != nullptr)
	{
		free(this->buffer);
		this->buffer = nullptr;
	}

    // reorients buffer to point to a new c-string within mem
    if (s.buffer != nullptr)
        this->buffer = strdup(s.buffer);

    this->capacity = s.capacity;
}



// move constructor
my_str::my_str(my_str&& s) noexcept
	: capacity (std::move(s.capacity))
	, buffer (std::exchange(s.buffer, nullptr)) {}



// overloaded assignment operator (deep copy '=' operator)
my_str& my_str::operator=(const my_str & s)
{
    // if we are attempting to perform a deep copy on the same
    // object, we should avoid trying to mess with anything in memory
	if (this == &s)
		return *this;

    // cleanup
	if (this->buffer != nullptr)
	{
		free(this->buffer);
		this->buffer = nullptr;
	}

    // makes new data for this my_str object to point to
    if (s.buffer != nullptr)
	    this->buffer = strdup(s.buffer);
	this->capacity = s.capacity;

    // returns this
	return *this;
}



// overloaded assignment operator (move '=' operator)
my_str& my_str::operator=(my_str && s) noexcept
{
    // keeps from trying to move the same object in memory
	if (this == &s)
		return *this;

	// cleanup
	if (this->buffer != nullptr)
	{
		free(this->buffer);
		this->buffer = nullptr;
	}

	// has this my_str object point to s's data members
	this->buffer = std::exchange(s.buffer, nullptr);
    this->capacity = std::move(s.capacity);

	return *this;
}



// overloaded [] operator
char& my_str::operator[](const int index)
{
    // will attempt to return the index of this->buffer the user wants to access
    // through the '[]' operator, throws and exception if the user attempts to access
    // out of bounds data
	try
	{
		if (index > capacity || index < 0 || this->buffer == nullptr)
		{
			std::out_of_range e(std::to_string(index));
			throw e;
		}

		return this->buffer[index];
	}
	catch(std::out_of_range &e)
	{
		throw e;
	}
}



// returns the capacity of the c-string in question
size_t my_str::length() const 
{
    if (this->buffer != nullptr)
	    return this->capacity;

    return 0;
}



// returns the index of the first occurance of c, returns -1 if unfound
int my_str::indexOf(char c) const
{
    // in the event that this->buffer is a nullptr, we don't want to try and
    // find an index of null
    if (this->buffer == nullptr)
        return -1;

    // searches through this->buffer in order to find the first instance of
    // the character within c
	for (int i = 0; i < this->capacity - 1; i++)
	{
		if (this->buffer[i] == c)
			return i;
	}

    // reaching here should only be possible if c was not found within this->buffer
    // thus we must return -1 to indicate that the character was not found
	return -1;
}



// returns the index of the first occurence of pat, returns -1 if unfound
int my_str::indexOf(const my_str & pat) const
{
    if  (this->buffer == nullptr || pat.buffer == nullptr)
        return -1;

    // searches for wherever pat.buffer may appear within this->buffer,
    // returns a nullptr in the event none is found
	char* c = strstr(this->buffer, pat.buffer);

    // if c points to nullptr, we return a -1 to indicate that it pat.buffer
    // is not in this->buffer
	if (c == nullptr)
		return -1;

    // subtracting the length of the c-string pointer c from this->capacity should
    // result in the index of pat.buffer's appearance in this->buffer
    return (int)(this->capacity - strlen(c));
}



// overloaded "==" comparison, compares the c-string buffers 
bool my_str::operator==(const my_str & s) const
{
    if (this->buffer != nullptr && s.buffer != nullptr)
    {
        // compares this->buffer and s.buffer's c-string contents,
        // returns true if they are the same
        if (strcmp(this->buffer, s.buffer) == 0)
            return true;
        else
            return false;
    }

    // this indicates that either this->buffer or s.buffer points to nullptr
	return false;
}


// overloaded "==" comparison, compares this->buffer to a const c-string
bool my_str::operator==(const char* s) const
{
    // checks to see if this->buffer is presently null, returning false if such is the case
    if (this->buffer == nullptr)
        return false;

    // compares this->buffer and s, returning true if they are the same
    if (strcmp(this->buffer, s) == 0)
        return true;

    // defaults to returning false
    return false;
}



// overloaded "+", concatenates this and s into a new my_str
my_str my_str::operator+(const my_str & s) const
{
    // sets newStr to have as many character positions as both
    // this and s combined
	char newStr[this->capacity + s.capacity];

    // concatenates s.buffer onto the end of this->buffer,
    // so long as this->buffer and s.buffer do not point to null
    // if either of them do, their part is reduced to ""
    if (this->buffer != nullptr)
        strcpy(newStr, this->buffer);
    else
        strcpy(newStr, "");

    if (s.buffer != nullptr)
        strcat(newStr, s.buffer);

    // returns a my_str object using this newly create c-string
	return my_str(newStr);
}



// overloaded "+=", concatenates s onto the end of this
my_str& my_str::operator+=(const my_str & s)
{
    // sets newStr to have as many character positions as both
    // this and s combined
	char newStr[this->capacity + s.capacity];

    // concatenates s.buffer onto the end of this->buffer,
    // so long as this->buffer and s.buffer do not point to null
    // if either of them do, their part is reduced to ""
    if (this->buffer != nullptr)
        strcpy(newStr, this->buffer);
    else
        strcpy(newStr, "");

    if (s.buffer != nullptr)
        strcat(newStr, s.buffer);

    // performs cleanup on whatever this->buffer is presently pointing to,
    // unless it is pointing to a nullptr location
	if (this->buffer != nullptr)
	{	
		free(this->buffer);
		this->buffer = nullptr;
	}

    // modifies this my_str object using utilizing this newStr data
	this->buffer = strdup(newStr);
	this->capacity = strlen(this->buffer);

    // returns a reference(?) to this object
	return *this;
}



// reverses the string within this and returns a my_obj containing that string
my_str my_str::reverse() const
{
    // if this->buffer points to nothing, there is nothing to reverse, so we
    // should return an empty my_str object
    if (this->buffer == nullptr)
        return my_str();

    // reaching this point, we can safely assume there is something pointed to
    // by this->buffer, so let's reverse that string
	char newStr[this->capacity];

    // stores the reversed form of this->buffer into newStr
	strrev(newStr, this->buffer);

    // returns a my_str object using the now reversed form of this->buffer
    // within newStr to initialize that object
	return my_str(newStr);
}



// prints out this my_str to the ostream out
void my_str::print(std::ostream & out) const
{
    // simply displays this->buffer using whatever ostream object is passed in,
    // so long as this->buffer is not null
    if (this->buffer != nullptr)
        out << this->buffer;

    return;
}



// reads a word from the istream using getline and stores the characters into this my_str buffer
void my_str::read(std::istream & in)
{
    // creates a c-string of 256 characters (could be longer if so desired) for the upcoming input
    // to be stored in
	char newStr[256];
	in.getline(newStr, 256);

    // performs memory cleanup if this->buffer is not null
	if (this->buffer != nullptr)
	{	
		free(this->buffer);
		this->buffer = nullptr;
	}

    // sets this->buffer to point to the newly input user c-string
	this->buffer = strdup(newStr);
	this->capacity = strlen(newStr);

    return;
}



// destruct a my_str
my_str::~my_str()
{
    // if this->buffer points to nullptr, we immediately end the destructor
    // call as this particular buffer is empty and we need not perform any
    // memory cleanup
	if (this->buffer == nullptr)
		return;

    // cleans up memory
	free(this->buffer);
	this->buffer = nullptr;

    this->capacity = 0;
}
