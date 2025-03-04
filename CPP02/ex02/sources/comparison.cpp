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

/*
bool Fixed::operator>(const Fixed &other) const
{
    if(this->_fixedPointNumber > other._fixedPointNumber)
        return(true);
    return(false);
}

el lo mismo que hacer

this->_fixedPointNumber > other._fixedPointNumber
*/