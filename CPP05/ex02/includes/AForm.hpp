#ifndef AFORM_HPP
# define AFORM_HPP

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

class AForm
{
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _signed;
		
	public:
		AForm(); // Default constructor
		AForm(std::string name, int gradeToSign, int gradeToExecute); // Constructor
		AForm(const AForm& copy); // Copy constructor 
		AForm& operator=(const AForm& copy); // Copy assignment operator
		~AForm(void);
		
		//exceptions
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
		class NotSignedException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
			
		//getters
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getSigned() const;
		
		void beSigned(Bureaucrat &b);
		void beExecute(Bureaucrat const & executor) const; 
		virtual void execute() const = 0;
};
		
std::ostream& operator<<(std::ostream &out, const AForm &f);


#endif
