#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> 
#include "Weapon.hpp"

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
		
	public:
		HumanB(const std::string& name);
		void setWeapon (Weapon& weapon);
		void attack() const;
};
		
#endif
