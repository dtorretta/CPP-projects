#include "../includes/Phonebook.hpp"

void PhoneBook::ft_add()
{
	Contact newCont;

	newCont.get_firstname();
	newCont.get_lastname();
	newCont.get_nickname();
	newCont.get_phone();
	newCont.get_secret();

	this->index = (this->index + 1) % 8; // Incrementa el índice y vuelve a 0 si llega a 8
	this->contact[this->index] = newCont;

	std::cout << "\033[32m\nContact added successfully!\033[0m" << std::endl;
}

void PhoneBook::ft_printsearch()
{
	//std::string str;
	int j = 0;
	
	while (1)
	{
		std::cout << std::endl;
		std::cout << "\033[36mEnter the index of the contact you want to view or 0 to return to menu: \033[0m";
		std::cin >> j;
		std::cin.ignore();
		
		if (j == 0)
			break;
		if (j > 0 && j < 9 && !this->contact[--j].firstName.empty())
		{
			std::cout << "\nFirst Name: \033[33m" << this->contact[j].firstName << std::endl;
			std::cout << "\033[0mLast Name: \033[33m" << this->contact[j].lastName << std::endl;
			std::cout << "\033[0mNickname: \033[33m" << this->contact[j].nickname << std::endl;
			std::cout << "\033[0mPhone Number: \033[33m"<< this->contact[j].phoneNumber << std::endl;
			std::cout << "\033[0mDarkest Secret: \033[33m" << this->contact[j].darkestSecret << "\033[0m" << std::endl;
			break;
		}
		std::cout << std::endl;
		std::cout << "\033[31mError: incorrect index number.\033[0m" << std::endl;
	}
}

void PhoneBook::ft_search()
{
	std::string line;
	int i = -1;
	int limit = 8;
	
	std::cout << std::endl; 
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	while(++i < limit && !this->contact[i].firstName.empty())
	{
		std::cout << "         " << i + 1;
		this->contact[i].print_firstname();
		this->contact[i].print_lastname();
		this->contact[i].print_nickname();
	}
	this->ft_printsearch();
}

PhoneBook::PhoneBook() : index(-1) {
}
