#include "Array.hpp"
#include <array>
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

int main()
{
	// Below I have a built-in Array
	char chars[10];
	chars[0] = 'f';
	chars[1] = 'o';
	chars[2] = 'r';
	chars[3] = 't';
	chars[4] = 'y';
	chars[5] = 't';
	chars[6] = 'w';
	chars[7] = 'o';
	chars[8] = 44;
	std::cout << chars[8] << std::endl;

	// std container
	std::array<int, 2> values;
	values[0] = 42;
	values[1] = 42;
	std::cout << values.max_size() << std::endl;
	std::cout << values.back() << std::endl;

	// My class
	Array<int> numbers(5);
	std::cout << numbers.size() << std::endl;
	numbers[0] = 42;
	std::cout << numbers[0] << std::endl;
	try
	{
		std::cout << "exception out of bounds trigger: " << numbers[5] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	// testing const overloader
	const Array<char> letters(2);
	char c = letters[0];
	std::cout << c << std::endl;
}
