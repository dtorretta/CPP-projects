#include "../includes/Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << YELLOW << "A zombie has risen from the grave 🪦" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << _name << " is dead..." << RESET << std::endl;
}

void Zombie::announce()
{
	std::cout << _name << ": " << YELLOW << "BraiiiiiiinnnzzzZ..." << RESET  << std::endl;
}

void Zombie::set_name(std::string zombie_name)
{
	this->_name = zombie_name;
}
