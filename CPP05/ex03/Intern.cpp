/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:17:59 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/20 21:33:24 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	std::cout << "Intern assignment operator called" << std:: endl;
	return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	int index;
	std::string forms[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presendial pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
	  		index = i;		
	}
	switch(index)
	{
		case 0: return (new ShrubberyCreationForm(target));
		case 1: return (new RobotomyRequestForm(target));
		case 2: return (new PresidentialPardonForm(target));
		default: throw(Intern::FormNotExist());
	}
}

const char* Intern::FormNotExist::what() const throw()
{
	return ("Form doesn't exist!");
}
