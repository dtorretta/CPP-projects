#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class Animal
{
	protected:
		std::string _type;
		
	public:
		Animal(void); // Default constructor
		Animal(const Animal& copy); // Copy constructor 
		Animal& operator=(const Animal& copy); // Copy assignment operator
		virtual ~Animal(void);

		virtual void makeSound(void) const; //cada clase va a tener su propia funcion
		virtual std::string getType() const; //cada clase va a tener su propia funcion
};
		
#endif

/*
Makesound y getType son virtuales porque si no lo fuera, cuando intente llamar a la funcion dentro de dog, solo va a usar la de ANIMAL

como contrapartida, en la funciond entro de cada clase tambien le ponemos virtual

DESTRUCTOR
Cuando usas delete en un puntero a la clase base (Animal*), si el destructor no es virtual, 
solo se ejecuta el destructor de Animal, ignorando el destructor de Dog o Cat.



*/