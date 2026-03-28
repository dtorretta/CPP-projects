#include "../includes/Zombie.hpp"

void randomChump( std::string name )
{
	Zombie temporal_zombie(name);
	temporal_zombie.announce();
}
