/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:45:27 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/30 14:47:54 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_health = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_health = 100;
	_energy = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called" << std::endl;
	return (*this);
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_highFives)
	{
		std::cout << "FragTrap " << _name 
			<< " is in High Five mode! Takes 50% less damage!" << std::endl;
		amount = amount / 2;
	}
	if (amount >= _health)
		_health = 0;
	else
		_health -= amount;
	std::cout << "FragTrap " << _name << " takes " << amount 
		<< " damage! HP: " << _health << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (this->_health > 0 && this->_energy > 0)
	{
		std::cout << "FragTrap " << _name
			<< " strongly attacks " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
		-- _energy;
	}
	else if (this->_energy == 0)
	{
		std::cout << "FragTrap " << _name
			<< " is out of energy and can't attack!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << _name
			<< " is broken and cannot attack!" << std::endl; 
	}
}

void FragTrap::highFivesGuys()
{
	if (_highFives)
		std::cout << "FragTrap " << _name
			<< " is now in High Fives mode!" << std::endl;
}

void FragTrap::setHighFivesGuys(bool sign)
{
	_highFives = sign;
}
