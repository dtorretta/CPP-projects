#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"


template <typename T, typename F> // si necesita una funcion tengo que agegar un segundo template
void iter(T *array, const size_t length, F func)  //seguimos usando * para direccion de memoria
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void printElement(const T& x) 
{
    std::cout << YELLOW << x << RESET;
}

template <typename T>  //no le puedo sacar esto porque lo necesita como parametro
void increase(T &val)
{
    val++;
}

void upper(std::string &str)
{
    for(size_t i = 0; i < str.size(); ++i)
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
}



