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

int main(int v, char **str)
{
	if (v <= 5)
	{
		std::cout << "you must input at least 2 paremeters. e.g: ./bureaucrat name grade" << std::endl;
		return (1);
	}
	try
	{
		Form contract(str[3], false, std::atoi(str[4]), std::atoi(str[5]));
		Bureaucrat Matheus(str[1], std::atoi(str[2]));
		Matheus.signForm(contract);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
