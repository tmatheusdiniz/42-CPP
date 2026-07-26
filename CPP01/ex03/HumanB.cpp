/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:23:19 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/20 23:30:59 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::setWeapon(Weapon* w)
{
	if (w)
		this->_weapon = w;
}

HumanB::HumanB(const std::string& _name)
{
	this->_name = _name;
}

void HumanB::attack()
{
	if (this->_weapon)
	{
		std::cout << _name << " attacks with their " 
			<< _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << _name << " has no _weapon to attack with!" 
			<< std::endl;
	}
}
