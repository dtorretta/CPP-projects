#pragma once 

#include <iostream>
#include <fstream>
#include <iomanip> //std::setprecision y std::fixed
#include <string>
#include <exception>

# include <climits> // INT_MAX and INT_MIN
# include <cfloat>  // FLT_MAX, FLT_MIN (float), DBL_MAX, DBL_MIN (double)
#include <stdint.h>  // para uintptr_t
#include <cstdlib>
#include <sstream> 
#include <cmath> 
#include "Data.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class Serializer
{
	private: //como no las voy a usar las dejo en privado
		Serializer(); // Default constructor
		Serializer(const Serializer& copy); // Copy constructor 
		Serializer& operator=(const Serializer&); // Copy assignment operator
		~Serializer(void);
		
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};



