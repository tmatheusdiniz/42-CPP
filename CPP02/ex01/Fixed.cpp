/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:30:18 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/26 01:12:52 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->_rawBits = other._rawBits;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	this->_rawBits = intValue << this->_fracBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
{
	this->_rawBits = roundf(floatValue * (1 << this->_fracBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& other)
{
	if (this != &other)
	{
		_rawBits = other._rawBits;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float Fixed::toFloat( void ) const
{
	float ret;
	ret = (static_cast<float>(this->_rawBits)) / (1 << this->_fracBits);
	return (ret);
}

int Fixed::toInt( void ) const
{
	return (this->_rawBits >> this->_fracBits);
}

// ---------------------------------------------

int Fixed::getIntegerPart() const
{
	return (this->_rawBits & INT_MASK) >> this->_fracBits;
}

int Fixed::getFractionalRaw() const
{
	return (this->_rawBits & FRAC_MASK);
}

float Fixed::getFractionalFloat() const
{
	int fracRaw = this->_rawBits & FRAC_MASK;
	return (static_cast<float>(fracRaw) / (1 << this->_fracBits));
}

void Fixed::printParts() const
{
	std::cout << "Raw: " << this->_rawBits << std::endl;
	std::cout << "Integer part: " << getIntegerPart() << std::endl;
	std::cout << "Frac raw: " << getFractionalRaw() << std::endl;
	std::cout << "Frac float: " << getFractionalFloat() << std::endl;
	std::cout << "Total: " << toFloat() << std::endl;
	std::cout << "---" << std::endl;
}

// ---------------------------------------------
