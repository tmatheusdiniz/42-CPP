/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:08:42 by mreinald          #+#    #+#             */
/*   Updated: 2025/12/05 14:28:53 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <atomic>

int main(int v, char **str)
{
	std::srand(std::time(NULL));
	if (v <= 2)
	{
		std::cout << "you must input at least 2 paremeters. e.g: ./bureaucrat name grade" << std::endl;
		return (1);
	}
	try
	{
		AForm *test[3];
		Intern poorGuy;
		Bureaucrat sirGrey(str[1], std::atoi(str[2]));
		test[0] = poorGuy.makeForm("robotomy request", "index 0");
		test[1] = poorGuy.makeForm("shrubbery request", "index 1");
		test[2] = poorGuy.makeForm("presidential request", "index 2");
		std::cout << test[0]->getGradeToAssign() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
