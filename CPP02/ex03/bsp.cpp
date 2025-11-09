/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:02:33 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/27 19:03:35 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed calculateArea(Point const& a, Point const& b, Point const& c)
{
	Fixed area = (a.getPointX() * (b.getPointY() - c.getPointY())
				+ b.getPointX() * (c.getPointY() - a.getPointY()) 
				+ c.getPointX() * (a.getPointY() - b.getPointY()));
	if (area < 0)
		area = area * Fixed(-1);
	return (area / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaTriangle = calculateArea(a, b, c);
	if (areaTriangle == 0)
		return (false);
	Fixed areaPAB = calculateArea(point, a, b);
	Fixed areaPAC = calculateArea(point, a, c);
	Fixed areaPBC = calculateArea(point, b, c);
	if (areaPAB == 0 || areaPAC == 0 || areaPBC == 0)
		return (false);
	Fixed sumArea = areaPAB + areaPAC + areaPBC;
	Fixed diff = areaTriangle - sumArea;
	if (diff < 0)
		diff = diff * Fixed(-1);
	return (diff < Fixed::epsilonFloat());
}
