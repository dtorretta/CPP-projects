#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

class Weapon
{
	private:
		std::string _type;
		
	public:
		Weapon(const std::string &weapon);
		const std::string& getType();
		void setType (const std::string &new_weapon);
};
	
#endif
