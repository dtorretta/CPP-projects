#ifndef PRESIDENTIALPARDONFORM_HPP
# define RESIDENTIALPARDONFORM_HPP

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

class PresidentialPardonForm : public AForm //deberia agregarle virutal?
{
	private:
		std::string _target;
		
	public:
		PresidentialPardonForm(); // Default constructor
		PresidentialPardonForm(std::string target); // constructor
		PresidentialPardonForm(const PresidentialPardonForm& copy); // Copy constructor 
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy); // Copy assignment operator
		~PresidentialPardonForm(void);
		
		void execute() const;
		
		//getters
		std::string getTarget() const;
};

#endif
