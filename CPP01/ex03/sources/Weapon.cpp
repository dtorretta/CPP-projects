#include "../includes/Weapon.hpp"


Weapon::Weapon (const std::string &weapon) 
		: _type(weapon) {} //el formato : _type(weapon)  solo se puede usar en contructors

void Weapon::setType (const std::string& new_weapon) 
{
	_type = new_weapon;
}

const std::string& Weapon::getType()
{
	return(_type);
}

