/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:53:16 by mreinald          #+#    #+#             */
/*   Updated: 2025/11/03 14:57:00 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : AAnimal(src)
{
	this->brain = new Brain(*src.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		AAnimal::operator=(src);
		delete (this->brain);
		this->brain = new Brain(*src.brain);
	}
	return (*this);
}

Cat::~Cat() 
{
	delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!" << std::endl;
}
