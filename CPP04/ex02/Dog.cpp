/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:40:54 by mreinald          #+#    #+#             */
/*   Updated: 2025/11/04 09:41:17 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	this->brain = new Brain(*src.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
	{
		AAnimal::operator=(src);
		delete (this->brain);
		this->brain = new Brain(*src.brain);
	}
	return (*this);
}

Dog::~Dog() 
{
	delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Burk! Burk!" << std::endl;
}
