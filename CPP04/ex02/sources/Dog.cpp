/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/05/19 15:57:58 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// Default constructor
Dog::Dog(void): AAnimal()
{
	this->_type = "Dog";
	_brain = new Brain();
	std::cout << ORANGE << "Dog Constructor: " << RESET << "A new Dog was born 🐶" << std::endl;
}

// The copy constructor
Dog::Dog(const Dog& copy) : AAnimal(copy)
{
	this->_brain = new Brain(*copy._brain);
	std::cout << ORANGE << "Dog Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator
Dog& Dog::operator=(const Dog& copy) 
{
	if(this != &copy)
	{
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
		std::cout << ORANGE << "Dog Copy Operator called" << RESET << std::endl;
	}
	return(*this);
}

// Destructor
Dog::~Dog()
{
	delete this->_brain;
	std::cout << ORANGE << "Dog Destructor called" << RESET << std::endl;
} 

//getter
std::string Dog::getType() const
{
	return(this->_type);
}

void Dog::makeSound(void) const
{
	std::cout << BLUE << "Dog makes: WOOF, WOOF 🐶" << RESET << std::endl;
	return;
}

void Dog::setIdea (int i, std::string idea)
{
	_brain->setIdead(i, idea);
}

std::string Dog::getIdea (int i)
{
	return(_brain->getIdead(i));
}
