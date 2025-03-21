/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 15:58:06 by marvin           ###   ########.fr       */
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

/*
Lo que sucede aquí es que el constructor de ClapTrap(name) se llama correctamente y asigna el valor "Asuka" al atributo 
_name de ClapTrap. Pero este valor no se refleja automáticamente en la clase derivada ScavTrap si no haces algo más.
*/
ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	//si yo aca no hago _name = name; no se va a modificar.
	this->_Hitpoints = 100; //modifica los valolres de los atributos de la clase base
	this->_Energypoints = 50;
	this->_Attackdamage = 20;
	std::cout << ORANGE << "ScavTrap name constructor called" << RESET << std::endl;
	
} 

// The copy constructor creates a new object as a copy of an existing object.
ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src) //llama directamente al copy constructor de la clase base
{
	this->_Energypoints = src._Energypoints;
	std::cout << ORANGE << "ScavTrap copy constructor called" << RESET << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	if(this != &src)
	{
		ClapTrap::operator=(src);
		std::cout << ORANGE << "ScavTrap copy operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
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
	
	//std::cout << RED << "NAME: " << _name << RESET << std::endl; //borrar
	std::cout << BLUE << "ScavTrap " << this->_name << " attacks " << target << " causing " <<  get_attackdamage() << " points of damage 💥" << RESET << std::endl;
	_Energypoints --;
	return;
}

//getter
unsigned int ScavTrap::get_energypoints() const
{
	return(this->_Energypoints);
}



/*
scav no tiene atributos publcios propios, sino que hereda los de Clap
por eso al usar el copy constructor, no necesito manualmente copiar cada atributo --> lo hace la funcion de Clap

'src' (que es un ScavTrap) puede ser leído por ClapTrap(src) en el constructor de copia.
Cuando pasamos src a ClapTrap(src), estamos pasando un objeto de tipo ScavTrap a un constructor que espera un objeto ClapTrap.
Esto funciona porque un ScavTrap es un ClapTrap, ya que ScavTrap hereda de ClapTrap.
*/