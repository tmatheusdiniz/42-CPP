/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:33:28 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/01 15:38:55 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{

}

AMateria::AMateria(const AMateria& src) : type(src.type)
{

}

AMateria& AMateria::operator=(const AMateria& src)
{
	if (this != &src)
	{
		this->type= src.type;
	}
	return (*this);
}

AMateria::~AMateria()
{

}

std::string const & AMateria::getType() const
{
	return (this->type);
}
