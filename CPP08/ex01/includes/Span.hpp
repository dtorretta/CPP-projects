#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>
#include <numeric>
#include <climits>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"


class Span
{
    private:
        unsigned int _size;
        std::vector<int> _Array;
        
    public:
        Span(unsigned int size); //Constructor
        Span(const Span& other); // Copy constructor
		Span& operator=(const Span& other); // Copy assignment operator
		~Span(); //destructor
		
        //exception
        class NoMoreSpace : public std::exception
        {
        	public:
        		const char* what() const throw();
        };
        
        class NoSpanFound : public std::exception
        {
        	public:
        		const char* what() const throw();
        };
        
        //getter
        unsigned int getSize(void) const;
        void printElements() const;
        
        //member function
        void addNumber(int value);
        int shortestSpan();
        int longestSpan();
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        
};
