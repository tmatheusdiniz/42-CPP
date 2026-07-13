#include "Span.hpp"
#include <algorithm>
#include <ios>
#include <limits>
#include <stdexcept>
#include <vector>

Span::Span() : _N(0)
{

}

Span::Span(unsigned int n) :  _N(n)
{
	_values.reserve(n);
}


Span::Span(const Span& other) : _N(other._N), _values(other._values)
{

}

Span::~Span()
{

}


Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		_values = other._values;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (Span::_values.size() == _N)
		throw std::runtime_error("It is not possible to surpass N numbers allocated.");
	Span::_values.push_back(number);
}

int Span::shortestSpan()
{
	int shortest = std::numeric_limits<int>::max();
	if (_values.size() == 0 || _values.size() == 1)
		throw std::runtime_error("There isn't any number stored in Span");
	std::sort(_values.begin(), _values.end());
	for (std::vector<int>::iterator it = _values.begin(); it != _values.end() - 1; ++it)
	{
		int diff = *(it + 1) - *it;
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (_values.size() == 0 || _values.size() == 1)
		throw std::runtime_error("There isn't any number stored in Span");
	std::sort(_values.begin(), _values.end());
	std::vector<int>::iterator beginning = _values.begin();
	std::vector<int>::iterator end = _values.end() - 1;
	return (*end - *beginning);
}

int Span::spanSize()
{
	return (_values.size());
}
