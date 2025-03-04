#include "../includes/Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *new_zombie = new Zombie(name); // Se crea un objeto Zombie en el heap y va a ser necesario liberar memoria
	if (new_zombie == NULL)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return NULL;
	}
	return (new_zombie);
}
