#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

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

class harlFilter
{
	private:
		void debug();
		void info();
		void warning();
		void error();
		
	public:
		void complain(std::string level);
};
		
#endif
