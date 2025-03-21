/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 22:49:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// Default constructor
Dog::Dog(void): Animal() 
{
	this->_type = "Dog";
	std::cout << ORANGE << "Dog Constructor: " << RESET << "A new Dog was born" << std::endl;
}

// The copy constructor
Dog::Dog(const Dog& copy) : Animal(copy) //llama directamente al copy constructor de la clase base
{
	std::cout << ORANGE << "Dog Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator
Dog& Dog::operator=(const Dog& copy) 
{
	if(this != &copy)
	{
		Animal::operator=(copy);
		std::cout << ORANGE << "Dog Copy Operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

// Destructor
Dog::~Dog()
{
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