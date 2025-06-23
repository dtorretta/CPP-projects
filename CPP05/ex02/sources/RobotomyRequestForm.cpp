/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/06/18 22:31:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45)
{
	this->_target = "unnamed";
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

// Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm("Robotomy Request Form", 72, 45)
{
	this->_target = copy.getTarget();
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if(this != &copy)
	{
		this->_target = copy.getTarget();
		std::cout << "RobotomyRequestForm Copy Operator called" << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
} 

//getter		
std::string RobotomyRequestForm::getTarget() const
{
	return(this->_target);
}

//creo una validacion random para que aveces falle asi se puefe checkear el mensaje de error
void RobotomyRequestForm::execute() const
{
	
	std::cout << YELLOW << "\n* DRILLING NOISES * 🤖 * BRZZZZZ... TKTKTKTKT... CLANG!! 💥⚙️" << RESET << std::endl;
	if(rand() % 2)
		std::cout << YELLOW << getTarget() << " has been robotomized successfully 50% of the time\n" << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed for " << getTarget() << "! 💥❌\n" << RESET << std::endl;
}

//sed -i 's/ShrubberyCreationForm/RobotomyRequestForm/g' sources/RobotomyRequestForm.cpp