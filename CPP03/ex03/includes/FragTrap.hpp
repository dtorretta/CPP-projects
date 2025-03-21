#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

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

class FragTrap : virtual public ClapTrap //AGREGAMOS VIRTUAL
{
	protected:
		unsigned int _Hitpoints;
		unsigned int _Attackdamage;
		
	public:
		FragTrap(void); // Default constructor
		FragTrap(const std::string name); // Name constructor
		FragTrap(const FragTrap& copy); // Copy constructor
		FragTrap& operator=(const FragTrap& src); // Copy assignment operator
		~FragTrap();
		
		void highFivesGuys(void);
		
		//getter
		unsigned int get_hitpoints() const;
		unsigned int get_attackdamage() const;

};
		
#endif

/*
class ScavTrap : virtual public ClapTrap
Cuando no usamos virtual, DiamondTrap heredaría dos veces ClapTrap porque tanto ScavTrap como FragTrap lo heredan. 
Esto causaría duplicación de atributos y métodos dentro de DiamondTrap, generando ambigüedad y errores de compilación.

Para evitar esto, usamos herencia virtual en ScavTrap y FragTrap al heredar de ClapTrap:
Esto significa que DiamondTrap tendrá dos veces los atributos _Hitpoints, _Energypoints, _Attackdamage,

Cuando agregamos virtual en la herencia de ScavTrap y FragTrap, indicamos que ClapTrap debe existir solo una vez, 
sin importar cuántas clases lo hereden.


porque ahora agregamos atributos protected:

En el primer ejercicio no es necesario agregar los atributos como protected en FragTrap 
porque esos atributos ya se definen en la clase base ClapTrap, y solo necesitas sobrescribir sus valores en el constructor de FragTrap.

En el segundo ejercicio (cuando tienes múltiples clases base), es necesario declarar los atributos como protected 
para asegurar que las clases derivadas (como DiamondTrap) tengan acceso a ellos. 
Esto ocurre porque tienes más de una clase base, y quieres poder modificar o acceder a estos atributos 
de forma segura dentro de las clases derivadas.

*/