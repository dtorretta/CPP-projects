/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/21 16:46:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

// Default constructor
//en clap no estoy usando el default porque asi lo pide la consigna

DiamondTrap::DiamondTrap(void): ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() //parents y abuelo
{
	_name = "Default"; //propio
	_Hitpoints = FragTrap::_Hitpoints;
	_Energypoints = ScavTrap::_Energypoints;
	_Attackdamage = FragTrap::_Attackdamage;
	std::cout << RED << "DiamondTrap default constructor called" << RESET << std::endl;
}

// Name constructor
/*
ClapTrap("Asuka_clap_name") le gana de mano a ScavTrap(Asuka)
*/
DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) //parents y abuelo
{
	_name = name; //propio
	_Hitpoints = FragTrap::_Hitpoints;
	_Energypoints = ScavTrap::_Energypoints;
	_Attackdamage = FragTrap::_Attackdamage;
	std::cout << RED << "DiamondTrap name constructor called" << RESET << std::endl;
} 

// The copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), ScavTrap(src), FragTrap(src) //llama directamente al copy constructor de la clase base
{
	this->_name = src._name; //ahora tengo este atributo
	std::cout << RED << "DiamondTrap copy constructor called" << RESET << std::endl;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	if(this != &src)
	{
		ClapTrap::operator=(src);
		this->_name = src._name; //ahora tengo este atributo
		std::cout << RED << "DiamondTrap copy operator called" << RESET << std::endl;
	}
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap destructor: " << _name << RESET << std::endl;
} 

std::string DiamondTrap::get_name() const
{
	return(this->_name);
}

void DiamondTrap::whoAmI()
{
	std::cout << ORANGE << "My DiamondTrap's name is: '" << this->get_name() 
	<< "' and my ClapTrap's name is: '" << ClapTrap::get_name()<< "'" << RESET << std::endl;
}

/*
en el constructor de DiamondTrap, tanto ClapTrap como ScavTrap reciben un valor. Entonces, ¿por qué el valor que recibe ClapTrap tiene "más peso"?

ClapTrap(name + "_clap_name"): Aquí le estás pasando el valor "Asuka_clap_name" a ClapTrap. 
Eso significa que cuando ClapTrap inicializa su atributo _name, el valor de _name será "Asuka_clap_name".

ScavTrap(name): A pesar de que pasas "Asuka" a ScavTrap, en realidad no modifica el atributo _name de ScavTrap, 
porque la clase ScavTrap hereda de ClapTrap, y el atributo _name ya fue inicializado por el constructor de 
ClapTrap con el valor "Asuka_clap_name". En otras palabras, el valor de _name no se sobrescribe en ScavTrap 
si ya fue inicializado en el constructor de ClapTrap.


El orden de la inicialización: En C++, cuando se inicializan las clases base en un constructor de una clase derivada, 
el orden de inicialización sigue el orden en que las clases aparecen en la lista de inicialización 

*/