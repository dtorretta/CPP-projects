/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:27:16 by dtorrett          #+#    #+#             */
/*   Updated: 2025/12/02 15:27:16 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/BitcoinExchange.hpp"

// Constructor
BitcoinExchange::BitcoinExchange(){}

// The copy constructor creates a new object as a copy of an existing object.
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
{
	_database = other._database;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if(this != &other)
	   _database = other._database;
	return *this;
}

//Destructor
BitcoinExchange::~BitcoinExchange() {}; 

std::string trim(const std::string &s)
{
	size_t start = s.find_first_not_of(" \t\r");
	size_t end = s.find_last_not_of(" \t\r");
	if (start == std::string::npos)
		return "";
	return s.substr(start, end - start + 1);
}

bool isNotNumber(const std::string &s)
{
	if (s.empty())
		return true;

	std::istringstream iss(s);
	double val;
	char c;
	if (!(iss >> val)) 
		return true; // no number
	if (iss >> c) 
		return true; //not numerical char after number
	return false;
}

void BitcoinExchange::validation(std::string &datePart, float valuePart) const
{
	//date validation
	std::istringstream iss(datePart); 
	int year, month, day;
	char dash1, dash2;
	
	if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') 
		throw std::runtime_error("Error: bad input => " + datePart);
		
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		daysInMonth[1]  = 29; //biciesto
		
	if (day < 1 || day > daysInMonth[month - 1] || month < 1 || month > 12)
		throw std::runtime_error("Error: bad input => " + datePart);
		  
	//float validation
	if(valuePart <= 0)
		throw std::runtime_error("Error: not a positive number.");
	if(valuePart > 1000)
		throw std::runtime_error("Error: too large a number.");
}

std::map<std::string, float>::const_iterator BitcoinExchange::findClosestDate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date); //searchs the first element which date is >=.
	
	if (it != _database.end() && it->first == date) //exact match
		return it;
	
	if (it == _database.end()) //all dates are previous
	{
		--it; // one back
		return it;
	}
	
	if (it->first > date)
	{
		if(it == _database.begin())//there is no previous date → no valid date
			throw std::runtime_error("Error: no previous date available.");
		--it;
	}
	
	return it;
}

void BitcoinExchange::printOutput(std::string &date, float value) const
{
	std::map<std::string, float>::const_iterator it = findClosestDate(date);
	float result = it->second * value;
	
	std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::processDatabase()
{
	std::ifstream _file("data.csv");
	if (!_file.is_open()) 
		throw std::runtime_error("Error: could not open data.csv file.");
	
	std::string line; //buffer for each line in data.csv
	std::getline(_file, line); // discart the first lines as it is the title.
	while (std::getline(_file, line)) 
	{
		std::istringstream iss(line);
		std::string date;
		std::string value;
		
		std::getline(iss, date, ','); //date any value before ',' ex: 2011-01-03
		std::getline(iss, value); //XR any value after ',' ex: 0.36
		if (value.empty()) //if there is no ','
			throw std::runtime_error("Error: incorrect format: " + line);
			
		float floatValue = atof(value.c_str());

		_database[date] = floatValue;
	}
}

void BitcoinExchange::processBitcoin(char *file)
{
	std::ifstream dataFile(file);
	if (!dataFile.is_open())
		throw std::runtime_error("Error: could not open database file.");
	  
	std::string line; //buffer
	std::getline(dataFile, line); // discart the first lines as it is the title.
	
	while (std::getline(dataFile, line))
	{
		try
		{
			std::istringstream iss(line);
			std::string datePart;
			std::string valuePart;
			std::getline(iss, datePart, '|'); //datePart any value before '|' ex: 2011-01-03
			std::getline(iss, valuePart); //valuePart any value after '|' ex: 3

			datePart = trim(datePart);
			valuePart = trim(valuePart);
			
			if (valuePart.empty() || isNotNumber(valuePart)) //if there is no '|' or value is not a number
				throw std::runtime_error("Error: bad input => " + line);
			
			float floatValue = atof(valuePart.c_str());
			
			validation(datePart, floatValue);
			printOutput(datePart, floatValue);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		} 
	}    
}


