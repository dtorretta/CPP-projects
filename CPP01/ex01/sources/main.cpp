#include "../includes/Zombie.hpp"

int main(int ac, char **av)
{
	if(ac != 2 || std::atoi(av[1]) < 0)
	{
		std::cout << RED << "**Error**    Usage: ./MoarBrainz +N" << RESET << std::endl;
		exit (1);
	}
	if (std::atoi(av[1]) <= 0)
	{
		std::cout << BLUE << "\nNo zombies are coming... for now. 💀\n" << RESET << std::endl;
		exit(0);
	}
	std::cout << BLUE << "\n🌑🔮 Darkness falls across the land. The midnight hour is close at hand" << std::endl;
	std::cout << "Creatures crawl in search of blood to terrorize y'all's neighborhood 🔮🌑\n" << RESET << std::endl;
	
	Zombie *horde = zombieHorde(std::atoi(av[1]), "Zombie "); //creo un array de zombies y llamo a la fx donde le asigna memoria y los nombres
	std::cout << std::endl;
	
	for(int i = 0; i < std::atoi(av[1]); i++)
		horde[i].announce();
		
	std::cout << BLUE << "\n***🔥 The flames consume the zombies...***\n" << RESET << std::endl;
	delete [] horde;
	
	std::cout << BLUE << "\n***💀 The night is silent again... for now. 💀***\n" << RESET << std::endl;
	return 0;
}
