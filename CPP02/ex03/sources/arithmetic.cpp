#include "../includes/Fixed.hpp"

/*****ARITHMETIC OPERATORS*****/
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.setRawBits(this->_fixedPointNumber + other.getRawBits()); //setRawBits no es necesario para que funcione, sino que es una medida de hacerlo correctamente con el metodo de encapsulado
    return(result); //esto esta en numero fijo pero al imprimise en la consola, el << lo transformara en float.
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
    result.setRawBits((this->_fixedPointNumber * other.getRawBits()) >> _fractionalBits); //Ajustamos la escala dividiendo por 256
    return(result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.setRawBits((this->_fixedPointNumber << _fractionalBits) / other.getRawBits()); //Ajustamos la escala multiplicando por 256
    return(result);
}

/*
¿Por qué operator+ solo tiene un argumento?
Cuando defines un operador como método de la clase, el primer operando es el propio objeto (this), 
y el segundo operando es el argumento que pasas (other).
la llamada seria:
a.operator+(b);

Si el operador + fuera una función externa (fuera de la clase), entonces sí tendríamos que pasar dos argumentos

hacer '>> this->_fractionalBits' es mas eficiente que '/ (1 << this->_fractionalBits))' SOLO cuando estamos ajustando escala
para los demas casos no, porque se pierde presicion con los decimales


*/