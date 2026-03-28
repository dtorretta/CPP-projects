/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:52:23 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:52:23 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*****ARITHMETIC OPERATORS*****/
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointNumber + other.getRawBits());
	return(result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointNumber - other.getRawBits());
	return(result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->_fixedPointNumber * other.getRawBits()) >> _fractionalBits);
	return(result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->_fixedPointNumber << _fractionalBits) / other.getRawBits());
	return(result);
}
