#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
    public:
    	Contact    contact[8];
    	
    	int        index;
    	
    	PhoneBook();
    	
    	void       ft_add();
    	void       ft_search();
    	void       ft_printsearch();
};

#endif