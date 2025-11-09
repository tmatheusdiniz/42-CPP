/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:55:42 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/18 20:04:59 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <iterator>

Zombie::Zombie()
{
	std::cout << "Zombie was created without a _name" << std::endl;
}

Zombie::Zombie( std::string _name )
{
	this->_name = _name;
	std::cout << "Zombie " << this->_name << " was created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string _name)
{
	this->_name = _name;
	std::cout << "Zombie _name " << _name << std::endl;
}
