#include "../includes/Zombie.hpp"

void randomChump( std::string name )
{
	//es lo mismo que hacer Zombie temporal = Zombie(name), pero + eficiente
	Zombie temporal_zombie(name); // Creación de un objeto en el stack (porque solo lo usamos dentro de esta funcion) por lo que ni es necesario liberar memoria
	temporal_zombie.announce();
}
