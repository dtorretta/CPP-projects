#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <vector> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

class Zombie
{
	private:
		std::string _name;
		
	public:
		void announce( void ); 
		Zombie(std::string zombie_name); //porque si name es privada, ouedo asignarle valor con esta fx
		//Zombie* newZombie( std::string name );
		//void randomChump( std::string name );
		~Zombie( void ); 
};

Zombie* newZombie( std::string name ); //poque esta fuera de la clase?
void randomChump( std::string name );//poque esta fuera de la clase?
		
#endif