#include "../includes/Fixed.hpp"

/*****INCREMENT / DECREMENT OPERATORS*****/	

Fixed Fixed::operator++() //pre-increment
{
    this->_fixedPointNumber += 1;
    return (*this);
}

Fixed Fixed::operator++(int) //post-increment
{
    Fixed temp = *this;
    this->_fixedPointNumber += 1;
    return (temp);
}

Fixed Fixed::operator--() //pre-decrement
{
    this->_fixedPointNumber -= 1;
    return (*this);
}

Fixed Fixed::operator--(int) //post-decrement
{
    Fixed temp = *this;
    this->_fixedPointNumber -= 1;
    return (temp);
}
