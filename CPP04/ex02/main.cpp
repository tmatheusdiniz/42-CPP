/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:19:14 by mreinald          #+#    #+#             */
/*   Updated: 2025/11/04 14:26:52 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal *cat = new Cat();
	cat->makeSound();
	Cat cat2;
	cat2.makeSound();
	std::cout << cat2.getType() << std::endl;
	Dog dog;
	std::cout << dog.getType() << std::endl;
	WrongCat wrongCat;
	std::cout << wrongCat.getType() << std::endl;
	wrongCat.makeSound();
	Brain brain;
	for (int i = 0; i < 10; i++)
	{
		brain.setIdea(i, "cat thinking about whiskas");
	}
	for (int i = 10; i < 20; i++)
	{
		brain.setIdea(i, "Dog thinking about the meat on the table");
	}
	for (int k = 0; k < 10; k++)
	{
		std::cout << brain.getIdea(k) << std::endl;
	}
	for (int k = 10; k < 20; k++)
	{
		std::cout << brain.getIdea(k) << std::endl;
	}
	delete (cat);
}
