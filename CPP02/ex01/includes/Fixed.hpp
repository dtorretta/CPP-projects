#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>

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
		
		Fixed(const int int_number); // Constructor int to fixed-point value
		Fixed(const float float_number); // Constructor float to fixed-point value
		float toFloat( void ) const;
		int toInt( void ) const;
};
		
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif


/*
static const int _fractionalBits;

que sea static significa que esta variable pertenece a la clase y no a las instancias (objetos) de la clase.
si no dijera static Cada objeto (Fixed a; Fixed b;) tendría su propia copia de fractionalBits.

al ser static, se define como variable global:
const int Fixed::_fractionalBits = 8;


declarar la funcion por fuera de la clase:
estás declarando la función como una función no miembro de la clase
es una función que no forma parte de la clase
esto es asi porque el operador << trabaja con std::cout
que no es parte de la clase Fixed. Es decir, std::cout es un objeto diferente y no 
tiene nada que ver con la clase Fixed directamente. Es un flujo de salida estándar para la consola.

¿Qué es un operador sobrecargado?
Cuando hablamos de "sobrecargar" un operador en C++, significa que estamos definiendo 
un nuevo comportamiento para un operador estándar (como +, -, <<, >>, etc.) 

*/