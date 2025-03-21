#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

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
#define FORM    "\033[4m"

class WrongAnimal
{
	protected:
		std::string _type;
		
	public:
		WrongAnimal(); // Default constructor
		WrongAnimal(const WrongAnimal& copy); // Copy constructor 
		WrongAnimal& operator=(const WrongAnimal& copy); // Copy assignment operator
		~WrongAnimal(); //NO USAMOS VIRTUAL ACA

		void makeSound() const; //NO USAMOS VIRTUAL ACA
		std::string getType() const; //NO USAMOS VIRTUAL ACA
};
		
#endif

/*
Destructor, Makesound y getType les quitamos el virtual

*/