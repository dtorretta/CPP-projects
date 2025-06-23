#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <fstream>

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

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

class Form
{
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signed;
		
	public:
		Form(); // Default constructor
		Form(std::string name, int gradeToSign, int gradeToExecute); // constructor
		Form(const Form& copy); // Copy constructor 
		Form& operator=(const Form& copy); // Copy assignment operator
		~Form(void);
		
		class GradeTooHighException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
			
		class GradeTooLowException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
				
		//getters
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getSigned() const;
		
		void beSigned(Bureaucrat &b); //NO necesito hacer herencia, solo decflarar los headers para que puedan acceder
};
		
std::ostream& operator<<(std::ostream &out, const Form &f);

#endif
