/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 23:37:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

// Default constructor
AAnimal::AAnimal(void): _type("Animal")
{
	std::cout << YELLOW << "AAnimal Constructor:" << RESET <<  " A new animal was born" << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
AAnimal::AAnimal(const AAnimal& copy): _type(copy.getType())
{
	std::cout << YELLOW << "AAnimal Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
AAnimal& AAnimal::operator=(const AAnimal& copy)
{
	if(this != &copy)
	{
		this->_type = copy.getType();
		std::cout << YELLOW << "AAnimal Copy Operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
AAnimal::~AAnimal()
{
	std::cout << YELLOW << "AAnimal Destructor called" << RESET << std::endl;
} 

//getter
std::string AAnimal::getType() const
{
	return(this->_type);
}

void AAnimal::makeSound(void) const
{
	std::cout << BLUE << "AAnimal makes: ... what does this animal sound like? 🤔" << RESET << std::endl;
	return;
}