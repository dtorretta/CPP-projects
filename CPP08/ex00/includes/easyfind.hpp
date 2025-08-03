#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class NoOccurrence : public std::exception //no puedo agregarlo dentro del template
{
	public:
		const char* what() const throw()
		{
		    return "\n❌ No occurrence founded!";
		}
};
		
template <typename T> // T representa el tipo del contenedor. ej: std::vector<int>
typename T::iterator easyfind(T& container, int value) 
{
    //esto equivale a decir *it = 
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if(it == container.end())
        throw NoOccurrence();
    return it;
}

/*escribir "typename T" es basicamente el comodin
lo importante aca es que el retorno es un algoritmo "iterator"
Queremos devolver un iterador que apunta al número buscado dentro del contenedor.
RETORNA UN POINTER

container.end() --> no es el ultimo elemento del array sino el NULL final

ITERADOR == equivale a puntero en C
*/