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
