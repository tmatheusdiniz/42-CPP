/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:53:39 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/04 18:01:56 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int16_t grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name)
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
	this->_grade = src._grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& src)
{
	std::cout << "Bureaucrat assigment operator called" << std::endl;
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int16_t Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementBureaucratLevel()
{
	if (_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	else
	 	-- _grade;
}

void Bureaucrat::decrementBureaucratLevel()
{
	if (_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	else
	 	++ _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high! Must be >= 1 ");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low! Must be <= 150");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}
