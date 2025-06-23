#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Aform.hpp" //necesario??

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

class Bureaucrat;

class ShrubberyCreationForm : public AForm //deberia agregarle virutal?
{
	private:
		std::string _target;
		
	public:
		ShrubberyCreationForm(); // Default constructor
		ShrubberyCreationForm(std::string target); // constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& copy); // Copy constructor 
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy); // Copy assignment operator
		~ShrubberyCreationForm(void);
		
		void execute() const;
		
		//getters
		std::string getTarget() const;
};

#endif
