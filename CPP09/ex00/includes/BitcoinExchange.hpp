#pragma once

#include <iostream>
#include <map>
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

/*El programa debe decir cuánto valía esa cantidad de bitcoins en dólares (u otra moneda) según una 
base de datos de precios históricos de Bitcoin (que te dan en formato .csv).*/

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database; //1er paso para trabajar con maps
		
	public:
		BitcoinExchange(); //Default Constructor
		BitcoinExchange(const BitcoinExchange& other); //Copy constructor
		BitcoinExchange& operator=(const BitcoinExchange& other); //Copy assignment operator
		~BitcoinExchange(); //Destructor
		
		//Methods
		void processDatabase();
		void processBitcoin(char *file);
		void validation(std::string &datePart, float valuePart) const;
		void printOutput(std::string &date, float value) const;
		std::map<std::string, float>::const_iterator findClosestDate(const std::string &date) const;
};

/*
INICIALIZACION AUTPOMATICA DE ATRIBUTOS PRIVADOS

-Con un constructor por defecto vacío (BitcoinExchange()) tus atributos como _database se inicializan correctamente 
y vacíos si son tipos STL que tienen constructor por defecto.

-Tipos primitivos (int, float, double, char, punteros crudos, bool, etc.): 
Estos NO se inicializan automáticamente si usás un constructor por defecto vacío.
*/