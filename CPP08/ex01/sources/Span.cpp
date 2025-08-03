/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/07/31 14:08:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

// Constructor
Span::Span(unsigned int size) : _size(size) {}

// The copy constructor creates a new object as a copy of an existing object.
Span::Span(const Span& copy): _size(copy.getSize()) {}

// The copy assignment operator copies the contents from one existing object to another existing object.
Span& Span::operator=(const Span& copy)
{
	if(this != &copy)
		this->_size = copy.getSize();
	return(*this); //this es un puntero entonces si retornamos *this lo estamos desreferenciando para acceder a su objeto
}

//destructor
Span::~Span() {}

//exceptions
const char* Span::NoMoreSpace::what() const throw()
{
	return "Container is already full!";
}

const char* Span::NoSpanFound::what() const throw()
{
	return "Not enough numbers stored to compute a span!";
}

//member function

void Span::addNumber(int value)
{
	if (_Array.size() >= _size)
		throw NoMoreSpace();
	_Array.push_back(value);
}

int Span::longestSpan()
{
	if (_Array.size() < 2)
		throw NoSpanFound();
		
	std::sort(_Array.begin(), _Array.end()); //1. sort	
	int minValue = _Array[0];	
	int maxValue = *std::max_element(_Array.begin(), _Array.end());

	return(maxValue - minValue);
}
int Span::shortestSpan()
{
	if (_Array.size() < 2)
		throw NoSpanFound();
	std::sort(_Array.begin(), _Array.end()); //1. sort
	std::vector<int> temp(_Array.size()); //2. create a temporal vector with the same size as _Array
	std::adjacent_difference(_Array.begin(), _Array.end(), temp.begin()); //3. store in temp the spans
	temp.erase(temp.begin()); //4. delete de first element of temp
	std::sort(temp.begin(), temp.end()); //5. sort temp vector to get the shorter
	      
	return(temp[0]);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t rangeSize = std::distance(begin, end); //averiguar el rango
	if(_Array.size() + rangeSize > _size)
		throw NoMoreSpace();
	_Array.insert(_Array.end(), begin, end);
}

//getter
unsigned int Span::getSize(void) const
{
	return(this->_size);
}

void Span::printElements() const 
{
    for (size_t i = 0; i < _Array.size(); ++i)
        std::cout << _Array[i] << std::endl;
}
