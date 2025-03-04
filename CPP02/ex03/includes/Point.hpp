#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include "Fixed.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m" 
#define RESET	"\033[0m"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
		
	public:
		Point(void); //default constructor
		Point(const float x, const float y);
		Point(const Point& src); //copy constructor
		Point& operator=(const Point& src); //copy assignment operator
		~Point(void);
		
		Fixed getx(void) const;
		Fixed gety(void) const;			
};
#endif

