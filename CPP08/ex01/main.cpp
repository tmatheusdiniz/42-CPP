#include "Span.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "throwing an exception by exceeding: ";
	try
	{
		sp.addNumber(7);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "throwing an exception by sending an empty object: ";
	Span empty(4);
	try
	{
		empty.shortestSpan();
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Running with repeated numbers" << std::endl;
	empty.addNumber(1);
	empty.addNumber(1);
	empty.addNumber(2);
	empty.addNumber(2);
	std::cout << "shortest: " << empty.shortestSpan() << std::endl;
	std::cout << "longest: " << empty.longestSpan() << std::endl;

	std::cout << "Running with negative numbers" << std::endl;
	Span negative(5);
	negative.addNumber(0);
	negative.addNumber(-4);
	negative.addNumber(-8);
	negative.addNumber(-6);
	std::cout << "shortest: " << negative.shortestSpan() << std::endl;
	std::cout << "longest: " << negative.longestSpan() << std::endl;

	Span addRange(10);
	addRange.addNumber(4);
	std::vector<int> numbers;
	for (int i = 1; i <= 5; ++i) 
	{
		numbers.push_back(i * 10);
	}
	addRange.addGroup(numbers.begin(), numbers.end());
	try
	{
		std::vector<int> moreNumbers(7, 42);
		std::cout << "Trying to add more numbers than capacity using addRange()..." << std::endl;
		addRange.addGroup(moreNumbers.begin(), moreNumbers.end());
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
