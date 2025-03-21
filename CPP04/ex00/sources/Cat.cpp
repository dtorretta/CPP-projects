/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 22:50:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// Default constructor
Cat::Cat(void): Animal()
{
	this->_type = "Cat";
	std::cout << GREEN << "Cat Constructor: " << RESET << "A new Cat was born" << std::endl;
}

// The copy constructor
Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << GREEN << "Cat Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator
Cat& Cat::operator=(const Cat& copy)
{
	if(this != &copy)
	{
		Animal::operator=(copy);
		std::cout << GREEN << "Cat Copy Operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

// Destructor
Cat::~Cat()
{
	std::cout << GREEN << "Cat Destructor called" << RESET << std::endl;
} 

//getter
std::string Cat::getType() const
{
	return(this->_type);
}

void Cat::makeSound(void) const
{
	std::cout << BLUE << "Cat makes: MEOOOOOOOOW 🐱" << RESET << std::endl;
	return;
}