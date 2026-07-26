/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a00100010 <mreinald@student.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 22:52:16 by a00100010         #+#    #+#             */
/*   Updated: 2026/06/29 22:26:09 by a00100010        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static bool isChar(const std::string& input);
		static bool isInt(const std::string& input);
		static bool isFloat(const std::string& input);
		static bool isDouble(const std::string& input);
		static bool isSpecial(const std::string& input);
		static void convertFromChar(char input);
		static void convertFromInt(int input);
		static void convertFromFloat(float input);
		static void convertFromDouble(double input);
		static void convertFromSpecial(const std::string& input);
	public:
		static void convert(const std::string& input);
};

#endif
