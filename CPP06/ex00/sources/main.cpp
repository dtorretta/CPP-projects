/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:58:02 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:58:02 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"


int main(int argc, char **argv)
{
	try
	{    
		if (argc != 2)
			throw "Error, only one parameter accepted";   
		ScalarConverter::convert(argv[1]);
	}
	catch (const char* msg)
	{
		std::cout << RED << msg << RESET << std::endl;
	}    
	return 0;
}

// // INPUT TO TEST:
// - 0
// - nan
// - NaN
// - inf
// - inff
// - -inf
// - -inff
// - +inf
// - +inff
// - 42.0f

// - 2147483647
// - 2147483648
// - -2147483648
// - -2147483649
// - 1.0e40 (bigger than max float)
// - max float: 3.40282e+38
// - max double: 1.79769e+308