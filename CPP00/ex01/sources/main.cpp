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


/*
			line.insert(0, 10 - line.length(), ' ');
			//line.append(10 - line.length(), ' ');
*/
/*
std::cin >> variable;
Este método lee una entrada hasta que encuentra un espacio en blanco, un tabulador o un salto de línea (\n)

el std::cin.ignore(); solo tiene sentido usarlo despues de std::cin. si uso getline o es necesario

*/

/*
magias de c++

cuando en el main ejecuto la linea PhoneBook phonebook;  esto autpomaticamente busca el constructor PhoneBook::PhoneBook() que dentro 
de este proyecto lo que hace es inicializar el index a -1

constructor: PhoneBook()
destructor: ~PhoneBook(): solo si tu clase usa memoria dinámica (new / delete) o si tiene pubnteros --> 

Contact* contacts; // Se usa memoria dinámica




*/