/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:57:27 by dtorrett          #+#    #+#             */
/*   Updated: 2025/12/02 15:29:15 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main (int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << RED << "Error: usage: \"2 + 3 * 4\"" << RESET << std::endl;
		return 1;
	}    
	try
	{
		RPN rpn;
		rpn.processOperation(std::string(av[1]));
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}    
	return 0;
}