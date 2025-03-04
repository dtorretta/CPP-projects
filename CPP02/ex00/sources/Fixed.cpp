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
    //this->_fixedPointNumber = src.getRawBits();
    *this = src; //llama al operador de asignación donde se va a ejecutar this->_fixedPointNumber = src.getRawBits()
    //* desreferencia el pointer ya que la copy assignment operator retorna una objeto y no un pointer. 
}

// The copy assignment operator copies the contents from one existing object to another existing object.
Fixed& Fixed::operator=(const Fixed& src)
{
    std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    if(this != &src)
        this->_fixedPointNumber = src.getRawBits();
    return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
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

/*

el constructor asigna un vaor default a _fixedPointNumber
el copy constructor asigna al _fixedPointNumber del nuevo objeto, el _fixedPointNumber del que esta copiando
    this->_fixedPointNumber = src.getRawBits();



siempre que dentro de una funcion usamos this-> es porque estamos trabajando con punteros.
*this lo estamos desreferenciando para acceder a su objeto
*/