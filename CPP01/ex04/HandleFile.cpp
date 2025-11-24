/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleFile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:22:37 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/22 11:45:54 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HandleFile.hpp"
#include <iostream>

std::string replaceOccurence(std::string s, std::string s1, std::string s2)
{
	int size = s.length();
	int size_s1= s1.length();
	std::string new_buffer;

	for (int i = 0; i < size; i++)
	{
		if ((i + size_s1 < size) && (s.substr(i, size_s1) == s1))
		{
			new_buffer += s2;
			i += size_s1 - 1;
		}
		else
			new_buffer += s[i];
	}
	return (new_buffer);
}

void handleFile(std::string filename, std::string s1, std::string s2)
{
	std::fstream file;
	std::string s;
	char c;

	if (s1.empty() || s2.empty())
	{
		std::cout << "the strings must not be empty" << std::endl;
		return ;
	}
	file.open(filename.c_str(), std::ifstream::in);
	if (!file.is_open())
	{
		std::cout << "Occurred an error trying to open the file" << std::endl;
		return ;
	}
	while ((c = file.get()) != EOF)
		s+= static_cast<char>(c);
	file.close();
	std::string newBuffer = replaceOccurence(s, s1, s2);
	std::ofstream newFile((filename + ".replace").c_str());
	if (!newFile.is_open())
	{
		std::cout << "Occurred an error trying to open the file" << std::endl;
		return ;
	}
	newFile << newBuffer;
	newFile.close();
}
