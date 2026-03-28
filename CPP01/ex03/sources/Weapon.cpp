#include "../includes/Weapon.hpp"


Weapon::Weapon (const std::string &weapon) 
		: _type(weapon) {}

void Weapon::setType (const std::string& new_weapon) 
{
	_type = new_weapon;
}

const std::string& Weapon::getType()
{
	return(_type);
}

