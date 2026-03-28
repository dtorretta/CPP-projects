#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 
#include "Animal.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m" 
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class Dog: virtual public Animal
{	
	public:
		Dog(void); // Default constructor
		Dog(const Dog& copy); // Copy constructor 
		Dog& operator=(const Dog& copy); // Copy assignment operator
		virtual ~Dog(void);

		virtual void makeSound(void) const;
		virtual std::string getType() const;
};
		
#endif

