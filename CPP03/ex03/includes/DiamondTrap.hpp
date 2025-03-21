#ifndef DIAMONTRAP_HPP
# define DIAMONTRAP_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
		
	public:
		DiamondTrap(void); // Default constructor
		DiamondTrap(const std::string name); 
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap& operator=(const DiamondTrap& copy);
		~DiamondTrap();
		
		//void attack(const std::string& target); //we use the one for ScavTrap
		using ScavTrap::attack;
		
		void whoAmI();
		std::string get_name() const;
};
		
#endif

/*
🛠️ Cómo Funciona la Herencia Virtual
📌 Sin virtual:

DiamondTrap heredaría dos copias separadas de ClapTrap: una desde ScavTrap y otra desde FragTrap.
Esto generaría ambigüedad porque DiamondTrap no sabría cuál ClapTrap usar.
📌 Con virtual:

Se asegura que ClapTrap exista solo una vez.
ScavTrap y FragTrap no inicializan ClapTrap, solo lo referencian.
La única copia de ClapTrap es controlada por DiamondTrap..

como VIRTUAL esta solo en ScavTrap y FragTrap

1️⃣ ClapTrap (una sola copia, gracias a virtual)
2️⃣ ScavTrap (hereda ClapTrap pero no lo inicializa)
3️⃣ FragTrap (hereda ClapTrap pero no lo inicializa)
4️⃣ DiamondTrap (inicializa ClapTrap)


Cuando Solo Tenías ClapTrap y ScavTrap:
Cuando solo tenías dos clases (ClapTrap y ScavTrap), y ambas tenían su propia versión de attack(), 
el polimorfismo ya estaba funcionando si ScavTrap heredaba de ClapTrap y la función attack() era sobreescrita en ScavTrap.

En este caso, si tú creabas un objeto de tipo ScavTrap y lo referenciabas o apuntabas como un ClapTrap, 
C++ utilizaba el polimorfismo implícito. Como ScavTrap sobrescribía la función attack(), 
C++ usaba la versión de attack() de ScavTrap cuando el objeto real era un ScavTrap.

ClapTrap: Tiene una función attack().
ScavTrap: Sobrescribe la función attack(). --> no necesita virtual
FragTrap: No tiene su propia versión de attack().
DiamondTrap: Hereda de ScavTrap y FragTrap.

si FragTrap tambien tuviera la funci9n entnces habria que agregar un virtual ya que DiamondTrap no sabria cual tomar
ClapTrap es la clase base y tiene la versión original de attack(). Debes hacerla virtual para habilitar el polimorfismo.

*/