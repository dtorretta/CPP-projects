#include "../includes/Phonebook.hpp"


void Contact::get_firstname()
{
	std::cout << "\nFirst name: ";
	std::getline(std::cin, this->firstName);
	while(this->firstName.empty())
	{
		std::cout << "\n\033[31mError: First name cannot be empty.\033[0m\n" << std::endl;
		std::cout << "First name: ";
		std::getline(std::cin, this->firstName);
	}
}

void Contact::get_lastname()
{
	std::cout << "Last name: ";
	std::getline(std::cin, this->lastName);
	while(this->lastName.empty())
	{
		std::cout << "\n\033[31mError: Last name cannot be empty.\033[0m\n" << std::endl;
		std::cout << "Last name: ";
		std::getline(std::cin, this->lastName);
	}
}

void Contact::get_nickname()
{
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname);
	while(this->nickname.empty())
	{
		std::cout << "\n\033[31mError: Nickname cannot be empty.\033[0m\n" << std::endl;
		std::cout << "Nickname: ";
		std::getline(std::cin, this->nickname);
	}
}

static bool ft_is_all_digits(const std::string &str)
{
	size_t i = -1;
	
	while(++i < str.length())
	{
		if(!isdigit(str[i]))
			return (false);
	}
	return(true);
}

void Contact::get_phone()
{
	std::cout << "Phone number: ";
	std::getline(std::cin, this->phoneNumber);
	while(this->phoneNumber.empty() || !ft_is_all_digits(this->phoneNumber))
	{
		if(!ft_is_all_digits(this->phoneNumber))
			std::cout << "\n\033[31mError: Only numbers.\033[0m\n" << std::endl;
		else
			std::cout << "\n\033[31mError: Phone number cannot be empty.\033[0m\n" << std::endl;
		std::cout << "Phone number: ";
		std::getline(std::cin, this->phoneNumber);
	}
}

void Contact::get_secret()
{
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->darkestSecret);
	while(this->darkestSecret.empty())
	{
		std::cout << "\n\033[31mError: Darkest secret cannot be empty.\033[0m\n" << std::endl;
		std::cout << "Darkest secret: ";
		std::getline(std::cin, this->darkestSecret);
	}
}

void Contact::print_firstname()
{
	std::string line;
	
	if(this->firstName.length() > 10)
	{
		line = this->firstName.substr(0,9);
		line.append(1 , '.');
	}
	else
	{
		line = this->firstName.substr(0,10);
		if (line.length() < 10)
			line.insert(0, 10 - line.length(), ' ');
	}
	std::cout << "|" << line << "|";
}

void Contact::print_lastname()
{
	std::string line;
	
	if(this->lastName.length() > 10)
	{
		line = this->lastName.substr(0,9);
		line.append(1 , '.');
	}
	else
	{
		line = this->lastName.substr(0,10);
		if (line.length() < 10)
			line.insert(0, 10 - line.length(), ' ');
	}
	std::cout << line << "|";
}

void Contact::print_nickname()
{
	std::string line;
	
	if(this->nickname.length() > 10)
	{
		line = this->nickname.substr(0,9);
		line.append(1 , '.');
	}
	else
	{
		line = this->nickname.substr(0,10);
		if (line.length() < 10)
			line.insert(0, 10 - line.length(), ' ');
	}
	std::cout << line << std::endl; 
}
