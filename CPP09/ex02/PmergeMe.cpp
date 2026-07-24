#include "PmergeMe.hpp"

#include <sstream>
#include <stdexcept>
#include <climits>
#include <cctype>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vec(other._vec), _deque(other._deque)
{
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deque = other._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

int	PmergeMe::parseInt(const std::string& token)
{
	if (token.empty())
		throw std::invalid_argument("Error");

	for (std::string::size_type i = 0; i < token.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			throw std::invalid_argument("Error");
	}

	long	value = 0;
	for (std::string::size_type i = 0; i < token.size(); ++i)
	{
		value = value * 10 + (token[i] - '0');
		if (value > INT_MAX)
			throw std::out_of_range("Error");
	}

	if (value <= 0)
		throw std::out_of_range("Error");

	return (static_cast<int>(value));
}

void	PmergeMe::parseArguments(int argc, char** argv)
{
	if (argc < 2)
		throw std::invalid_argument("Error");

	for (int i = 1; i < argc; ++i)
	{
		std::istringstream	iss(argv[i]);
		std::string			token;

		while (iss >> token)
		{
			int	value = parseInt(token);
			_vec.push_back(value);
			_deque.push_back(value);
		}
	}

	if (_vec.empty())
		throw std::invalid_argument("Error");
}
