#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << "<value>" << std::endl;
		return 1;
	}
	if (argv[1][0] == '\0' || argv[1][0] == ' ' || argv[1][0] == '\t')
	{
		std::cerr << "Error: Empty string provided." << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
