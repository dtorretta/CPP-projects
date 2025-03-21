/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 21:55:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

// Default constructor
Brain::Brain(void) //inicializa el array de idea en vacio
{
	//no tengo qeu usar ningun new??? como asigno memroa para cada string?
	for(int i = 0; i < 100; i++)
	{
		_ideas[i] = ""; //empty
	}
	std::cout << RED << "Brain Constructor: " << RESET << "A new Brain was created" << std::endl;
}

// The copy constructor (from existint to new)
Brain::Brain(const Brain& copy) //llama directamente al copy constructor de la clase base
{
	for(int i = 0; i < 100; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
	std::cout << RED << "Brain Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator
Brain& Brain::operator=(const Brain& copy) 
{
	if(this != &copy)
	{
		for(int i = 0; i < 100; i++)
		{
			this->_ideas[i] = copy._ideas[i];
		}
		std::cout << RED << "Brain Copy Operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

// Destructor
Brain::~Brain()
{
	std::cout << RED << "Brain Destructor called" << RESET << std::endl;
} 

void Brain::setIdead(int i, std::string &idea) //porque la funcion no puede ser const?
{
	if(i >= 0 && i < 100)
		this->_ideas[i] = idea;
}

std::string Brain::getIdead(int i)
{
	if(i >= 0 && i < 100)
		return(_ideas[i]);
	return(""); //sino retorna vacio
}
		