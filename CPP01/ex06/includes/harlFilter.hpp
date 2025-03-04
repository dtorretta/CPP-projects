#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

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

class harlFilter
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
el "switch" se refiere a una sentencia de control de flujo en C++ que permite elegir entre varias opciones posibles 
basadas en el valor de una variable o expresión.

fallthrough:
si no colocas un break, el flujo de control continuará ejecutando los siguientes case a medida que se vayan encontrando.
la version 98 pide que explicitamente agreguemos el comentario // Fallthrough para evitar los warning
*/

