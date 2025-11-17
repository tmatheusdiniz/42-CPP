/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 09:34:21 by mreinald          #+#    #+#             */
/*   Updated: 2025/09/22 09:39:17 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <cstring>
#include <iostream>

int main (int v, char**str)
{
	if (v == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		for (int i = 1; i < v; i ++)
		{
			std::string input = str[i];
			for (std::size_t j = 0; j < input.length(); j++)
				std::cout << (char)std::toupper(input[j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
