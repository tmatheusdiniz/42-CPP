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

int main(int v, char** str)
{
	if (v <= 2)
	{
		std::cout << "you must input at least 2 paremeters. e.g: ./bureaucrat name grade" << std::endl;
		return (1);
	}
	try
	{
		if (str[1] && str[2])
		{
			Bureaucrat a(str[1], std::atoi(str[2]));
			std::cout << "first Bureaucrat name: " << a.getName() << std::endl;
			std::cout << "first Bureaucrat grade: " << a.getGrade() << std::endl;
			Bureaucrat b("Diniz", 3);
			std::cout << "Second Bureaucrat name: " << a.getName() << std::endl;
			std::cout << "Second Bureaucrat grade: " << b.getGrade() << std::endl;
			b = a;
			std::cout << "Second Bureaucrat grade: " << b.getGrade() << std::endl;
		}
	} catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}
