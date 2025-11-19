/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:42:57 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/20 00:13:46 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main ()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory addresses:" << std::endl;
	std::cout << &str << std::endl;
	std::cout << static_cast<const void *>(stringPTR) << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "The values:" << std::endl;
	std::cout << "string content: " << str << std::endl;
	std::cout << "Pointer content: " << *stringPTR << std::endl;
	std::cout << "Reference content: " << stringREF << std::endl;
}
