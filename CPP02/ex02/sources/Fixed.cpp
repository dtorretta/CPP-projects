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
Fixed::Fixed(const Fixed& src)
{
    //el lo mismo que hacer this->_fixedPointNumber = src.getRawBits();
    *this = src; //llama al operador de asignación donde se va a ejecutar this->_fixedPointNumber = src.getRawBits()
    //* desreferencia el pointer ya que la copy assignment operator retorna una objeto y no un pointer. 
}

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

/*
¿Por qué operator+ solo tiene un argumento?
Cuando defines un operador como método de la clase, el primer operando es el propio objeto (this), 
y el segundo operando es el argumento que pasas (other).
la llamada seria:
a.operator+(b);

hacer '>> this->_fractionalBits' es mas eficiente que '/ (1 << this->_fractionalBits))' SOLO cuando estamos ajustando escala
para los demas casos no, porque se pierde presicion con los decimales

Si el operador + fuera una función externa (fuera de la clase), entonces sí tendríamos que pasar dos argumentos



bool Fixed::operator>(const Fixed &other) const
{
    if(this->_fixedPointNumber > other._fixedPointNumber)
        return(true);
    return(false);
}

el lo mismo que hacer

this->_fixedPointNumber > other._fixedPointNumber
*/