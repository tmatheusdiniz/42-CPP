/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:   :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:34:47 by mreinald          #+#    #+#             */
/*   Updated: 2025/11/03 09:41:15 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <string>

AAnimal::AAnimal() : _type("")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	this->_type = src._type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

AAnimal::~AAnimal() 
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const 
{
    return (this->_type);
}
