#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m" 
#define RESET	"\033[0m"

class Fixed
{
	private:
		int _fixedPointNumber;
		static const int _fractionalBits;
		
	public:
		Fixed(void); // Default constructor
		Fixed(const Fixed& src); // Copy constructor 
		Fixed& operator=(const Fixed& src); // Copy assignment operator
		~Fixed();
		
		int getRawBits() const;
		void setRawBits(int const raw);
};
		
#endif


/*
static const int _fractionalBits;

que sea static significa que esta variable pertenece a la clase y no a las instancias (objetos) de la clase.
si no dijera static Cada objeto (Fixed a; Fixed b;) tendría su propia copia de fractionalBits.

al ser static, se define como variable global:
const int Fixed::_fractionalBits = 8;

*/