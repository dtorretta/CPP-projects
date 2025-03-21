/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 15:51:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void): _name("Shinji"), _Hitpoints(10), _Energypoints(10), _Attackdamage(0) 
{
	std::cout << YELLOW << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string name): _name(name), _Hitpoints(10), _Energypoints(10), _Attackdamage(0)
{
	std::cout << YELLOW << "ClapTrap name constructor called" << RESET << std::endl;
} 

// The copy constructor creates a new object as a copy of an existing object.
ClapTrap::ClapTrap(const ClapTrap& src)
{
	this->_name = src._name;
    this->_Hitpoints = src._Hitpoints;
    this->_Energypoints = src._Energypoints;
    this->_Attackdamage = src._Attackdamage;
    //no necesitas crear un objeto extra como newClap.
	std::cout << YELLOW << "ClapTrap copy constructor called" << RESET << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	if(this != &src)
	{
		this->_name = src.get_name();
		this->_Hitpoints = src.get_hitpoints();
		this->_Energypoints = src.get_energypoints();
		this->_Attackdamage = src.get_attackdamage();
		std::cout << YELLOW << "ClapTrap copy operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "ClapTrap destructor: " << _name << RESET << std::endl;
} 

//getter
unsigned int ClapTrap::get_hitpoints() const
{
	return(this->_Hitpoints);
}
unsigned int ClapTrap::get_energypoints() const
{
	return(this->_Energypoints);
}
unsigned int ClapTrap::get_attackdamage() const
{
	return(this->_Attackdamage);
}
std::string ClapTrap::get_name() const
{
	return(this->_name);
}

void ClapTrap::attack(const std::string& target)
{
	if (_Energypoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name << " has no energy left to attack! 🪫" << RESET << std::endl;
        return;
	}
	
	else if (_Hitpoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name << " is out of hit points and cannot attack 💀" << RESET << std::endl;
        return;
	}
	
	std::cout << BLUE << "ClapTrap " << _name << " attacks " << target << " causing " << get_attackdamage() << " points of damage 💥" << RESET << std::endl;
	_Energypoints --;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_Hitpoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name << " is out of HP 💀" << RESET << std::endl;
        return;
	}
	
	std::cout << YELLOW << "ClapTrap " << _name <<" suffered " << amount << " hit points 💥";
	
	if(amount >= _Hitpoints)
	{
		_Hitpoints = 0;
		std::cout << " and has been destroyed 💀" << RESET << std::endl;
	}
	else
	{
		_Hitpoints -= amount;
		std::cout << " and now has " << _Hitpoints << " HP remaining ❤️" << RESET << std::endl;
	}
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_Energypoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name << " has no energy left to heal 🪫" << RESET << std::endl;
        return;
	}
	
	else if (_Hitpoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name << " is out of HP and cannot be healed 💀" << RESET << std::endl;
        return;
	}
	
	std::cout << GREEN << "ClapTrap " << _name <<" regains " << amount << " hit points 🧪 ";
	_Energypoints --;
	if (amount <= (10 - this->_Hitpoints))
		this->_Hitpoints += amount;
	else
		_Hitpoints = 10;
		
	std::cout << " Current HP: " << _Hitpoints << " ❤️" << RESET << std::endl;
	return;
}