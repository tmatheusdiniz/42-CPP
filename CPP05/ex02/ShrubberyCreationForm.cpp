/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:44:26 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/17 15:03:49 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", false, 145, 137), _target("default")
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, false, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &src)
{
	if(this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout << "ShrubberyCreationForm operator assignment called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!AForm::getIsSigned())
		throw(AForm::FormNotAssigned());
	if (executor.getGrade() > AForm::getGradeToExecute())
		throw(AForm::GradeTooLowException());
	std::ofstream myfile;
	myfile.open(_target + "shrubbery");
	if (!myfile.is_open())
	{
		std::cerr << "Error: Could not create file "
			<< _target + "shrubbery" << std::endl;
		return ;
	}
	myfile << "       _-_\n";
	myfile << "    /~~   ~~\\\n";
	myfile << " /~~         ~~\\\n";
	myfile << "{               }\n";
	myfile << " \\  _-     -_  /\n";
	myfile << "   ~  \\\\ //  ~\n";
	myfile << "_- -   | | _- _\n";
	myfile << "  _ -  | |   -_\n";
	myfile << "      // \\\\\n";
	myfile.close();
	std::cout << "Shrubbery created in file: "
		<< _target + "shrubbery" << std::endl;
}
