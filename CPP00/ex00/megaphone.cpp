#include <iostream>
#include <cctype>
#include <string>

int main(int ac, char **av)
{
	int i = 0;
	size_t j = -1;
	
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	
	while(++i < ac)
	{
		std::string str = av[i]; 
		while(++j < str.size())
			std::cout << (char)std::toupper(str.at(j)); 
	}
	std::cout << std::endl;
	return (0);
}


//at() lanza una excepción std::out_of_range si intentas acceder a un índice fuera de los límites. simpelmente es una seguridad para hacer el codigo mas robusto