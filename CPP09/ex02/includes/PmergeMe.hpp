#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <string>
#include <climits>
# include <sstream>
# include <algorithm>
# include <cctype>


#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

struct Pairs
{
	int L; //larger
	int S; //smaller
	Pairs() : L(-1), S(-1) {} //default constructor
};


class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
	
	public:
		PmergeMe(); //Default Constructor
		PmergeMe(const PmergeMe& other); //Copy constructor
		PmergeMe& operator=(const PmergeMe& other); //Copy assignment operator
		~PmergeMe(); //Destructor
		
		//Methods
		void addNumber (int n);
		void validate(const std::string &s) const;
		void print(std::vector<int> container) const;
		void print(std::deque<int> container) const;
		void printTime(std::string str, int start_time, int end_time) const;
		
		std::vector<int> sortVec(std::vector<int> vector) const;
		std::deque<int> sortDeq(std::deque<int> deque) const;
		
		//getter
		std::vector<int> getVec();
		std::deque<int> getDeq();
};

template <typename T>
void printContainer(const T &container)
{
	typename T::const_iterator it = container.begin();
	typename T::const_iterator end = container.end();

	for (; it != end; ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

template <typename C>
bool isSorted(const C& container)
{
	for (typename C::const_iterator it = container.begin(); it + 1 != container.end(); ++it)
	{
		if (*it > *(it + 1))
			return false;
	}
	return true;
}


