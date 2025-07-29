#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <string>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

template <typename T>
class Array
{
    private:
        T* _ptr;
        unsigned int _size;
        
    public:
        Array(); //Default constructor
        Array(unsigned int size); //Constructor
        Array(const Array<T>& copy); // Copy constructor
		Array<T>& operator=(const Array& copy); // Copy assignment operator
		~Array(); //destructor
		
		//subscript operator
		T& operator[](unsigned int i);
		/*no pongo int& porque quiero hacer un template que permita todo. 
		Significa "Devuelvo una referencia al tipo T que el usuario eligió"
        y T va a ser int, float, std::string, o lo que sea que se usó para instanciar la plantilla.*/
        
        //member functions
        unsigned int size() const;
        
        //exceptions
        class OutOfBoundsException : public std::exception 
		{
			public:
				const char* what() const throw();
		};
};

#include "../sources/Array.tpp"
