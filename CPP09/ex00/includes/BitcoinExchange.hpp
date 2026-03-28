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

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database;
		
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
