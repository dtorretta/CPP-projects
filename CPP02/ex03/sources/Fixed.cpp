#include "../includes/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed(void) : _fixedPointNumber(0) {}

// Constructor int to fixed-point value
Fixed::Fixed(const int int_number) : _fixedPointNumber(int_number * (1 << _fractionalBits)) {} // multiplicado por 256

// Constructor float to fixed-point value
// The roundf function is used to round the result to the nearest integer.
Fixed::Fixed(const float float_number) : _fixedPointNumber(roundf(float_number * (1 << _fractionalBits))) {} // multiplicado por 256

// The copy constructor creates a new object as a copy of an existing object.
Fixed::Fixed(const Fixed& src) : _fixedPointNumber(src.getRawBits()) {}

Fixed::~Fixed() {}

float Fixed::toFloat(void) const // Divide entre 256
{
    return ((float)this->_fixedPointNumber / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const // Divide entre 256
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
    return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//operador << está diseñado para convertir el valor de punto fijo de nuevo a flotante usando toFloat()
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) //std::ostream incluye a std::cout
{
    out << fixed.toFloat(); //llama a la funcion tofloat dentro del objeto pasado como parametro
    return(out); // Devuelve el flujo de salida para permitir encadenar más operaciones
}

/*
hacer '>> this->_fractionalBits' es mas eficiente que '/ (1 << this->_fractionalBits))' SOLO cuando estamos ajustando escala
para los demas casos no, porque se pierde presicion con los decimales
*/