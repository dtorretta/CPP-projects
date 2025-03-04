#include "../includes/Harl.hpp"

void Harl::debug(){
	std::cout << "🍔 I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do! 🍔" << std::endl;
}

void Harl::info(){
	std::cout << "🥓 I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! 🥓" << std::endl;
}

void Harl::warning(){
	std::cout << "💸 I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month. 💸" << std::endl;
}

void Harl::error(){
	std::cout << "🤬 This is unacceptable! I want to speak to the manager now. 🤬" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"}; //cada elemento en el array tiene un índice asociado automáticamente, empezando desde 0.
	
	void(Harl::*ptr_array[])() //podriamos ponerle [4] o no ya que lo infiere automaticamente
			= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level) //cuando i = 0, busca en el array_level y encuentra el string "DEBUG" y lo compara con level
		{
			(this->*ptr_array[i])();
			return;
		}	
	}
	std::cout << "🤷 He is probably complaining about something insignificant! 🤷" << std::endl; //llega aca cuando no encontro nada en el bucle for
}

/*
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

*/