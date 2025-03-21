#ifndef CAT_HPP
# define CAT_HPP

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

class Cat: virtual public Animal
{
	private:
		Brain *_brain; //si o si pointer porque esto acepta que en el contructor sea asignado como NULL
		//en este caso dentro del contructor SI usamos new Brain porque si no no se aloca memoria en ningun otro lado
		
	public:
		Cat(void); // Default constructor
		Cat(const Cat& copy); // Copy constructor 
		Cat& operator=(const Cat& copy); // Copy assignment operator
		~Cat(void); //funciona tambien si no le ponemos virtual aca

		void makeSound() const; //funciona tambien si no le ponemos virtual aca
		std::string getType() const; //funciona tambien si no le ponemos virtual aca
		void setIdea (int i, std::string idea);
		std::string getIdea (int i);
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