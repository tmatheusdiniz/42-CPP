#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	
}

void ScalarConverter::convert(const std::string& input)
{
	if (input.empty())
	{
		std::cout << "Error: Empty string provided." << std::endl;
		return ;
	}

	if (isSpecial(input))
	{
		convertFromSpecial(input);
	}
	else if (isChar(input))
	{
		convertFromChar(input[0]);
	}
	else if (isInt(input))
	{
		std::istringstream iss(input);
		int value;
		iss >> value;
		convertFromInt(value);
	}
	else if (isFloat(input))
	{
		std::string onlynumber = input.substr(0, input.length() - 1);
		std::istringstream iss(onlynumber);
		float value;
		iss >> value;
		convertFromFloat(value);
	}
	else if (isDouble(input))
	{
		std::istringstream iss(input);
		double value;
		iss >> value;
		convertFromDouble(value);
	}
	else
	{
		std::cout << "Error: Invalid input format." << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &input)
{
	if (input.length() == 1 && !isdigit(static_cast<unsigned char>(input[0])))
		return true;
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\''
		&& isprint(static_cast<unsigned char>(input[1])))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &input)
{
	if (input.empty())
		return (false);
	std::istringstream strm(input);
	int val;
	char left;
	return ((strm >> val) && !(strm >> left));
}

bool ScalarConverter::isDouble(const std::string &input)
{
	if (input.empty())
		return (false);
	std::istringstream strm(input);
	double val;
	char left;
	return ((strm >> val) && !(strm >> left)
			&& input.find('.') != std::string::npos);
}

bool ScalarConverter::isFloat(const std::string &input)
{
	if (input.empty())
		return (false);
	if (input[input.length() - 1] != 'f')
		return (false);
	std::string onlynumber = input.substr(0, input.length() - 1);
	std::istringstream strm(onlynumber);
	float val;
	char left;
	return ((strm >> val) && !(strm >> left)
			&& input.find('.') != std::string::npos);
}

bool ScalarConverter::isSpecial(const std::string& input)
{
	return (input == "nan" || input == "+inf" || input== "-inf"||
			input == "nanf" || input == "+inff" || input == "-inff");
}

void ScalarConverter::convertFromChar(char input)
{
	std::cout << "char: " << input << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << static_cast<float>(input) << std::endl;
	std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void ScalarConverter::convertFromInt(int input)
{
	if (input >= 0 && input <= 127)
	{
		if (isprint(static_cast<char>(input)))
			std::cout << "char: '" << static_cast<char>(input) << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(input) << "f" <<  std::endl;
	std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void ScalarConverter::convertFromFloat(float input)
{
	if (input >= 0 && input <= 127 && !std::isnan(input) && !std::isinf(input))
	{
		if (isprint(static_cast<char>(input)))
			std::cout << "char: '" << static_cast<char>(input) << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (input >= static_cast<float>(std::numeric_limits<int>::min())
		&& input <  static_cast<float>(std::numeric_limits<int>::max())
		&& !std::isinf(input) && !std::isnan(input))
			std::cout << "int: " << static_cast<int>(input) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

void ScalarConverter::convertFromDouble(double input)
{
	if (input >= 0 && input <= 127 && !std::isnan(input) && !std::isinf(input))
	{
		if (isprint(static_cast<char>(input)))
			std::cout << "char: '" << static_cast<char>(input) << "'"<< std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (input <= std::numeric_limits<int>::max() && input >= std::numeric_limits<int>::min()
		&& !std::isinf(input) && !std::isnan(input))
		std::cout << "int: " << static_cast<int>(input) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (input > std::numeric_limits<float>::max() || input < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
	}
	std::cout << "double: " << input << std::endl;
}


void ScalarConverter::convertFromSpecial(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;

	std::cout << "int: impossible" << std::endl;

	if (input == "nan" || input == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}
