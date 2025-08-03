#pragma once

#include <stack>
#include <list>
#include <iostream>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

/*
"Write a MutantStack class. It will be implemented in terms of a std::stack."
heredamos de una clase starndart por lo que no necesitamos escribir de 0 todo como el constructor, etc 
Cuando una clase ya te ofrece toda la funcionalidad que querés (en este caso, std::stack), y solo necesitás agregar algo más, 
como iteradores, la solución natural y eficiente es heredarla.
*/

template <typename T>
class MutantStack : public std::stack<T> 
{     
    public:
        //alias
        typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_it;
		typedef typename std::stack<T>::container_type::reverse_iterator rev_it;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_rev_it;
		
		//Member fuctions
		iterator begin() {return std::stack<T>::c.begin();} 
		iterator end() {return std::stack<T>::c.end();}

		const_it begin() const {return std::stack<T>::c.begin();}
		const_it end() const {return std::stack<T>::c.end();}

		rev_it rbegin() {return std::stack<T>::c.rbegin();}
		rev_it rend() {return std::stack<T>::c.rend();}

		const_rev_it rbegin() const {return std::stack<T>::c.rbegin();}
		const_rev_it rend() const {return std::stack<T>::c.rend();}
};
