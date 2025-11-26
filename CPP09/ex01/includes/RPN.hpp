#pragma once

#include <iostream>
#include <stack>
#include <fstream>
#include <string>

# include <sstream>
# include <algorithm>
# include <cctype>

#define GREEN	"\033[32m"
#define RED  	"\033[31m"
#define BLUE	"\033[36m"
#define YELLOW	"\033[0;33m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;2;255;165;0m"
#define FORM    "\033[4m"
#define RESET	"\033[0m"

class RPN
{
	private:
		std::stack<int> _stack;
		int _operands;
		int _x;
		int _z;
		int _result;
		
	public:
		RPN(); //Default Constructor
		RPN(const RPN& other); //Copy constructor
		RPN& operator=(const RPN& other); //Copy assignment operator
		~RPN(); //Destructor
		
		//Methods
		void processOperation(const std::string &rpn);
		void mathOperation(int x, int z, char op);
		
		//getter
		int getResult();
};

/*
INICIALIZACION AUTPOMATICA DE ATRIBUTOS PRIVADOS

-Con un constructor por defecto vacío (RPN()) tus atributos como _operation se inicializan correctamente 
y vacíos si son tipos STL que tienen constructor por defecto.

-Tipos primitivos (int, float, double, char, punteros crudos, bool, etc.): 
Estos NO se inicializan automáticamente si usás un constructor por defecto vacío.
*/