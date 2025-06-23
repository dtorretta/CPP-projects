#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <fstream>

#include <string>
#include <exception>

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

class Bureaucrat
{
	private:
		std::string _name;
		int _grade;
		
	public:
		Bureaucrat(); // Default constructor
		Bureaucrat(std::string name, int grade); // Constructor
		Bureaucrat(const Bureaucrat& copy); // Copy constructor 
		Bureaucrat& operator=(const Bureaucrat& copy); // Copy assignment operator
		~Bureaucrat(void);
		
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
		int getGrade() const;
		
		void incrementGrade(); //no pueden ser const porque dentro de esta fuincion se va a modificar el valor de grade
		void decrementGrade();
};
		
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif
