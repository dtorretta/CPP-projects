/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/05/19 15:49:54 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << GREEN << "WrongCat Constructor: " << RESET << "A new Cat was born" << std::endl;
}

// The copy constructor
WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	std::cout << GREEN << "WrongCat Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	if(this != &copy)
	{
		WrongAnimal::operator=(copy);
		std::cout << GREEN << "WrongCat Copy Operator called" << RESET << std::endl;
	}
	return(*this);
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << GREEN << "WrongCat Destructor called" << RESET << std::endl;
} 

//getter
std::string WrongCat::getType() const
{
	return(this->_type);
}

void WrongCat::makeSound(void) const
{
	std::cout << GREEN << "WrongCat makes: MEOOOOOOOOW 🐱" << RESET << std::endl;
	return;
}