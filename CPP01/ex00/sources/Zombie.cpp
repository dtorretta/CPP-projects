#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string zombie_name)
{
	_name = zombie_name;
	std::cout << "Zombie " << _name << " is coming...\n" << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << RED << "Zombie " << _name << " is dead...\n" << RESET << std::endl;
}

void Zombie::announce( void )
{
	std::cout << _name  << YELLOW << ": BraiiiiiiinnnzzzZ...\n" << RESET  << std::endl;
}

/*
randomChump: crea un objeto en el stack (porque solo lo usamos dentro de esta funcion) por lo que NO es necesario liberar memoria
el destructor se va a ejecutar automaticamente

newZombie: cuando usamos new pra crear un objeto este se asigna dinamicamente en el heap y va a ser necesario liberar memoria
Se debes liberar esa memoria manualmente usando delete

al final del main:
delete myZombie;  // Esto ejecutará el destructor y liberará la memoria
*/