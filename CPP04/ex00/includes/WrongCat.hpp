#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "../includes/WrongAnimal.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class WrongCat : public WrongAnimal //NO USAMOS VIRTUAL
{
	public:
		WrongCat(); // Default constructor
		WrongCat(const WrongCat& copy); // Copy constructor 
		WrongCat& operator=(const WrongCat& copy); // Copy assignment operator
		~WrongCat();

		void makeSound() const;
		std::string getType() const;
	};

	#endif
	
/*
class WrongCat : public WrongAnimal
le quitamos Virtual a la clase derivada	
*/