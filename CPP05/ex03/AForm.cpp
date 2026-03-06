/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:38:42 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/15 09:41:29 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <ostream>
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToAssign(150),
	_gradeToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, bool isSigned, int16_t gradeToAssign, int16_t gradeToExecute) : _name(name), _isSigned(isSigned), _gradeToAssign(gradeToAssign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToAssign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToAssign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _isSigned(src._isSigned),
	_gradeToAssign(src._gradeToAssign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int16_t AForm::getGradeToAssign() const
{
	return (this->_gradeToAssign);
}

int16_t AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_gradeToAssign < bureaucrat.getGrade())
		throw(AForm::GradeTooLowException());
	this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::FormNotAssigned::what() const throw()
{
	return ("Form hasn't assigned");
}

std::ostream &operator<<(std::ostream &os, const AForm &src)
{
	os << "AForm: " << src.getName()
	   << "\nSigned: " << (src.getIsSigned() ? "Yes" : "No")
	   << "\nGrade to Assign: " << src.getGradeToAssign()
	   << "\nGrade to Execute: " << src.getGradeToExecute();
	return (os);
}
