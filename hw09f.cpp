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
	this->buffer = strdup(s);
	this->capacity = strlen(s);
}



// copy constructor
my_str::my_str(const my_str & s)
{
	if (this->buffer != nullptr)
	{
		free(this->buffer);
		this->buffer = nullptr;
	}

	this->buffer = strdup(s.buffer);
	this->capacity = strlen(this->buffer);
}



// move constructor
my_str::my_str(my_str&& s) noexcept
	: capacity (s.capacity)
	, buffer (s.buffer) 
{
	s.buffer = nullptr;
	s.capacity = 0;
}



// overloaded assignment operator (deep copy '=' operator)
my_str& my_str::operator=(const my_str & s)
{
	if (this == &s)
		return *this;

	if (this->buffer != nullptr)
	{
		free(this->buffer);
		this->buffer = nullptr;
	}

	this->buffer = strdup(s.buffer);
	this->capacity = strlen(this->buffer);

	return *this;
}



// overloaded assignment operator (move '=' operator)
my_str& my_str::operator=(my_str && s) noexcept
{
	if (this == &s)
		return *this;

	// cleanup
	if (this->buffer != nullptr)
	{
		free(this->buffer);
		this->buffer = nullptr;
	}
	// member wise move
	this->capacity = s.capacity;
	this->buffer = s.buffer;

	s.buffer = nullptr;
	s.capacity = 0;

	return *this;
}



// overloaded [] operator
char& my_str::operator[](const int index)
{
	try
	{
		if (index > capacity || index < 0)
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
	return this->capacity;
}



// returns the index of the first occurance of c, returns -1 if unfound
int my_str::indexOf(char c) const
{
	for (int i = 0; i < this->capacity - 1; i++)
	{
		if (this->buffer[i] == c)
			return i;
	}

	return -1;
}



// returns the index of the first occurence of pat, returns -1 if unfound
int my_str::indexOf(const my_str & pat) const
{
	char* c = strstr(this->buffer, pat.buffer);

	if (c == nullptr)
		return -1;

	int index = -1;
	bool indexFound = false;
	while (index < this->capacity - 1 && !indexFound)
	{
		index++;
		if (this->buffer[index] == c[0])
		{
			for (int i = 1; i < pat.capacity - 1; ++i)
			{
				if (this->buffer[index + i] != c[i])
				{
					indexFound = false;
					i = pat.capacity;
				}
				else
					indexFound = true;
			}
		}
	}

	return index;
}



// overloaded "==" comparison, compares the c-string buffers 
bool my_str::operator==(const my_str & s) const
{
	if (strcmp(this->buffer, s.buffer) == 0)
		return true;

	return false;
}



// overloaded "+", concatenates this and s into a new my_str
my_str my_str::operator+(const my_str & s) const
{
	char newStr[this->capacity + s.capacity];
	strcpy(newStr, this->buffer);
	strcat(newStr, s.buffer);

	return my_str(newStr);
}



// overloaded "+=", concatenates s onto the end of this
my_str& my_str::operator+=(const my_str & s)
{
	char newStr[this->capacity + s.capacity];
	strcpy(newStr, this->buffer);
	strcat(newStr, s.buffer);

	if (this->buffer != nullptr)
	{	
		free(this->buffer);
		this->buffer = nullptr;
	}

	this->buffer = strdup(newStr);
	this->capacity = strlen(this->buffer);

	return *this;
}



// reverses the string within this and returns a my_obj containing that string
my_str my_str::reverse() const
{
	char newStr[this->capacity];
	strcpy(newStr, this->buffer);
	
	for (int i = 0; i < this->capacity; i++)
		newStr[i] = this->buffer[this->capacity - (1 + i)];

	return my_str(newStr);
}



// prints out this my_str to the ostream out
void my_str::print(std::ostream & out) const
{
	out << this->buffer;
}



// reads a word from the istream using getline and stores the characters into this my_str buffer
void my_str::read(std::istream & in)
{
	char newStr[256];
	in.getline(newStr, 256);

	if (this->buffer != nullptr)
	{	
		free(this->buffer);
		this->buffer = nullptr;
	}

	this->buffer = strdup(newStr);
	this->capacity = strlen(newStr);
}



// destruct a my_str
my_str::~my_str()
{
	if (this->buffer == nullptr)
		return;

	free(this->buffer);
	this->buffer = nullptr;
}
