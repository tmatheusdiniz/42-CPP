/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:10:31 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/01 21:00:13 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(Character& src) : _name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character& Character::operator = (const Character& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]); // the actual object behind the pointer not is an AMateria object but Cure or Ice. it's making delete (Cure*) or delete (Ice*)
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << "Equiped" << std::endl;
			return ;
		}
	}
	std::cout << "Full Inventory" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx <= 0 || idx > 4)
	{
		std::cout << "the index may be between 1 and 4" << std::endl;
		return ;
	}
	if (this->_inventory[idx - 1])
		this->_inventory[idx - 1] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 0 && idx <= 4 && this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
	}
}
