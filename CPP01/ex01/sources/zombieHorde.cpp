#include "../includes/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	if (horde == NULL)
	{
		std::cerr << "Memory allocation failed" << std::endl;
		return NULL;
	}
	
	std::cout << std::endl;
	std::cout << N << " zombies are comming..." << std::endl;
	
	for (int i = 0; i < N; i++)
	{
		std::ostringstream concatenated;
		concatenated << name << i + 1;
		std::string zombieName = concatenated.str();
		horde[i].set_name(zombieName);
	}
	return (horde);
}
