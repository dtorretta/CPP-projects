/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/07/17 14:53:30 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

// Default constructor
Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
Intern::Intern(const Intern& copy)
{
	(void)copy; // Nothing to copy
	std::cout << "Intern Copy Constructor called" << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
Intern& Intern::operator=(const Intern& copy)
{
	(void)copy; // Nothing to copy
	std::cout << "Intern Copy Operator called" << std::endl;
	return(*this);
}

//destructor
Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
} 

//exceptions
const char* Intern::NonExistingFormException::what() const throw()
{
	std::cerr << RED << "ERROR404: ✗ form not found ✗" << RESET << std::endl;
	return NULL;
}

AForm* CreateShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* CreatePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* CreateRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	const std::string formNames[] = {"presidental pardon", "robotomy request", "shrubbery creation"};
	AForm* (*formCreator[])(const std::string _target) = {CreateShrubbery, CreateRobotomy, CreatePardon};
	
	for (int i = 0; i < 3; i++)
	{
		if(formNames[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (formCreator[i](target));
		}
	}
	throw NonExistingFormException();
}