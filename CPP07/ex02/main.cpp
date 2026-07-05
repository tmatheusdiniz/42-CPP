#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
	// Empty array construction
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;

	// Sized construction: elements are default-initialized
	Array<int> numbers(5);
	std::cout << "numbers.size() = " << numbers.size() << std::endl;
	std::cout << "default value at [0] = " << numbers[0] << std::endl;

	// Fill the array through the subscript operator
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = static_cast<int>(i) * 10;

	std::cout << "numbers: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	// Copy construction is a deep copy
	Array<int> copy(numbers);
	copy[0] = 999;
	std::cout << "after modifying the copy -> numbers[0] = " << numbers[0]
			  << ", copy[0] = " << copy[0] << std::endl;

	// Assignment operator is a deep copy too
	Array<int> assigned;
	assigned = numbers;
	assigned[1] = -1;
	std::cout << "after modifying assigned -> numbers[1] = " << numbers[1]
			  << ", assigned[1] = " << assigned[1] << std::endl;

	// Out-of-bounds access throws
	try
	{
		std::cout << "accessing numbers[42]..." << std::endl;
		std::cout << numbers[42] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "caught exception: " << e.what() << std::endl;
	}

	// Works with any type
	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "template";
	words[2] = "world";
	std::cout << "words: ";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";
	std::cout << std::endl;

	// const array: only the const operator[] is usable
	const Array<int> readOnly(numbers);
	std::cout << "readOnly[2] = " << readOnly[2] << std::endl;

	return (0);
}
