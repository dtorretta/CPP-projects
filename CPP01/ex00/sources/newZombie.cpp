#include "../includes/Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *new_zombie = new Zombie(name);
	if (new_zombie == NULL)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return NULL;
	}
	return (new_zombie);
}
