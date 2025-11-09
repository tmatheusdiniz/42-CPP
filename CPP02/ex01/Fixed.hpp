/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:15:59 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/26 01:13:01 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _rawBits;
		static const int _fracBits = 8;
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float floatValue);
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
//---------------------------------------------------------
		int getIntegerPart() const;
		int getFractionalRaw() const;
		float getFractionalFloat() const;
		void printParts() const;
		static const int FRAC_MASK = (1 << _fracBits) - 1;
		static const int INT_MASK = ~FRAC_MASK;
//---------------------------------------------------------
};

std::ostream& operator << (std::ostream& os, const Fixed& f);

#endif
