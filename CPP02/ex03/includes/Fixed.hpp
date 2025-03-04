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
		Fixed(void);
		Fixed(const Fixed& src);
		Fixed(const int int_number);
		Fixed(const float float_number);
		Fixed& operator=(const Fixed& src);
		~Fixed();
		
		int getRawBits() const;
		void setRawBits(int const raw);		
		float toFloat( void ) const;
		int toInt( void ) const;	
		
		// arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		// comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		// increment/decrement operators
		Fixed operator++(); //pre-increment
		Fixed operator++(int); //post-increment
		Fixed operator--(); //pre-decrement
		Fixed operator--(int); //post-decrement
		//Static min & max functions
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		
};
		
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif


/*

El hecho de que uses int como argumento en el operador de post-incremento es una convención en C++. 
Este argumento no se utiliza en el cuerpo de la función, pero su presencia permite al compilador 
diferenciar entre el pre-incremento y el post-incremento.

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