/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 21:55:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

// Default constructor
Animal::Animal(void): _type("Animal")
{
	std::cout << YELLOW << "Animal Constructor:" << RESET <<  " A new animal was born" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
Animal::Animal(const Animal& copy): _type(copy.getType())
{
	std::cout << YELLOW << "Animal Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
Animal& Animal::operator=(const Animal& copy)
{
	if(this != &copy)
	{
		this->_type = copy.getType();
		std::cout << YELLOW << "Animal Copy Operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
Animal::~Animal()
{
	std::cout << YELLOW << "Animal Destructor called" << RESET << std::endl;
} 

//getter
std::string Animal::getType() const
{
	return(this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << BLUE << "Animal makes: ... what does this animal sound like? 🤔" << RESET << std::endl;
	return;
}