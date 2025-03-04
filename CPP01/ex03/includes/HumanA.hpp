#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> 
#include "Weapon.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon; // necesita ser & porque en main cambio el valor de weapon.
		
	public:
		HumanA(const std::string& name, Weapon& weapon); //si o si const ya que el string en main es por defecto const
		void attack() const;  //sin el const no funciona
};
		
#endif

/*
como mi atributo privado es Weapon &_weapon; (es una referencia, y NO un objeto completo)
esto signfica que se puede modificar el objeto original al que _weapon hace referencia. 
Es decir, si en otro lugar de tu código cambias ese objeto Weapon, también cambiará lo que tiene _weapon, porque no tiene una copia propia, sino que apunta al objeto original.

por ende NO PUEDO definir este atributo en mi constructor como const
OK --> HumanA(const std::string& name, Weapon& weapon);
NO --> HumanA(const std::string& name, CONST Weapon& weapon);


PORQUE Weapon &_weapon; COMO REFERENCIA?
necesita ser & porque en main cambio el valor de weapon.
si no fuera un atributo & entonces en su creacion se pasaria una copia,e tnonces en main cuando cambio el type del objeto
este no se veria reflejado en esta parte, y por ende el getType no se actualizaria.


*/