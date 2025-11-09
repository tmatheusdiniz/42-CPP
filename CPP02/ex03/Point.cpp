/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:12:21 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/27 17:02:15 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{

}

Point::Point(float const x, float const y) : _x(x), _y(y)
{

}

Point::Point(Point const& copy) : _x(copy._x), _y(copy._y)
{

}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{

}

Fixed Point::getPointX() const
{
	return (this->_x);
}

Fixed Point::getPointY() const
{
	return (this->_y);
}
