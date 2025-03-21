#ifndef BRAIN_HPP
# define BRAIN_HPP

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

class Brain
{
	private:
		std::string _ideas[100];  // Array of 100 strings
		
	public:
		Brain(void); // Default constructor
		Brain(const Brain& copy); // Copy constructor 
		Brain& operator=(const Brain& copy); // Copy assignment operator
		virtual ~Brain(void);

		void setIdead(int i, std::string &idea); //cada clase va a tener su propia funcion???? VIRTUAL????
		std::string getIdead(int i); //cada clase va a tener su propia funcion???? VIRTUAL????
};
		
#endif

/*
Makesound y getType son virtuales porque si no lo fuera, cuando intente llamar a la funcion dentro de dog, solo va a usar la de ANIMAL

como contrapartida, en la funciond entro de cada clase tambien le ponemos virtual

DESTRUCTOR
Cuando usas delete en un puntero a la clase base (Animal*), si el destructor no es virtual, 
solo se ejecuta el destructor de Animal, ignorando el destructor de Dog o Cat.



*/