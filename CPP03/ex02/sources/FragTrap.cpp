/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 12:35:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(void): ClapTrap() //primero crea el objeto claptrap y luego el objeto ScavTrap
{
	this->_Hitpoints = 100;
	this->_Energypoints = 100;
	this->_Attackdamage = 30;
	std::cout << MAGENTA << "FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	this->_Hitpoints = 100; //modifica los valores de los atributos de la clase base
	this->_Energypoints = 100;
	this->_Attackdamage = 30;
	std::cout << MAGENTA << "FragTrap name constructor called" << RESET << std::endl;
	
} 
// The copy constructor creates a new object as a copy of an existing object.
FragTrap::FragTrap(const FragTrap& src): ClapTrap(src) //llama directamente al copy constructor de la clase base
{
	std::cout << MAGENTA << "FragTrap copy constructor called" << RESET << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
FragTrap& FragTrap::operator=(const FragTrap& src)
{
	if(this != &src)
	{
		ClapTrap::operator=(src);
		std::cout << MAGENTA << "FragTrap copy operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
FragTrap::~FragTrap()
{
	std::cout << MAGENTA << "FragTrap destructor: " << _name << RESET << std::endl;
} 

void FragTrap::highFivesGuys() //tengo que usar getter?
{
	if (_Hitpoints == 0)
	{
		std::cout << RED << "FragTrap " << _name << " is out of HP 💀" << RESET << std::endl;
        return;
	}
	std::cout << MAGENTA << "FragTrap " << _name <<" is ready for a high-five! ✋ anyone?..." << RESET << std::endl;
	return;
}

