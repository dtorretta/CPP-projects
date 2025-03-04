#include "../includes/Zombie.hpp"

int main()
{
	std::cout << BLUE << "\n🌑🔮 Darkness falls across the land" << std::endl;
	std::cout << "The midnight hour is close at hand" << std::endl;
	std::cout << "*Heap allocated* creatures crawl in search of blood" << std::endl;
	std::cout << "To terrorize y'all's neighborhood 🔮🌑\n" << RESET << std::endl;
	
	Zombie* heapZombie1 = newZombie("Dazai");
	Zombie* heapZombie2 = newZombie("Mori sensei");
	
	heapZombie1->announce();
	heapZombie2->announce();
	
	std::cout << BLUE << "\n🌑🔮 The foulest stench is in the air" << std::endl;
	std::cout << "The funk of forty thousand years" << std::endl;
	std::cout << "And grizzly *stack allocated* ghouls from every tomb" << std::endl;
	std::cout << "Are closing in to seal your doom 🔮🌑\n" << RESET << std::endl;
	
	randomChump("Chuya");
	randomChump("Akutagawa");

	std::cout << BLUE << "\n***🔥 The flames consume the heap allocated zombies...***\n" << RESET << std::endl;
	delete heapZombie1;
	delete heapZombie2;
	
	std::cout << BLUE << "\n***💀 The night is silent again... for now. 💀***\n" << RESET << std::endl;
	return 0;
}
