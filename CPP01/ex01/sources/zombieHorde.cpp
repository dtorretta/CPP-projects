#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N]; // Crear un array de Zombies --> char **array
	if (horde == NULL)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return NULL;
	}
	
	std::cout << std::endl;
	std::cout << N << " zombies are comming..." << std::endl;
	
	for (int i = 0; i < N; i++)
	{
		std::ostringstream concatenated;
		concatenated << name << i + 1;
		std::string zombieName = concatenated.str();
		horde[i].set_name(zombieName); //para cada elemento del str llamo a la funcion set name	    
	}
	return (horde);
}

/*
para concatenar strings simplemente hago 
std::string newString = str1 + str2; 

para insertar un/unos chars en un string:
str.insert;

para unir un STR con un INT:
std::ostringstream buff; // en lugar de enviar los datos a la salida estándar (std::COUT) los almacena en un buffer interno.
buff << str << i;
std::string zombieName = concatenated.str();  //name.STR() obtengo la cadena de texto acumulada en ese buffer interno.

para crear un array de str
Class *nameArray = new Class[N strings]; 

cuando asigno memoria con *new*, tengo que eliminarla con *delete*
si lo que quiero eliminar es un array: delete [] array;
*/