/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:36:31 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/28 14:33:00 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _health(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
{
	this->_name = name;
	this->_health = 10;
	this->_energy = 10;
	this->_attackDamage = 10;
	std::cout << "ClapTrap " << _name << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_health > 0 && this->_energy > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
		-- _energy;
	}
	else if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " is out of energy and can't attack!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name
			<< " is broken and cannot attack!" << std::endl; 
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health > 0)
	{
		if ((this->_health - amount) < 0)
			_health = 0;
		else
			_health = _health - amount;
		std::cout << "ClapTrap " << _name
			<< " takes " << amount << " points of damage! " 
			<< "Remaining hit points: " << _health << std::endl;
	}
	else if (_health == 0)
		std::cout << "ClapTrap " << _name
			<< " is already broken and can't take more damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_health > 0 && _energy > 0)
	{
		if ((this->_health + amount) > 10)
			_health = 10;
		else
			_health = _health + amount;
		-- _energy;
		std::cout << "ClapTrap " << _name
			<< " repairs itself for " << amount 
			<< " hit points! Current hit points: " << _energy << std::endl;
	}
	else if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " is out of energy and can't attack!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name
			<< " is broken and cannot attack!" << std::endl; 
	}
}
