/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:57:58 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:57:58 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed(void) : _fixedPointNumber(0)
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
Fixed::Fixed(const Fixed& src)
{
	std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if(this != &src)
		this->_fixedPointNumber = src.getRawBits();
	return(*this);
}

int Fixed::getRawBits() const
{
	std::cout << ORANGE << "getRawBits member function called" << RESET << std::endl;
	return(this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << MAGENTA << "setRawBits member function called" << RESET << std::endl;
	this->_fixedPointNumber = raw;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}
