/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/06/18 22:43:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

// Default constructor
//cuando los atributos privados son const SOLO pueden asignarse en el constructor en la lista de inicializacion
Form::Form() : _name("unnamed"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
	std::cout << "Form Defult Constructor called" << std::endl;
}

// Constructor
//cuando los atributos privados son const SOLO pueden asignarse en el constructor en la lista de inicializacion
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException(); //nunca finaliza el constructor asi que el objeto no se crea
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();  
	std::cout << "Form Constructor called" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
Form::Form(const Form& copy): _name(copy.getName()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()), _signed(copy.getSigned())
{
	std::cout << "Form Copy Constructor called" << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
// ❗Only _signed is not constant, therefore is the only atribute we can copy
Form& Form::operator=(const Form& copy)
{
	if(this != &copy)
	{
		this->_signed = copy.getSigned();
		std::cout << "Form Copy Operator called" << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
} 

//getter		
std::string Form::getName() const
{
	return(this->_name);
}

int Form::getGradeToSign() const
{
	return(this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return(this->_gradeToExecute);
}

bool Form::getSigned() const
{
	return(this->_signed);
}

//exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

//overload <<
std::ostream& operator<<(std::ostream &out, const Form &f) //std::ostream incluye a std::cout
{
    std::string status = "not signed";
    
    if (f.getSigned())
        status = "signed";
        
    out << YELLOW << f.getName() << "\nstatus: " << status
        << "\nForm grade required to sign it: " << f.getGradeToSign() 
		<< "\nForm grade required to execute it: " << f.getGradeToExecute()<< "." << RESET;
    return(out); // Devuelve el flujo de salida para permitir encadenar más operaciones
}

void Form::beSigned(Bureaucrat &b)
{
	if(b.getGrade() > getGradeToSign())
		throw GradeTooLowException();  
	
	_signed = true;
	//std::cout << "Form signed by the Bureaucrat " << b.getName() << std::endl;
}