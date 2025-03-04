#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
		
	public:
		void complain(std::string level);
		
};
		
#endif


/*
*******HARL.cpp****

void(Harl::*ptr_array[])() = {}
void --> la funcion almacenada en el array no tiene retorno, todas las funciones (info, warning etc, son void)

(Harl::*)() --> esta es la forma de usar punteros a metodos (fx) de una clase. en C directamente usariamos *
ptr_array[] --> declaro dentro de esta misma linea un array de pointers. empezando desde el 0 al 3 cada level apunta a una funcion de la clase
= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error} --> inicializamos el array para cada posicion (de 0 a 3) con la funcion asociada
& --> cuando trabajamos con funciones que son miembros de una clase, para referirnos a una función miembro sin ejecutarla, usamos & para obtener su dirección.

al final de la ejecucion, el pointer *ptr_array solamente va a apuntar a una funcion:
void (*ptr_array)() = &myFunction;
para ejecutar la funcion, llamo al pointer
ptr_array();
(en C es distinto ya que no hace falta usar &)

dentro del bucle for:
(this->*ptr_array[i])();

this-> es necesario cuando queremos acceder a pointers dentro de una clase. en general para los otros casos el complilador lo infiere automaticamente
por eso no lo agregamos, pero cuando se trata de pointers a funciones miebro es obnligatorio

*ptr_array --> Un puntero a una función miembro no es igual a un puntero a una función normal. sin el * el compilador considera que estas
accediendo a una funcion normal que NO forma parte de la clase
basicamente el * DESREFERENCIA el pointer, es decir, acceder al valor o al objeto al que ese puntero apunta. 
Cuando trabajas con punteros, no estás manejando directamente el objeto o valor al que apuntan, sino solo la dirección de memoria donde se encuentra


*******MAIN.cpp*******

si  void complain( std::string level ); fuera STATIC, podria llamarla en el main mas facilmente:
Harl::complain(level);

pero como no es static tengo que crear un objeto de la clase y ahi llamar a la funcion 
harl.complain(level);

*/

