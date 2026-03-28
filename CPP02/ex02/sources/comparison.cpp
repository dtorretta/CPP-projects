/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:52:45 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:52:45 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*****COMPARISON OPERATORS*****/		

bool Fixed::operator>(const Fixed &other) const
{
	return(this->_fixedPointNumber > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return(this->_fixedPointNumber < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return(this->_fixedPointNumber >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return(this->_fixedPointNumber <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return(this->_fixedPointNumber == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return(this->_fixedPointNumber != other.getRawBits());
}
