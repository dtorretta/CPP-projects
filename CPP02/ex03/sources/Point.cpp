/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:57:00 by dtorrett          #+#    #+#             */
/*   Updated: 2025/03/10 08:57:00 by dtorrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

// Default constructor
Point::Point(void) : _x(0) , _y(0) {}

Point::Point(const float x, const float y) : _x(x) , _y(y) {}

// The copy constructor creates a new object as a copy of an existing object.
Point::Point(const Point& src) : _x(src._x) , _y(src._y) {}

// The copy assignment operator makes nothing as _x and _y are const, we cannot assign them new values
Point& Point::operator=(const Point& src)
{
	(void)src;
	return(*this);
}

Point::~Point(void) {}

Fixed Point::getx(void) const
{
	return(_x);
}

Fixed Point::gety(void) const
{
	return(_y);
}

