#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

class RobotomyRequestForm : public AForm //deberia agregarle virutal?
{
	private:
		std::string _target;
		
	public:
		RobotomyRequestForm(); // Default constructor
		RobotomyRequestForm(std::string target); // constructor
		RobotomyRequestForm(const RobotomyRequestForm& copy); // Copy constructor 
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy); // Copy assignment operator
		~RobotomyRequestForm(void);
		
		void execute() const;
		
		//getters
		std::string getTarget() const;
};

#endif
