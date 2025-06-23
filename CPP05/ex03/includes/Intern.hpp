#ifndef INTER_HPP
# define INTER_HPP

#include <fstream>

#include <iostream>
#include <string>
#include <exception>
#include <map>
#include "AForm.hpp"


#include <cstdlib>
#include <sstream> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class AForm;

class Intern
{
	public:
		Intern(); // Default constructor
		Intern(const Intern& copy); // Copy constructor 
		Intern& operator=(const Intern& copy); // Copy assignment operator
		~Intern(void);
				
		class NonExistingFormException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
		
		AForm* makeForm(std::string form, std::string target);
};

#endif
