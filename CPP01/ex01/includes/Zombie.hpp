#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

class Zombie
{
	private:
		std::string _name;
		int index;
		
	public:
		Zombie();
		~Zombie( void ); 
		
		void announce(); 
		void set_name(std::string zombie_name);
};

Zombie* zombieHorde( int N, std::string name ); //poque esta fuera de la clase?
		
#endif