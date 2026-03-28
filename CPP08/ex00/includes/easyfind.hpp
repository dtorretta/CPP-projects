#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class NoOccurrence : public std::exception
{
	public:
		const char* what() const throw()
		{
		    return "\n❌ No occurrence founded!";
		}
};
		
template <typename T> 
typename T::iterator easyFind(T &container, int value) 
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if(it == container.end())
        throw NoOccurrence();
    return it;
}
