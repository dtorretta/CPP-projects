/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/06/18 22:41:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("unnamed")
{
	_grade = 150;
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

// Constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if(grade < 1)
		throw GradeTooHighException(); //nunca finaliza el constructor asi que el objeto no se crea
	if(grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if(this != &copy)
	{
		this->_name = copy.getName();
		this->_grade = copy.getGrade();
		std::cout << "Bureaucrat Copy Operator called" << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
} 

//getter
std::string Bureaucrat::getName() const
{
	return(this->_name);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::decrementGrade(void) 
{
	if(_grade + 1 <= 150)
	{
		_grade++;
		std::cout << BLUE << "Grade decremented" << RESET << std::endl;
	}
	else
		throw GradeTooLowException();
		
	return;
}

void Bureaucrat::incrementGrade(void) 
{
	if(_grade - 1 >= 1)
	{
		_grade--;
		std::cout << GREEN << "Grade incremented" << RESET << std::endl;
	}
	else
		throw GradeTooHighException(); 
	return;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << GREEN << getName() << " signed " << f.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << getName() << " couldn’t sign " << f.getName() << " because " << e.what() << ".\n" << RESET << std::endl;
	}
}

//exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

//overload <<
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b) //std::ostream incluye a std::cout
{
    out << YELLOW << b.getName()  << ", bureaucrat grade " << b.getGrade() << "." << RESET;
    return(out); // Devuelve el flujo de salida para permitir encadenar más operaciones
}