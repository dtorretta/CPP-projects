/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:18:11 by marvin            #+#    #+#             */
/*   Updated: 2025/07/29 17:18:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Default constructor
template <typename T>
Array<T>::Array() : _ptr(NULL), _size(0) {}

// Constructor
template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	_ptr = new T[size];
	for(unsigned int i = 0; i < size; i++)
	{
		_ptr[i] = T();
	}
}

// The copy constructor creates a new object as a copy of an existing object.
template <typename T>
Array<T>::Array(const Array<T>& copy): _size(copy.size())
{
    if(this->_size > 0)	
    {
    	this->_ptr = new T[this->_size];
    	for(unsigned int i = 0; i < this->_size; i++)
    	{
    		this->_ptr[i] = copy._ptr[i];
    	}
    	std::cout << BLUE << "Copy Constructor called" << RESET << std::endl;
    }
}

// The copy assignment operator copies the contents from one existing object to another existing object.
template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if(this != &copy)
	{
		delete[] this->_ptr;
		this->_size = copy.size();
		this->_ptr = new T[this->_size];
		for(unsigned int i = 0; i < this->_size; i++)
    	{
    		this->_ptr[i] = copy._ptr[i];
    	}
		this->_size = copy.size();
		std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	}
	return(*this);
}

//destructor
template <typename T>
Array<T>::~Array()
{
	delete[] _ptr;
} 

//member functions
template <typename T>
unsigned int Array<T>::size() const
{
	return(this->_size);
}

//exceptions
template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return " index is out of bounds!";
}

//subscript operator
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size || _ptr == NULL)
        throw OutOfBoundsException();
    return _ptr[i];
}