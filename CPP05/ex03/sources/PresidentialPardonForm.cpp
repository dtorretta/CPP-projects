/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/06/18 22:37:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5)
{
	this->_target = "unnamed";
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

// Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5)
{
	this->_target = target;
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm("Presidential Pardon Form", 25, 5)
{
	this->_target = copy.getTarget();
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if(this != &copy)
	{
		this->_target = copy.getTarget();
		std::cout << "PresidentialPardonForm Copy Operator called" << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
} 

//getter		
std::string PresidentialPardonForm::getTarget() const
{
	return(this->_target);
}

void PresidentialPardonForm::execute() const
{
	std::cout << YELLOW << getTarget() << " has been pardoned by Zaphod Beeblebrox 👏\n" << RESET << std::endl;
}

//sed -i 's/ShrubberyCreationForm/PresidentialPardonForm/g' sources/PresidentialPardonForm.cpp