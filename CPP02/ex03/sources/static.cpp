#include "../includes/Fixed.hpp"

/*****STATIC FUNCTIONS*****/

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return(a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return(a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return(a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return(a > b) ? a : b;
}

