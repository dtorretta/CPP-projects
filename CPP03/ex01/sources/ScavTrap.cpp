/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/20 20:10:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void): ClapTrap() //primero crea el objeto claptrap y luego el objeto ScavTrap
{
	this->_Hitpoints = 100;
	this->_Energypoints = 50;
	this->_Attackdamage = 20;
	std::cout << ORANGE << "ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	this->_Hitpoints = 100; //modifica los valolres de los atributos de la clase base
	this->_Energypoints = 50;
	this->_Attackdamage = 20;
	std::cout << ORANGE << "ScavTrap name constructor called" << RESET << std::endl;
	
} 

// The copy constructor creates a new object as a copy of an existing object.
ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src) //llama directamente al copy constructor de la clase base
{
	std::cout << ORANGE << "ScavTrap copy constructor called" << RESET << std::endl;
}

//destructor
ScavTrap::~ScavTrap()
{
	std::cout << ORANGE << "ScavTrap destructor: " << _name << RESET << std::endl;
} 

void ScavTrap::guardGate() //tengo que usar getter?
{
	if (_Hitpoints == 0)
	{
		std::cout << RED << "ScavTrap " << _name << " is out of HP 💀" << RESET << std::endl;
        return;
	}
	std::cout << MAGENTA << "ScavTrap " << _name <<" is now in Gate keeper mode" << RESET << std::endl;
	return;
}

void ScavTrap::attack(const std::string& target)
{
	if (_Energypoints == 0)
	{
		std::cout << RED << "ScavTrap " << _name << " has no energy left to attack! 🪫" << RESET << std::endl;
        return;
	}
	
	else if (_Hitpoints == 0)
	{
		std::cout << RED << "ScavTrap " << _name << " is out of hit points and cannot attack 💀" << RESET << std::endl;
        return;
	}
	
	std::cout << BLUE << "ScavTrap " << _name << " attacks " << target << " causing " << get_attackdamage() << " points of damage 💥" << RESET << std::endl;
	_Energypoints --;
	return;
}




/*
scav no tiene atributos publcios propios, sino que hereda los de Clap
por eso al usar el copy constructor, no necesito manualmente copiar cada atributo --> lo hace la funcion de Clap

'src' (que es un ScavTrap) puede ser leído por ClapTrap(src) en el constructor de copia.
Cuando pasamos src a ClapTrap(src), estamos pasando un objeto de tipo ScavTrap a un constructor que espera un objeto ClapTrap.
Esto funciona porque un ScavTrap es un ClapTrap, ya que ScavTrap hereda de ClapTrap.
*/