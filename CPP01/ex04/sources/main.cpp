#include "../includes/Replace.hpp"



int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if(std::string(av[2]) == "" || std::string(av[2]) == std::string(av[3]))
	{
		std::cout << RED << "nothing to replace!" << RESET << std::endl;
		return 1;
	}
	
	std::ifstream fd(av[1]); //es lo mismo que hacer       std::ifstream fd;   |     fd.open(av[1]);
	if(!fd.is_open())
	{
		std::cout << RED << "Error opening file!" << RESET << std::endl;
		return 1;
	}
		
	Replace sed = Replace(av[1], av[2], av[3]);
	
	std::string line;
	std::string result;
	std::string outputFile_name = sed.getString("name") + ".replace";
	std::ofstream outputFile(outputFile_name.c_str()); //como estamos en v98 tengo queagregar el .c_str() que lo convierte en un const char*
	
	if(!outputFile.is_open())
	{
		std::cout << RED << "Error opening output file!" << std::endl;
		return 1;
	}
	
	while(std::getline(fd, line)) //automaticamente lee una nueva linea con cada llamado
	{
		result = sed.ft_replace (line);
		outputFile << result << std::endl;
	}
	
	fd.close();
	outputFile.close();
	return 0;
}
