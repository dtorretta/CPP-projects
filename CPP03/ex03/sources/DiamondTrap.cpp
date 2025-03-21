/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 01:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void): ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	_name = "Default";
	_Hitpoints = FragTrap::_Hitpoints;
	_Energypoints = ScavTrap::_Energypoints;
	_Attackdamage = FragTrap::_Attackdamage;
	std::cout << RED << "DiamondTrap default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name")
{
	_name = name;
	_Hitpoints = FragTrap::_Hitpoints;
	_Energypoints = ScavTrap::_Energypoints;
	_Attackdamage = FragTrap::_Attackdamage;
	std::cout << RED << "DiamondTrap name constructor called" << RESET << std::endl;
	
} 

//destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor: " << _name << RESET << std::endl;
} 

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
} 

std::string DiamondTrap::get_name() const
{
	return(this->_name);
}

void DiamondTrap::whoAmI()
{
	std::cout << GREEN << "My DiamondTrap's name is: '" << this->get_name() 
	<< "' and my ClapTrap's name is: '" << ClapTrap::get_name()<< "'" << RESET << std::endl;
}