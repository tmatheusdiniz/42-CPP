#include "RPN.hpp"
#include <cstddef>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>

bool hasOnlyValidCharacters(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string values;
	while (iss >> values)
	{
		if (values.size() > 1)
			return (false);
	}
	for (std::size_t i = 0; i < expression.length(); ++i)
	{
		char c = expression[i];

		if (!std::isdigit(c) &&
			!std::isspace(c) &&
			c != '+' &&
			c != '-' &&
			c != '*' &&
			c != '/')
		{
			return (false);
		}
	}
	return (true);
}

int main(int c, char **p)
{
	if (c != 2
		|| static_cast<std::string>(p[1]).empty()
		|| !(hasOnlyValidCharacters(p[1])))
	{
		
		std::cerr << "Error: use only digits 0 - 9 and the operators: + - * /" << std::endl;
		exit (1);
	}
	try
	{
		RPN expression;
		std::cout << expression.evaluate(p[1]) << std::endl;
	}
	catch (std::runtime_error& err)
	{
		std::cout << err.what() << std::endl;
	}
}
