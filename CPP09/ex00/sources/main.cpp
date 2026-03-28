/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:57:27 by dtorrett          #+#    #+#             */
/*   Updated: 2025/12/03 15:32:12 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main (int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange btc;
		btc.processDatabase();
		btc.processBitcoin(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}    
	return 0;
}