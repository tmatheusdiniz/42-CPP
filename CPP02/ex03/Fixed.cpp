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
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->_rawBits = other._rawBits;
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	this->_rawBits = intValue << this->_fracBits;
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
{
	this->_rawBits = roundf(floatValue * (1 << this->_fracBits));
	//std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& other)
{
	if (this != &other)
	{
		_rawBits = other._rawBits;
	}
	//std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
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

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_rawBits > other._rawBits);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_rawBits < other._rawBits);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed result;
	long long int temp = (long long int)this->_rawBits * (long long int)rhs.getRawBits();
	result.setRawBits((int)temp >> _fracBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	if (rhs.getRawBits() == 0)
	{
		std::cerr << "Error: it's not possible divide by 0" << std::endl;
		return Fixed();
    }
	Fixed result;
	long long int temp = ((long long int)this->_rawBits << _fracBits) / rhs.getRawBits();
	result.setRawBits((int)temp);
	return (result);    
}

Fixed &Fixed::operator++()
{
	this->_rawBits++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator--()
{
	this->_rawBits--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

float Fixed::epsilonFloat()
{
	return (1.0 / static_cast<float>(1u << _fracBits));
}
