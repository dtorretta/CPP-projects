#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m" 
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class ClapTrap
{
	protected: //CUAL ES LA DIFENCIA CON PRIVATE?
		std::string _name;
		unsigned int _Hitpoints;
		unsigned int _Energypoints;
		unsigned int _Attackdamage;
		
	public:
		ClapTrap(void); // Default constructor
		ClapTrap(const std::string name); 
		ClapTrap(const ClapTrap& src); // Copy constructor 
		ClapTrap& operator=(const ClapTrap& src); // Copy assignment operator
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		//getter
		unsigned int get_hitpoints() const;
		unsigned int get_energypoints() const;
		unsigned int get_attackdamage() const;
		std::string get_name() const;
		//void setRawBits(int const raw);
};
		
#endif

/*
PRIVATE: no puedo acceder desde ScavTrap
*/