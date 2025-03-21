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
		virtual ~Dog(void); //aca TAMBIEN le ponemos virtual (no es necesario)

		virtual void makeSound(void) const; //aca TAMBIEN le ponemos virtual (no es necesario)
		virtual std::string getType() const; //aca TAMBIEN le ponemos virtual(no es necesario)
		void setIdea (int i, std::string idea);
		std::string getIdea (int i);
};
		
#endif

/*
como contrapartida, en la funciond entro de cada clase tambien le ponemos virtual (NO ES REALMENTE NECESARIO)

DESTRUCTOR
Cuando se crea un objeto de tipo Dog, su destructor es llamado. 
Si el destructor de Animal no fuera virtual, solo se llamaría el destructor de Animal, no el destructor de Dog, 
lo que podría generar comportamientos inesperados, como no liberar correctamente los recursos asignados por la clase derivada.

Aunque Dog hereda de Animal, no es necesario marcar su destructor como virtual. 
El polimorfismo se maneja en la clase base (Animal) cuando la clase base tiene métodos virtuales, 
incluido el destructor. En este caso, el destructor de Animal es virtual, y esto ya garantiza el 
comportamiento correcto de la destrucción del objeto

*/