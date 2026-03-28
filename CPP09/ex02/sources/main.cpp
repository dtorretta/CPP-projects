/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:57:27 by dtorrett          #+#    #+#             */
/*   Updated: 2025/12/02 15:45:36 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

void PmergeMe::printTime(std::string str, int start_time, int end_time) const
{
	double duration = double(end_time - start_time) / (CLOCKS_PER_SEC / 1000000.000); //microseconds
	
	int size = _vec.size();
	if(str == "vec")
		std::cout << YELLOW << "Time to process a range of: " << size << " elements with std::vector : " << duration << " us." << RESET << std::endl;
	else
		std::cout << YELLOW << "Time to process a range of: " << size << " elements with std::deque : " << duration << " us." << RESET << std::endl;
}
int main (int ac, char** av)
{
	if (ac == 1)
	{
		std::cout << RED << "Error: not enough arguments" << RESET << std::endl;
		return 1;
	}  
	
	try
	{ 
		PmergeMe merge;
		for(int i = 1; i < ac; i++)
		{
			merge.validate(av[i]);
			merge.addNumber(atoi(av[i]));
		}
				
		//VECTOR
		clock_t start_time = clock();
		std::vector<int> vector = merge.sortVec(merge.getVec());
		clock_t end_time = clock();
		
		if (!isSorted(vector))
			throw std::runtime_error("Error: Vector not sorted");
		// else
		//     std::cout << GREEN << "SORTED!" << RESET << std::endl;
		
		merge.print(vector);
		merge.printTime("vec", start_time, end_time);
		
		//DEQUE
		start_time = clock();
		std::deque<int> deque = merge.sortDeq(merge.getDeq());
		end_time = clock();
				  
		//merge.print(deque);
		merge.printTime("deq", start_time, end_time);
		// if (!isSorted(deque))
		//     throw std::runtime_error("Error: Deque not sorted");
		// else
		//     std::cout << GREEN << "SORTED!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}    
	return 0;
}
