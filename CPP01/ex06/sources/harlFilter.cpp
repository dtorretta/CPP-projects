#include "../includes/harlFilter.hpp"

void harlFilter::debug(){
	std::cout << RED << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "🍔 I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do! 🍔\n" << std::endl;
}

void harlFilter::info(){
	std::cout << RED << "[ INFO ]" << RESET << std::endl;
	std::cout << "🥓 I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more! 🥓\n" << std::endl;
}

void harlFilter::warning(){
	std::cout << RED << "[ WARNING ]" << RESET << std::endl;
	std::cout << "💸 I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month. 💸\n" << std::endl;
}

void harlFilter::error(){
	std::cout << RED << "[ ERROR ]" << RESET << std::endl;
	std::cout << "🤬 This is unacceptable! I want to speak to the manager now. 🤬\n" << std::endl;
}

void harlFilter::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(harlFilter::*ptr_array[])()
			= {&harlFilter::debug, &harlFilter::info, &harlFilter::warning, &harlFilter::error};
	
	int iLevel = -1;
	for (int i = 0; i < 4; i++) //++i?
	{
		if (levels[i] == level)
		{
			iLevel = i;
			break;
		}	
	}
	std::cout << std::endl;
	switch(iLevel)
	{
		case 0:
			(this->*ptr_array[0])();
			//Fallthrough
		case 1:
			(this->*ptr_array[1])();
			//Fallthrough
		case 2:
			(this->*ptr_array[2])();
			//Fallthrough
		case 3:
			(this->*ptr_array[3])();
			break;
		default:
			std::cout << "🤷 He is probably complaining about something insignificant! 🤷\n" << std::endl;
	}
}	
