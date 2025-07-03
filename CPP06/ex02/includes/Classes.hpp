#pragma once 

#include <iostream>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


