/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:37:57 by marvin            #+#    #+#             */
/*   Updated: 2025/11/11 19:37:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

// Constructor
RPN::RPN(){}

// The copy constructor creates a new object as a copy of an existing object.
RPN::RPN(const RPN& other) 
{
	_stack = other._stack;
	_operands = other._operands;
	_x = other._x;
	_z= other._z;
	_result = other._result;
}

// The copy assignment operator copies the contents from one existing object to another existing object.
RPN& RPN::operator=(const RPN& other)
{
	if(this != &other)
	{
		_stack = other._stack;
		_operands = other._operands;
		_x = other._x;
		_z= other._z;
		_result = other._result;
	}
	return *this;
}

//Destructor
RPN::~RPN() {}; 

//Utils
std::string removeSpaces(const std::string& str)
{
	std::string result;
	result.reserve(str.size());

	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (str[i] != ' ')
			result += str[i];
	}

	return result;
}

bool isOperator(char c) 
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

//Methods
void RPN::mathOperation(int x, int z, char op)
{
	if(op == '+')
		_result = z + x;
	else if(op == '-')
		_result = z - x;
	else if(op == '*')
		_result = z * x;
	else if(op == '/')
		_result = z / x;
	else
		throw std::runtime_error("Error: Invalid operator");
}

void RPN::processOperation(const std::string &rpn)
{
	std::istringstream iss(rpn);
	std::string token;
	_operands = 0;
	while(iss >> token)
	{
		if(token.size() > 1) //ex: 11
			throw std::runtime_error("Error: in Token");
		
		else if (!isdigit(token[0]) && !isOperator(token[0])) //ex: A or !
			throw std::runtime_error("Error: not a digit nor operator");
		else
		{
			if(isdigit(token[0]))
			{
				_operands++;
				_stack.push(atoi(token.c_str()));
			}
			else
			{
				if(_operands < 2)
					throw std::runtime_error("Error: not enough operands");
				_x = _stack.top();
				_stack.pop();
				_operands--;
				_z = _stack.top();
				_stack.pop();
				_operands--;
				
				mathOperation(_x, _z, token[0]);
				_stack.push(_result);
				_operands++;
			}
		}
	}
	
	//at the end of the while loop, last element of the stack should be the result. There should not be more elements. if so, there were not enough operators
	if(_stack.size() > 1)
		throw std::runtime_error("Error: remaining elements in stack");
		
	//The last element of the stack should match with the last math operation
	int compare = _stack.top();
	_stack.pop();
	
	if(_result != compare)
		throw std::runtime_error("Error in the result!");
}

//Getter
int RPN::getResult() {return _result;}
