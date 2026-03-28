#include "../includes/Phonebook.hpp"

int main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << "\033[31m\n**Error**\033[0m\n" << std::endl;
		exit (EXIT_FAILURE);
	}
	PhoneBook phonebook;
	std::string command;
	
	while (1)
	{
		std::cout << "\033[36m\nPlease select ADD, SEARCH or EXIT: \033[0m";	
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.ft_add();
		else if (command == "SEARCH")
			phonebook.ft_search();
		else if (command == "EXIT")
			break;
		else
			std::cout << "\033[31m\nInvalid command. Please try again.\033[0m" << std::endl;
	}
	return (0);
}
