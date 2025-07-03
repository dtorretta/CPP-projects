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

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main(void)
{
	Data original;
	original.name = "Kelsier";
	original.age = 38;
	original.mistborn = true;
	
	std::cout << FORM << "\n✅ #1 Print the data of the original structure.\n" << RESET << std::endl;
	std::cout   << std::boolalpha 
				<< YELLOW << "name: " << RESET << original.name
				<< YELLOW << "\nage: " << RESET << original.age
				<< YELLOW <<"\nmistborn?: " << RESET << original.mistborn << std::endl;
				
	uintptr_t raw = Serializer::serialize(&original);
	Data *recovered = Serializer::deserialize(raw);
	
	std::cout << FORM << "\n✅ #2 Print the data of the recovered structure.\n" << RESET << std::endl;
	std::cout   << std::boolalpha 
				<< YELLOW << "name: " << RESET << recovered->name
				<< YELLOW << "\nage: " << RESET << recovered->age
				<< YELLOW <<"\nmistborn?: " << RESET << recovered->mistborn << std::endl;
	
	std::cout << FORM << "\n✅ #3 Compare them.\n" << RESET << std::endl;
	if (recovered == &original)
		std::cout << GREEN << "Pointer successfully restored!" << RESET << std::endl;
	return 0;
}
