/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 11:21:16 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void): _name("Random"), _Hitpoints(10), _Energypoints(10), _Attackdamage(0) {}

ClapTrap::ClapTrap(const std::string name): _name(name) {}

// The copy constructor creates a new object as a copy of an existing object.
ClapTrap::ClapTrap(const ClapTrap& src)
{
	ClapTrap NewClap;
	NewClap._name = src.get_name();
	NewClap._Hitpoints = src.get_hitpoints();
	NewClap._Energypoints = src.get_energypoints();
	NewClap._Attackdamage = src.get_attackdamage();	
}
		ClapTrap& operator=(const ClapTrap& src); // Copy assignment operator

ClapTrap::~ClapTrap() {}

//getter
int ClapTrap::get_hitpoints() const
{
	return(this->_Hitpoints);
}
int ClapTrap::get_energypoints() const
{
	return(this->_Energypoints);
}
int ClapTrap::get_attackdamage() const
{
	return(this->_Attackdamage);
}
std::string ClapTrap::get_name() const
{
	return(this->_name);
}
