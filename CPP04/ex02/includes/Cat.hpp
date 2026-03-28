#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 
#include "AAnimal.hpp"
#include "Brain.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m" 
#define RESET	"\033[0m"
#define FORM    "\033[4m"

class Cat: virtual public AAnimal
{
	private:
		Brain *_brain;
		
	public:
		Cat(void); // Default constructor
		Cat(const Cat& copy); // Copy constructor 
		Cat& operator=(const Cat& copy); // Copy assignment operator
		~Cat(void);

		void makeSound() const;
		std::string getType() const;
		void setIdea (int i, std::string idea);
		std::string getIdea (int i);
};
		
#endif
