/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:52:18 by dtorrett          #+#    #+#             */
/*   Updated: 2025/06/26 02:31:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void printable(double value, char c)
{
	//char
	if(value < 0 || value > 255)
		std::cout << YELLOW << "char: " << RESET << "Impossible" << std::endl;
	else if (!isprint(c))
		std::cout << YELLOW << "char: " << RESET << "Non displayable" << std::endl;
	else 
		std::cout << YELLOW << "char: " << RESET << "'" << c << "'" << std::endl;
		
	//int
	if (value <= INT_MAX && value >= INT_MIN)	
		std::cout << YELLOW << "Int: " << RESET << static_cast<int>(value) << std::endl;
	else
		std::cout << YELLOW << "Int: " << RESET << "Impossible" << std::endl;
		
	//float	
	if (value <= FLT_MAX && value >= -FLT_MAX)	
		std::cout << YELLOW << "Float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << YELLOW << "Float: " << RESET << "Impossible" << std::endl;
		
	//double	
	std::cout << YELLOW << "Double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(value)  << std::endl;
}

void Impossible()
{
	std::cout << YELLOW << "char: " << RESET << "Impossible" << std::endl;
	std::cout << YELLOW << "Int: " << RESET << "Impossible" << std::endl;
	std::cout << YELLOW << "Float: " << RESET << "Impossible" << std::endl;
	std::cout << YELLOW << "Double: " << RESET << "Impossible" << std::endl;	
}

void handlePseudoLiterals(const std::string &str)
{
	std::cout << YELLOW << "char: " << RESET << "impossible" << std::endl;
	std::cout << YELLOW << "Int: " << RESET << "impossible" << std::endl;
	
	if (str.length() == 5)
	{
		std::cout << YELLOW << "Float: " << RESET << str << std::endl;
		std::string newstr = str.substr(0, str.length() - 1);
		std::cout << YELLOW << "Double: " << RESET << newstr << std::endl;
	}
	else
	{
		std::cout << YELLOW << "Float: " << RESET << str << "f" << std::endl;
		std::cout << YELLOW << "Double: " << RESET << str << std::endl;
	}
}

void handleChar(const std::string &str)
{
	char c = str[0];
	std::cout << YELLOW << "char: " << RESET << "'" << c << "'" << std::endl;
	std::cout << YELLOW << "Int: " << RESET << static_cast<int>(c) << std::endl;
	std::cout << YELLOW << "Float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << YELLOW << "Double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void handleInt(const std::string &str)
{
	std::istringstream iss(str);
	long long value;
	char c;
	
	iss >> value;
	
	c = static_cast<char>(value);
		
	printable (value, c);
	// //char
	// if(value < 0 || value > 255)
	// 	std::cout << YELLOW << "char: " << RESET << "Impossible" << std::endl;
	// else if (!isprint(c))
	// 	std::cout << YELLOW << "char: " << RESET << "Non displayable" << std::endl;
	// else 
	// 	std::cout << YELLOW << "char: " << RESET << "'" << c << "'" << std::endl;
	// //int	
	// if (value <= INT_MAX && value >= INT_MIN)	
	// 	std::cout << YELLOW << "Int: " << RESET << value << std::endl;
	// else
	// 	std::cout << YELLOW << "Int: " << RESET << "Impossible" << std::endl;
	// //float	
	// if (value <= FLT_MAX && value >= -FLT_MAX)	
	// 	std::cout << YELLOW << "Float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	// else
	// 	std::cout << YELLOW << "Float: " << RESET << "Impossible" << std::endl;
	// //double		
	// std::cout << YELLOW << "Double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void handleFloat(const std::string &str)
{
	std::istringstream iss(str);
	double value;
	char c;
	
	iss >> value;
	
	c = static_cast<char>(value);
	
	printable (value, c);
	// //char
	// if(value < 0 || value > 255)
	// 	std::cout << YELLOW << "char: " << RESET << "Impossible" << std::endl;
	// else if (!isprint(c))
	// 	std::cout << YELLOW << "char: " << RESET << "Non displayable" << std::endl;
	// else 
	// 	std::cout << YELLOW << "char: " << RESET << "'" << c << "'" << std::endl;
	// //int	
	// if (value <= INT_MAX && value >= INT_MIN)	
	// 	std::cout << YELLOW << "Int: " << RESET << static_cast<int>(value) << std::endl;
	// else
	// 	std::cout << YELLOW << "Int: " << RESET << "Impossible" << std::endl;
	// //float
	// if (value <= FLT_MAX && value >= -FLT_MAX)	
	// 	std::cout << YELLOW << "Float: " << RESET << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	// else
	// 	std::cout << YELLOW << "Float: " << RESET << "Impossible" << std::endl;
	// //double	
	// std::cout << YELLOW << "Double: " << RESET << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void handleDouble(const std::string &str)
{
	std::istringstream iss(str);
	double value;
	char c;
	
	iss >> value;
	
	c = static_cast<char>(value);
	
	printable (value, c);
	// //char
	// if(value < 0 || value > 255)
	// 	std::cout << YELLOW << "char: " << RESET << "Impossible" << std::endl;
	// else if (!isprint(c))
	// 	std::cout << YELLOW << "char: " << RESET << "Non displayable" << std::endl;
	// else 
	// 	std::cout << YELLOW << "char: " << RESET << "'" << c << "'" << std::endl;
	// //int
	// if (value <= INT_MAX && value >= INT_MIN)	
	// 	std::cout << YELLOW << "Int: " << RESET << static_cast<int>(value) << std::endl;
	// else
	// 	std::cout << YELLOW << "Int: " << RESET << "Impossible" << std::endl;
	// //float	
	// if (value <= FLT_MAX && value >= -FLT_MAX)	
	// 	std::cout << YELLOW << "Float: " << RESET << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	// else
	// 	std::cout << YELLOW << "Float: " << RESET << "Impossible" << std::endl;
	// //double	
	// std::cout << YELLOW << "Double: " << RESET << std::fixed << std::setprecision(1) << value << std::endl;
}

bool isChar(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]) && isprint(str[0])) //1 solo char / no es digito / es printble
		return true;
	return false;
}

bool isInt(const std::string &str)
{
	std::istringstream iss(str); //funciona como si fuera un archivo, pero en lugar de leer de un archivo, lee desde un string
	long long int value;
	char c;
	
	return (iss >> value) && !(iss >> c);
}

bool isFloat(const std::string &str)
{
	// Pseudo-literals
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		handlePseudoLiterals(str);
		return false;
	}
	
	std::istringstream iss(str);
	double value;
	char c;
	
	return (iss >> value) && (iss >> c) && (c == 'f') && !(iss >> c); 
}

bool isDouble(const std::string &str)
{
	// Pseudo-literals
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		handlePseudoLiterals(str);
		return false;
	}
	
	std::istringstream iss(str);
	double value;
	char c;

	return (iss >> value) && !(iss >> c);
}

void ScalarConverter::convert (std::string str)
{
	if (str == "")
		throw "Error: string cannot be empty";
	else if (isChar(str))
		handleChar(str);
	else if (isInt(str))
		handleInt(str);
	else if (isFloat(str))
		handleFloat(str);
	else if (isDouble(str))
		handleDouble(str);
	else
	{
		if(atoi(str.c_str()) <= DBL_MAX && atoi(str.c_str()) >= -DBL_MAX)	
			Impossible();
		else if (str != "-inff" && str != "+inff" && str != "nanf" && str != "-inf" && str != "+inf" && str != "nan")
			throw "Error: Type not recognized";
	}
}

/*The number is so large that a double can't represent it exactly. 
But C++ still tries to convert it to the closest possible value. That's why it prints a similar number, 
even though it's not exactly the same. This isn't a bug — it's just how double works in C++. */