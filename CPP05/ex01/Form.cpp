/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:38:42 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/15 09:41:29 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <ostream>
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToAssign(150),
	_gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, bool isSigned, int16_t gradeToAssign, int16_t gradeToExecute) : _name(name), _isSigned(isSigned), _gradeToAssign(gradeToAssign),
	_gradeToExecute(gradeToExecute)
{
	if (gradeToAssign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToAssign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned),
	_gradeToAssign(src._gradeToAssign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int16_t Form::getGradeToAssign() const
{
	return (this->_gradeToAssign);
}

int16_t Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_gradeToAssign < bureaucrat.getGrade())
		throw(Form::GradeTooLowException());
	this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &src)
{
	os << "Form: " << src.getName()
	   << "\nSigned: " << (src.getIsSigned() ? "Yes" : "No")
	   << "\nGrade to Assign: " << src.getGradeToAssign()
	   << "\nGrade to Execute: " << src.getGradeToExecute();
	return (os);
}
