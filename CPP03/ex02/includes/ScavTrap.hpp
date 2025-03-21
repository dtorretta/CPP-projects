#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 
#include "ClapTrap.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class ScavTrap : public ClapTrap //ScavTrap es una clase derivada de ClapTrap, es decir, ScavTrap hereda de ClapTrap.
{
	public:
		ScavTrap(void); // Default constructor
		ScavTrap(const std::string name); 
		ScavTrap(const ScavTrap& src); // Copy constructor 
		ScavTrap& operator=(const ScavTrap& src); // Copy assignment operator
		~ScavTrap();

		void attack(const std::string& target); //sobreescribe el metodo ATTACK de ClapTrap.
		void guardGate(); //agrega nuevos metodos
};
		
#endif

/*
class ScavTrap : public ClapTrap
La palabra clave public indica que la herencia es pública, 
lo que implica que los miembros públicos y protegidos de la clase base ClapTrap son accesibles desde la clase derivada ScavTrap.

*/