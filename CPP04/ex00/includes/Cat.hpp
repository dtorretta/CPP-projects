#ifndef CAT_HPP
# define CAT_HPP

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

class Cat: virtual public Animal
{
	// protected:
	// 	std::string _type; //NO HAY QUE VOLVER A DECLARARLO, USAMOS EL DE ANIMAL PERO REESCRIBIENDO EL VALOR
		
	public:
		Cat(void); // Default constructor
		Cat(const Cat& copy); // Copy constructor 
		Cat& operator=(const Cat& copy); // Copy assignment operator
		~Cat(void); //funciona tambien si no le ponemos virtual aca

		void makeSound(void) const; //funciona tambien si no le ponemos virtual aca
		std::string getType() const; //funciona tambien si no le ponemos virtual aca
};
		
#endif

/*
//funciona tambien si no le ponemos virtual aca

DESTRUCTOR
Cuando se crea un objeto de tipo Dog, su destructor es llamado. 
Si el destructor de Animal no fuera virtual, solo se llamaría el destructor de Animal, no el destructor de Dog, 
lo que podría generar comportamientos inesperados, como no liberar correctamente los recursos asignados por la clase derivada.

Aunque Dog hereda de Animal, no es necesario marcar su destructor como virtual. 
El polimorfismo se maneja en la clase base (Animal) cuando la clase base tiene métodos virtuales, 
incluido el destructor. En este caso, el destructor de Animal es virtual, y esto ya garantiza el 
comportamiento correcto de la destrucción del objeto
*/