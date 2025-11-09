/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:58:59 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/29 14:43:03 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_health = 100;
	_energy = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_health = 100;
	_energy = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_health > 0 && this->_energy > 0)
	{
		std::cout << "ScavTrap " << _name
			<< " strongly attacks " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
		-- _energy;
	}
	else if (this->_energy == 0)
	{
		std::cout << "ScavTrap " << _name
			<< " is out of energy and can't attack!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << _name
			<< " is broken and cannot attack!" << std::endl; 
	}
}

void ScavTrap::guardGate()
{
	if (_guardingGate)
		std::cout << "ScavTrap " << _name
			<< " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::setGuardGate(bool sign)
{
	_guardingGate = sign;
}
