/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 01:02:02 by marvin           ###   ########.fr       */
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
	std::cout << YELLOW << "FragTrap " << _name <<" is ready for a high-five! ✋ anyone?..." << RESET << std::endl;
	return;
}

//getter
unsigned int FragTrap::get_hitpoints() const
{
	return(this->_Hitpoints);
}
unsigned int FragTrap::get_attackdamage() const
{
	return(this->_Attackdamage);
}
