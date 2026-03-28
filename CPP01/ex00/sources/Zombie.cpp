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
