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

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//returns a references, not a copy
template <typename T>
T& min(T &a, T &b)
{
    return (a < b) ? a : b; 
}

//returns a references, not a copy
template <typename T>
T& max(T& a, T& b)
{
    return (a > b) ? a : b;
}
