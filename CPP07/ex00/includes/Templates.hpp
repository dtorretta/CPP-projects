#pragma once

#include <iostream>
#include <string>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

template <typename T> //template <class T>
void swap(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T& min(T& a, T& b) //necesito que sea & para que el retorno no cree un objeto sino que sea un pointer a A o B.
{
    return (a < b) ? a : b; 
}

template <typename T>
T& max(T& a, T& b) 
{
    return (a > b) ? a : b;
}