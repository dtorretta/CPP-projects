/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:37:57 by dtorrett          #+#    #+#             */
/*   Updated: 2025/11/11 19:37:57 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Constructor
PmergeMe::PmergeMe(){}

// The copy constructor creates a new object as a copy of an existing object.
PmergeMe::PmergeMe(const PmergeMe& other) 
{
	_vec = other._vec;
	_deq = other._deq;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if(this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

//Destructor
PmergeMe::~PmergeMe() {}; 

//utils
void PmergeMe::addNumber(int n)
{
	_deq.push_back(n);
	_vec.push_back(n);
}

bool isValidPositiveInt(const std::string &s)
{
	if (s.empty())
		return false;

	//not spaces and not any sign at the beggining
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (!isdigit(s[i]))
			return false;
	}

	//to avoid overflow: manual convertion instead of just atoi
	long num = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		num = num * 10 + (s[i] - '0');
		if (num > INT_MAX)
			return false;
	}

	//positive integer
	if (num <= 0)
		return false;

	return true;
}

void PmergeMe::validate(const std::string &s) const
{
	if(!isValidPositiveInt(s))
		throw std::runtime_error("Error: invalid argument");
}

void PmergeMe::print(std::vector<int> container) const
{
	std::cout << "Before: ";
	printContainer(_vec);
	
	std::cout << "After: ";
	printContainer(container);
}

void PmergeMe::print(std::deque<int> container) const
{
	std::cout << "Before: ";
	printContainer(_deq);
	
	std::cout << "After: ";
	printContainer(container);
}


//---------------------------
//         DEQUE
//---------------------------

// Divide into pairs and sort each one, largest first
std::deque<Pairs> divideIntoPairsDeq(std::deque<int> deque, int &odd)
{
	std::deque<Pairs> pairs;
	std::deque<int>::iterator it;
	for(it = deque.begin(); it < deque.end() - 1; ++it)
	{
		int a = *it;
		++it;
		int b = *it;
		
		//largest first
		if (a < b)
			std::swap(a, b);
			
		Pairs p;
		p.L = a;
		p.S = b;
		pairs.push_back(p);
	}
	if (it == deque.end() - 1)
		odd = *it;
		
	return pairs;
}

void insertDeq(std::deque<int> &deqSorted, int number)
{
	int left = 0;
	int right = deqSorted.size();
	int newElem = -1;
	while(left < right)
	{
		newElem = number;
		int mid = (left + right) / 2;
		if(newElem < deqSorted[mid])
			right = mid;
		else
			left = mid + 1;
	}
	if (newElem == -1)
		throw std::runtime_error("Error: value not asigned");
		
	deqSorted.insert(deqSorted.begin() + left, newElem);
}

std::deque<int> PmergeMe::sortDeq(std::deque<int> deque) const
{
	if(deque.empty() || deque.size() == 1)
		return deque;
	 
	std::deque<Pairs> pairs;
	int odd = -1;
	pairs = divideIntoPairsDeq(deque, odd);
	 
	std::deque<int> deqSorted;
	std::deque<Pairs>::iterator it = pairs.begin();
	for(; it != pairs.end(); ++it)
		deqSorted.push_back(it->L);
	deqSorted = sortDeq(deqSorted); //recursive call
			
	for(it = pairs.begin(); it != pairs.end(); ++it) 
		insertDeq(deqSorted, it->S);
	if(odd != -1)
		insertDeq(deqSorted, odd);
	
	return deqSorted;
}

//---------------------------
//         VECTOR
//---------------------------

// Divide into pairs and sort each one, largest first
std::vector<Pairs> divideIntoPairs(std::vector<int> vector, int &odd)
{
	std::vector<Pairs> pairs;
	std::vector<int>::iterator it;
	for(it = vector.begin(); it < vector.end() - 1; ++it)
	{
		int a = *it;
		++it;
		int b = *it;
		
		//largest first
		if (a < b)
			std::swap(a, b);
			
		Pairs p;
		p.L = a;
		p.S = b;
		pairs.push_back(p);
	}
	if (it == vector.end() - 1)
		odd = *it;
		
	return pairs;
}

void insert(std::vector<int> &vecSorted, int number)
{
	int left = 0;
	int right = vecSorted.size();
	int newElem = -1;
	while(left < right)
	{
		newElem = number;
		int mid = (left + right) / 2;
		if(newElem < vecSorted[mid])
			right = mid;
		else
			left = mid + 1;
	}
	if (newElem == -1)
		throw std::runtime_error("Error: value not asigned");

	vecSorted.insert(vecSorted.begin() + left, newElem);
}

std::vector<int> PmergeMe::sortVec(std::vector<int> vector) const
{   
	if(vector.empty() || vector.size() == 1)
		return vector;
	 
	//1. Divide into pairs and sort each one, bigger first
	std::vector<Pairs> pairs;
	int odd = -1;
	pairs = divideIntoPairs(vector, odd);

	//2. vecSorted will store the largest value of each pair. Calling the same function recursively with vecSorted creates the sorted sequence
	std::vector<int> vecSorted;
	std::vector<Pairs>::iterator it = pairs.begin();
	for(; it != pairs.end(); ++it)
		vecSorted.push_back(it->L);
	vecSorted = sortVec(vecSorted); //recursive call
			
	//3. Insert the smaller values using binary insertion.     
	for(it = pairs.begin(); it != pairs.end(); ++it) 
		insert(vecSorted, it->S);
	if(odd != -1)
		insert(vecSorted, odd);
		
	return vecSorted;   
}

//Getter
std::vector<int> PmergeMe::getVec() {return _vec;} 
std::deque<int> PmergeMe::getDeq() {return _deq;} 



