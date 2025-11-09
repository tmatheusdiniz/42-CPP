/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 02:29:10 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/27 02:38:54 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const& copy);
		Point& operator=(const Point& other);
		~Point();
		Fixed getPointX() const;
		Fixed getPointY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
