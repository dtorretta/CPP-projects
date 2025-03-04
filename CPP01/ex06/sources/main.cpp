#include "../includes/harlFilter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Usage: ./harlFilter <Complain>" << RESET << std::endl;
		std::cout << "DEBUG - INFO - WARNING - ERROR" << std::endl;
		return 1;
	}
	std::string level = av[1];	
	harlFilter harl;	
	harl.complain(level);

    return 0;
}
