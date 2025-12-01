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
		this->templates[i]= NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src.templates[i])
			this->templates[i]= src.templates[i]->clone();
		else
			this->templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->templates[i])
			{
				delete (this->templates[i]);
				this->templates[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (src.templates[i])
				this->templates[i] = src.templates[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i])
		{
			delete (this->templates[i]);
			this->templates[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->templates[i])
		{
			this->templates[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) 
{
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i] && this->templates[i]->getType() == type)
		{
			return this->templates[i]->clone();
		}
	}
	return (NULL);
}
