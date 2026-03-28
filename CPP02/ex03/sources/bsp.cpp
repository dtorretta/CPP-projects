/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:55:45 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:55:45 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
	Fixed area = Fixed(0.5f) * (a.getx() * (b.gety() - c.gety()) 
				+ b.getx() * (c.gety() - a.gety()) 
				+ c.getx() * (a.gety() - b.gety()));

	if (area < 0)
		area = area * Fixed(-1);

	return(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = area(a, b, c);
	Fixed pab = area(point, a, b);
	Fixed pbc = area(point, b, c);
	Fixed pca = area(point, c, a);
	return((pab + pbc + pca) == abc);
}
