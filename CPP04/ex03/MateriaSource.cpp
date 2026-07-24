/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:30:05 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/01 20:34:27 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_templates[i]= NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._templates[i])
			this->_templates[i]= src._templates[i]->clone();
		else
			this->_templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_templates[i])
			{
				delete (this->_templates[i]);
				this->_templates[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (src._templates[i])
				this->_templates[i] = src._templates[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i])
		{
			delete (this->_templates[i]);
			this->_templates[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_templates[i])
		{
			this->_templates[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) 
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] && this->_templates[i]->getType() == type)
		{
			return this->_templates[i]->clone();
		}
	}
	return (NULL);
}
