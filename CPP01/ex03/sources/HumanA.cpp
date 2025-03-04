#include "../includes/HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack() const
{
	std::cout << _name << " attacks with their " << YELLOW << _weapon.getType() << RESET << std::endl;
}

