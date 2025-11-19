/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:36:17 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/21 08:42:34 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
	this->_type = _type;
}

const std::string &Weapon::getType()
{
	return (this->_type);
}

void Weapon::setType(std::string _type)
{
	this->_type = _type;
}
