#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream> 

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define RESET	"\033[0m"

class Replace
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
		
	public:
		Replace(const std::string file, const std::string s1, const std::string s2);
		std::string getString (const std::string str);
		std::string ft_replace (const std::string line); //const?
		
};
		
#endif

