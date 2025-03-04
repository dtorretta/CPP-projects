#include "../includes/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

// Default constructor
Fixed::Fixed(void) : _fixedPointNumber(0)
{
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}

// Constructor int to fixed-point value
Fixed::Fixed(const int int_number) : _fixedPointNumber(int_number * (1 << _fractionalBits)) // multiplicado por 256
{
    std::cout << ORANGE << "Int constructor called" << RESET << std::endl;
}

// Constructor float to fixed-point value
// The roundf function is used to round the result to the nearest integer.
Fixed::Fixed(const float float_number) : _fixedPointNumber(roundf(float_number * (1 << _fractionalBits))) // multiplicado por 256
{
    std::cout << MAGENTA << "Float constructor called" << RESET << std::endl;
}

// The copy constructor creates a new object as a copy of an existing object.
Fixed::Fixed(const Fixed& src)
{
    std::cout << BLUE << "Copy constructor called" << RESET << std::endl;
    //this->_fixedPointNumber = src.getRawBits();
    *this = src; //llama al operador de asignación donde se va a ejecutar this->_fixedPointNumber = src.getRawBits()
    //* desreferencia el pointer ya que la copy assignment operator retorna una objeto y no un pointer. 
}

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

float Fixed::toFloat(void) const // Divide entre 256
{
    return ((float)this->_fixedPointNumber / (1 << _fractionalBits)); //igual que el int solo que le agrego el (float)
}

int Fixed::toInt( void ) const // Divide entre 256
{
    return (this->_fixedPointNumber / (1 << _fractionalBits)); // es lo mismo que poner this->_fixedPointNumber >> this->_fractionalBits;
}
		
// The copy assignment operator copies the contents from one existing object to another existing object.
Fixed& Fixed::operator=(const Fixed& src)
{
    std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    if(this != &src)
        this->_fixedPointNumber = src.getRawBits(); ///va????
    return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

int Fixed::getRawBits() const
{
    return(this->_fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointNumber = raw;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) //std::ostream incluye a std::cout
{
    out << fixed.toFloat(); //llama a la funcion tofloat dentro del objeto pasado como parametro
    return(out); // Devuelve el flujo de salida para permitir encadenar más operaciones
}


/*
TO INT
Si quieres obtener el valor entero después de haber realizado operaciones de punto fijo 
necesitas desplazar hacia la derecha (>>) para obtener el valor entero, usarías:

this->_fixedPointNumber >> this->_fractionalBits.                     ej: 1024 >> 8 = 4
que es lo mismo que 
this->_fixedPointNumber / (1 << this->_fractionalBits))               ej: 1024 / (1 << 8) =     1024 / 256  = 4

ESTO SOLO SIRVE SI ESTAMOS AJUSTANDO ESCALA
    

TO FIXED POINT
this->_fixedPointNumber * (1 << this->_fractionalBits)
(1 << this->_fractionalBits) = (1 << 8) = 256
*/