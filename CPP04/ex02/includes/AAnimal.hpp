#ifndef AANIMAL_HPP
# define AANIMAL_HPP

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
#define FORM "\033[4m"

class AAnimal
{
	protected:
		std::string _type;
		
	public:
		AAnimal(void); // Default constructor
		AAnimal(const AAnimal& copy); // Copy constructor 
		AAnimal& operator=(const AAnimal& copy); // Copy assignment operator
		virtual ~AAnimal(void);

		virtual void makeSound(void) const = 0; // Ahora es una clase abstracta
		virtual std::string getType() const; //cada clase va a tener su propia funcion
};
		
#endif

/*
ABSTRACT


*/