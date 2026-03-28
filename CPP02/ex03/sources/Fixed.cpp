/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:56:01 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:56:01 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed(void) : _fixedPointNumber(0) {}

// Constructor int to fixed-point value
Fixed::Fixed(const int int_number) : _fixedPointNumber(int_number * (1 << _fractionalBits)) {}

// Constructor float to fixed-point value
// The roundf function is used to round the result to the nearest integer.
Fixed::Fixed(const float float_number) : _fixedPointNumber(roundf(float_number * (1 << _fractionalBits))) {}

// The copy constructor creates a new object as a copy of an existing object.
Fixed::Fixed(const Fixed& src) : _fixedPointNumber(src.getRawBits()) {}

Fixed::~Fixed() {}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointNumber / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointNumber / (1 << _fractionalBits));
}

int Fixed::getRawBits() const
{
	return(this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNumber = raw;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
Fixed& Fixed::operator=(const Fixed& src)
{
	if(this != &src)
		this->_fixedPointNumber = src.getRawBits();
	return(*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return(out);
}
