/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 21:55:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

// Default constructor
Cat::Cat(void): Animal() //no puedohacer _brain(NULL) como hcie en HUMANA porque todavia no esta creado el elemento
{
	this->_type = "Cat";
	_brain = new Brain(); //le asigno memoria HEAP aca	
	std::cout << GREEN << "Cat Constructor: " << RESET << "A new Cat was born 🐱" << std::endl;
}

// The copy constructor
Cat::Cat(const Cat& copy): Animal(copy)
{
	this->_brain = new Brain(*copy._brain); //como no se esta creado por medio de default constructor tengo que agregar new aca tambien
	//al hacer Brain(*copy._brain) estamos llamado al copy constuctor de Brain y no el default --> deep copie
	//si llamaramos al constructor default, se crearia un brain nuevo vacio, y se perderian los pensamientos.
	std::cout << GREEN << "Cat Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator
Cat& Cat::operator=(const Cat& copy)
{
	if(this != &copy)
	{
		//Animal::operator=(copy); //porqu7e no es necesario??
		delete this->_brain; // el objeto ya existe y podría tener recursos dinámicos previamente asignados por lo que liberamos el anterior
		this->_brain = new Brain(*copy._brain); // Clonamos el nuevo
		std::cout << GREEN << "Cat Copy Operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
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

