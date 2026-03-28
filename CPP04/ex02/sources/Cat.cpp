/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/05/19 15:57:32 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// Default constructor
Cat::Cat(void): AAnimal() //no puedohacer _brain(NULL) como hcie en HUMANA porque todavia no esta creado el elemento
{
	this->_type = "Cat";
	_brain = new Brain(); //le asigno memoria HEAP aca	
	std::cout << GREEN << "Cat Constructor: " << RESET << "A new Cat was born 🐱" << std::endl;
}

// The copy constructor
Cat::Cat(const Cat& copy): AAnimal(copy)
{
	this->_brain = new Brain(*copy._brain);
	std::cout << GREEN << "Cat Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator
Cat& Cat::operator=(const Cat& copy)
{
	if(this != &copy)
	{
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
		std::cout << GREEN << "Cat Copy Operator called" << RESET << std::endl;
	}
	return(*this);
}

// Destructor
Cat::~Cat()
{
	delete this->_brain;
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

void Cat::setIdea (int i, std::string idea)
{
	this->_brain->setIdead(i, idea);
}

std::string Cat::getIdea (int i)
{
	return(_brain->getIdead(i));
}

