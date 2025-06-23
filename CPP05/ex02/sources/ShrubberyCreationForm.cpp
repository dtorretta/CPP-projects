/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/06/18 22:02:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form", 145, 137)
{
	this->_target = "unnamed";
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Form", 145, 137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm("Shrubbery Form", 145, 137)
{
	this->_target = copy.getTarget();
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if(this != &copy)
	{
		this->_target = copy.getTarget();
		std::cout << "ShrubberyCreationForm Copy Operator called" << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
} 

//getter		
std::string ShrubberyCreationForm::getTarget() const
{
	return(this->_target);
}

void ShrubberyCreationForm::execute() const
{
	std::ofstream file((getTarget() + "_shrubbery").c_str()); //para convertir std::string → const char*, compatible con C++98
	
	if(file.is_open())
	{
		file << "                _-_                 " << std::endl;
		file << "             /~~   ~~\\              " << std::endl;
		file << "          /~~         ~~\\           " << std::endl;
		file << "         {               }          " << std::endl;
		file << "          \\  _-     -_  /           " << std::endl;
		file << "           ~   \\\\ //  ~            " << std::endl;
		file << "         _- -   | | _- _            " << std::endl;
		file << "           _ -  | |   -_            " << std::endl;
		file << "                | |              " << std::endl;
		file << "           _____| |_____          " << std::endl;
	}
	else
		std::cerr << RED << "Error opening the file\n" << RESET << std::endl;
	file.close();
}

