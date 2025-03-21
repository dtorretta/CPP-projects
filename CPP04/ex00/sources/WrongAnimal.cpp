/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 22:48:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << YELLOW << "WrongAnimal Constructor: " << RESET << "A new animal was born" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
WrongAnimal::WrongAnimal(const WrongAnimal& copy): _type(copy.getType())
{
	std::cout << YELLOW << "WrongAnimal Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	if(this != &copy)
	{
		this->_type = copy.getType();
		std::cout << YELLOW << "WrongAnimal Copy Operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << YELLOW << "WrongAnimal Destructor called" << RESET << std::endl;
} 

//getter
std::string WrongAnimal::getType() const
{
	return(this->_type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << YELLOW << "WrongAnimal makes: ... what does this animal sound like? 🤔" << RESET << std::endl;
	return;
}