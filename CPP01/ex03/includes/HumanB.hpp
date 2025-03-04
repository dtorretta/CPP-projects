#ifndef HUMANB_HPP
# define HUMANB_HPP

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

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon; //si o si pointer porque esto acepta que en el contructor sea asignado como NULL
		
	public:
		HumanB(const std::string& name); //si o si const ya que el string en main es por defecto const // el const de weapon es por buena practica
		void setWeapon (Weapon& weapon);
		void attack() const; //sin el const no funciona??
};
		
#endif

/*

siempre que tenga atributos PRIVATE estos tienen que inicializarse de alguna manera en el cosntructor. no puedo soklamente tener como atributo alguno de ellos (humanB)
solucion:
Weapon _weapon; -->  Weapon *_weapon;  USAR POINTER
en C++, los punteros no necesitan ser inicializados explícitamente en el constructor (aunque es una buena práctica inicializarlos para evitar problemas).
Si no los inicializas explícitamente, se les asigna un valor predeterminado como NULL.


void setWeapon (Weapon& weapon);
podria haber sido pointer si en el main tuviera jim.setWeapon(*club);   pero como no puedo cambiar el main, no puedo usar pointer y uso referencia

pero aca viene el tema, la clase HumanB tiene un elemnto weapon con pointer
Weapon *_weapon;
pero en la funcion espera recibir un elemento con referencia
void setWeapon (Weapon& weapon);
para solucionar esto, dentro de la fx tengo que volver a usar &
_weapon = &weapon;       // si pusiera solo _weapon = weapon;  no funcionaria

esto es como en C cuando por ejemplo en ft_swap

void ft_swap (int *a, int *b) {}

main (void)
{
	int a = 1;
	int b = 2;
	ft_swap(&a, &b);  //como estoy enviado int a algo que espera recibir int*, tengo que usar &
}
*/