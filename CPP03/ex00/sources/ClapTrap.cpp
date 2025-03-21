/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 23:12:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void): _name("Rei"), _Hitpoints(10), _Energypoints(10), _Attackdamage(0) 
{
	std::cout << YELLOW << "ClapTrap: No pilot available. Rei Ayanami will pilot the EVA Unit. Prepare for combat 🔥" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string name): _name(name), _Hitpoints(10), _Energypoints(10), _Attackdamage(0)
{
	std::cout << YELLOW << "ClapTrap " << name << ": Pilot ready. EVA Unit is operational. Prepare for combat 🔥" << RESET << std::endl;
} 

// The copy constructor creates a new object as a copy of an existing object.
ClapTrap::ClapTrap(const ClapTrap& src): _name(src.get_name()), _Hitpoints(src.get_hitpoints()), _Energypoints(src.get_energypoints()), _Attackdamage(src.get_attackdamage())
{
	//no necesitas crear un objeto extra como newClap.
	std::cout << YELLOW << "Copy constructor: ClapTrap " << _name << " copied!" << RESET << std::endl;
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
		std::cout << YELLOW << "Copy operator: ClapTrap " << _name << " copied!" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap " << _name << " has disconnected... The EVA has been deactivated. Ending operation." << RESET << std::endl;
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

void ClapTrap::takeDamage(unsigned int amount) //que onda con el hecho de que son negativos?
{
	if (_Hitpoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name << " is out of HP 💀" << RESET << std::endl;
        return;
	}
	
	std::cout << BLUE << "ClapTrap " << _name <<" suffered " << amount << " hit points 💥";
	
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