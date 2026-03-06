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
		Bureaucrat Matheus(str[1], std::atoi(str[2]));
		ShrubberyCreationForm formS("S_Form");
		RobotomyRequestForm formR("R_FORM");
		PresidentialPardonForm formP("P_FORM");
		Matheus.signForm(formR);
		Matheus.executeForm(formR);
		Matheus.signForm(formS);
		Matheus.executeForm(formS);

		Bureaucrat king(str[3], std::atoi(str[4]));
		king.executeForm(formP);
		Matheus.signForm(formP);
		king.executeForm(formP);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
