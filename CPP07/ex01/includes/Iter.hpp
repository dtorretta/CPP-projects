#pragma once

#include <iostream>
#include <string>
#include <cstdlib> //???????????
#include <cctype> //???????????


#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"


template <typename T, typename F> // si necesit una funcion tengo que agegar un segundo template
void iter(T* array, size_t size, F func)  //seguimos usando * para direccion de memoria
{
    for(size_t i = 0; i < size; ++i)
        func(array[i]);
}