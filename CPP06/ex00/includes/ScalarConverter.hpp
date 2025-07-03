#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <fstream>
#include <iomanip> //std::setprecision y std::fixed
#include <string>
#include <exception>

# include <climits> // INT_MAX and INT_MIN
# include <cfloat>  // FLT_MAX, FLT_MIN (float), DBL_MAX, DBL_MIN (double)
#include <cstdlib>
#include <sstream> 
#include <cmath> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class ScalarConverter
{
	private: //como no las voy a usar las dejo en privado
		ScalarConverter(); // Default constructor
		ScalarConverter(const ScalarConverter& copy); // Copy constructor 
		ScalarConverter& operator=(const ScalarConverter&); // Copy assignment operator
		~ScalarConverter(void);
		
	public:
		static void convert(std::string str);
};

#endif


