/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:49:43 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/24 10:49:05 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <ostream>

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << "\n";
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << "\n";
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << "\n";
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
	std::cout << "\n";
}

int handlingChoice(std::string level)
{
	int x;
	if (level == "DEBUG")
		x = 0;
	else if (level == "INFO")
		x = 1;
	else if (level == "WARNING")
		x = 2;
	else if (level == "ERROR")
		x = 3;
	else
		x = 4;
	switch (x)
	{
		case 0:
			return (0);
		case 1:
			return (1);
		case 2:
			return (2);
		case 3:
			return (3);
		case 4:
			return (-1);
	};
	return (-1);
}

void Harl::complain( std::string level )
{
	void (Harl::*choices[])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int choice = handlingChoice(level);
	if (choice == -1)
	{
		std::cout << BOLD_GREEN <<
			"[ Probably complaining about insignificant problems ]"
			<< DEFAULT << std::endl;
		return ;
	}
	for (int i = choice; i < 4; i ++)
		(this->*choices[i])();
}
