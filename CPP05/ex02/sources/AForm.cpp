/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/06/18 22:44:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

// Default constructor
//cuando los atributos privados son const SOLO pueden asignarse en el constructor en la lista de inicializacion
AForm::AForm() : _name("unnamed"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}

// Constructor
//cuando los atributos privados son const SOLO pueden asignarse en el constructor en la lista de inicializacion
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if(gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException(); //nunca finaliza el constructor asi que el objeto no se crea
	if(gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();  
	std::cout << "AForm Constructor called" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
AForm::AForm(const AForm& copy): _name(copy.getName()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()), _signed(copy.getSigned())
{
	std::cout << "AForm Copy Constructor called" << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
// ❗Only _signed is not constant, therefore is the only atribute we can copy
AForm& AForm::operator=(const AForm& copy)
{
	if(this != &copy)
	{
		this->_signed = copy.getSigned();
		std::cout << "AForm Copy Operator called" << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
} 

//getter		
std::string AForm::getName() const
{
	return(this->_name);
}

int AForm::getGradeToSign() const
{
	return(this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return(this->_gradeToExecute);
}

bool AForm::getSigned() const
{
	return(this->_signed);
}

//exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form not signed!";
}

//overload <<
std::ostream& operator<<(std::ostream &out, const AForm &f) //std::ostream incluye a std::cout
{
    std::string status = "not signed";
    
    if (f.getSigned())
        status = "signed";
        
    out << YELLOW << f.getName() << "\nstatus: " << status
        << "\nForm grade required to sign it: " << f.getGradeToSign() 
		<< "\nForm grade required to execute it: " << f.getGradeToExecute()<< "." << RESET;
    return(out); // Devuelve el flujo de salida para permitir encadenar más operaciones
}

void AForm::beSigned(Bureaucrat &b)
{
	if(b.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();  
	
	this->_signed = true;
}

//cuando uso this-> estoy trabajando con el objeto derivado
void AForm::beExecute(Bureaucrat const & executor) const
{
	if(!this->_signed)	
		throw NotSignedException();
	if(this->_gradeToExecute < executor.getGrade())
		throw GradeTooLowException(); 
	this->execute();
}