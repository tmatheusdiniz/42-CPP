/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreinald <mreinald@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:21:52 by mreinald          #+#    #+#             */
/*   Updated: 2025/10/21 14:40:13 by mreinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HandleFile.hpp"

int main(int v, char** str)
{
	if (v != 4)
		return ((std::cout 
		<< "the program expects 3 paremeters: file name and two strings"
		<< std::endl), 1);
	handleFile(str[1], str[2], str[3]);
}
