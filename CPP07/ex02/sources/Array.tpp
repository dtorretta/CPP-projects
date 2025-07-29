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
Array<T>::Array() : _ptr(NULL), _size(0)
{
	std::cout << BLUE << "Array Default Constructor called" << RESET << std::endl;
}

// Constructor
template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	_ptr = new T[size];
	for(unsigned int i = 0; i < size; i++)
	{
		_ptr[i] = T(); //inicializa cada elemento con el default constructor
	}
	std::cout << BLUE << "Array Constructor called" << RESET << std::endl;
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
    		this->_ptr[i] = copy._ptr[i]; //podria hacer _ptr[i] si tuviera la definicion de [] mas arriba
    	}
    	std::cout << BLUE << "Array Copy Constructor called" << RESET << std::endl;
    }
}

// The copy assignment operator copies the contents from one existing object to another existing object.
template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if(this != &copy)
	{
		delete[] this->_ptr; //1. liberar memoria
		this->_size = copy.size();
		this->_ptr = new T[this->_size]; //2. crear nuevo bloque
		for(unsigned int i = 0; i < this->_size; i++)//3. Copiar elemento por elemento 
    	{
    		this->_ptr[i] = copy._ptr[i];
    	}
		this->_size = copy.size();
		std::cout << BLUE << "Array Copy Operator called" << RESET << std::endl;
	}
	return(*this);
}

//destructor
template <typename T>
Array<T>::~Array()
{
	delete[] _ptr;
	std::cout << BLUE << "Array Destructor called" << RESET << std::endl;
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
	return "Index is out of bounds!";
}

//subscript operator
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size || _ptr == NULL)
        throw OutOfBoundsException();
    return _ptr[i];
}