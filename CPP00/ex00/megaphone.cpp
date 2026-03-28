#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **av)
{
	int i;
	int j = 0;
	
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while(av[++j])
	{
		i = -1;
		while(av[j][++i])
			std::cout << (char)toupper(av[j][i]); 
	}
	std::cout << std::endl;
	return (0);
}
