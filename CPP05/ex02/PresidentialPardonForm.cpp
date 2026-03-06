/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:15:12 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/20 00:44:38 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", false, 25, 5), _target("default")
{
	std::cout << "Presidential default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm",false, 25, 5), _target(target)
{
	std::cout << "Presidential constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
    : AForm(src), _target(src._target)
{
	std::cout << "Presidential copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!AForm::getIsSigned())
		throw(AForm::FormNotAssigned());
	if (executor.getGrade() > AForm::getGradeToExecute())
		throw(AForm::GradeTooLowException());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}
