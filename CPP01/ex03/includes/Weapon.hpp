#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

class Weapon
{
	private:
		std::string _type;
		
	public:
		Weapon(const std::string &weapon);
		const std::string& getType(); //en main el objeto CLUB de la class Weapon no esta definido como const, entonces no es necesario el segundo const
		void setType (const std::string &new_weapon); //el const es solo una buena practica / & evita que se haga una copia de la nueva arma, tambien podria haber usado puntero
};
	
#endif
		
/*
La palabra clave const al final indica que la función no modificará ningún miembro de la clase.

el objeto de la clase es el nuevo nodo

Si CLUB fuera definido como const, entonces la fx getType() tambien deberia ser const, si no no me permitiria acceder a la variable _type (porque esta dentro de un objeto const)
Si un objeto es const, todas las funciones miembro que accedan a sus atributos deben ser const
de todos modos si le agrego const va a funcionar bien y va a servir si en un futuro defino un objeto const.

const std::string& getType() --> const std::string& WEAPON::getType()
el nombre de la clase siempre va antes del nombre de la funcion

el formato : _type(weapon)  solo se puede usar en contructors

El & indica que estamos pasando una "referencia" a la variable que contiene el valor. 
Pasar un valor por referencia significa que NO estamos copiando el valor que se pasa como argumento. En vez de eso, estamos trabajando directamente con el valor original

en c++ todo lo que escriba "hello world" siempre va a ser un CONST char*

siempre que tenga atributos PRIVATE estos tienen que inicializarse de alguna manera en el cosntructor. no puedo soklamente tener como atributo alguno de ellos (humanB)
solucion:
Weapon _weapon; -->  Weapon *_weapon;  USAR POINTER
en C++, los punteros no necesitan ser inicializados explícitamente en el constructor (aunque es una buena práctica inicializarlos para evitar problemas).
Si no los inicializas explícitamente, se les asigna un valor predeterminado como NULL.

CONSTRUCTOR:
HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}    // el null final es una buena practica

en main, en humanB primero estoy creando un objeto de la clase weapon, es decir, ya tengo un nodo.
Este sera pasado como parametro a la funcion setWeapon, por eso esta fx tiene que poder recibir la un pointer a la clase.
En este caso funciona como en C donde creabamos un nodo que estaba declarado sin puntero, y de ahi en mas, las demas funciones que lo recibian
como parametro, esperaban un pointer

Si en vez de pointer decidiera usar &, tendria que crear un nuevo nodo y asignarle memoria


HumanA:
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