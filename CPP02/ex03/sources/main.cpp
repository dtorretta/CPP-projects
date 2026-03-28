/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:56:46 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:56:46 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
	Point A(0, 0);
	Point B(5, 0);
	Point C(0, 5);
	Point inside(1, 1); //(2, 2) (3, 1)
	Point outside(6, 6);
	
	if (bsp(A, B, C, inside)) 
		std::cout << GREEN << "The point 1 is inside the triangle." << RESET << std::endl;
	else
		std::cout << RED << "The point 1 is outside the triangle." << RESET << std::endl;
		
	if (bsp(A, B, C, outside)) 
		std::cout << GREEN << "The point 2 is inside the triangle." << RESET << std::endl;
	else
		std::cout << RED << "The point 2 is outside the triangle." << RESET << std::endl;
		
	return 0;
}
