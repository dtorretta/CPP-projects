#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 
#include "Animal.hpp"
#include "Brain.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m" 
#define RESET	"\033[0m"
#define FORM    "\033[4m"

class Dog: virtual public Animal
{
	private:
		Brain *_brain;
		
	public:
		Dog(void); // Default constructor
		Dog(const Dog& copy); // Copy constructor 
		Dog& operator=(const Dog& copy); // Copy assignment operator
		virtual ~Dog(void);

		virtual void makeSound(void) const;
		virtual std::string getType() const;
		void setIdea (int i, std::string idea);
		std::string getIdea (int i);
};
		
#endif
