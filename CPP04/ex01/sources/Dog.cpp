/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 21:55:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

// Default constructor
Dog::Dog(void): Animal() //no puedo hacer _brain(NULL) como hcie en HUMANA porque todavia no esta creado el elemento
{
	this->_type = "Dog";
	_brain = new Brain(); //le asigno memoria HEAP aca	
	std::cout << ORANGE << "Dog Constructor: " << RESET << "A new Dog was born 🐶" << std::endl;
}

// The copy constructor
Dog::Dog(const Dog& copy) : Animal(copy) //llama directamente al copy constructor de la clase base
{
	this->_brain = new Brain(*copy._brain); //como no se esta creado por medio de default constructor tengo que agregar new aca tambien
	//al hacer Brain(*copy._brain) estamos llamado al copy constuctor de Brain y no el default --> deep copie
	//si llamaramos al constructor default, se crearia un brain nuevo vacio, y se perderian los pensamientos.
	std::cout << ORANGE << "Dog Copy Constructor called" << RESET << std::endl;
}

// The copy assignment operator
Dog& Dog::operator=(const Dog& copy) 
{
	if(this != &copy)
	{
		//Animal::operator=(copy); //porqu7e no es necesario??
		delete this->_brain; // el objeto ya existe y podría tener recursos dinámicos previamente asignados por lo que liberamos el anterior
		this->_brain = new Brain(*copy._brain); // Clonamos el nuevo
		std::cout << ORANGE << "Dog Copy Operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
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
