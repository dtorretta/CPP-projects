#include "../includes/HumanB.hpp"

HumanB::HumanB(const std::string& name) 
		: _name(name), _weapon(NULL) {}

void HumanB::attack() const
{
	if(_weapon)
		std::cout << _name << " attacks with their " << YELLOW << _weapon->getType() << RESET << std::endl;
	else    
		std::cout << RED << _name << " has no weapon to attack with!" << RESET << std::endl;
}

void HumanB::setWeapon (Weapon& weapon)
{
	_weapon = &weapon;
}
