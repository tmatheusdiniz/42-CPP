#include "RPN.hpp"
#include <cctype>
#include <cstddef>
#include <ostream>
#include <sstream>
#include <iostream>
#include <stdexcept>

RPN::RPN()
{
	
};

RPN::RPN(const RPN& other)
{
	this->_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN()
{
	
}

 bool RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	else
		return (false);
}

void RPN::applyOperator(char op)
{
	int firstValue;
	int secondValue;
	int value;
	firstValue = _stack.top();
	_stack.pop();
	secondValue = _stack.top();
	_stack.pop();
	if (op == '+')
		value = firstValue + secondValue;
	if (op == '-')
		value = secondValue - firstValue;
	if (op == '*')
		value = firstValue * secondValue;
	if (op == '/')
	{
		if (firstValue == 0)
			throw std::runtime_error("Error: division by zero");
		value = secondValue / firstValue;
	}
	_stack.push(value);
}

int RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	char token;
	while (iss >> token)
	{
		if (std::isdigit(token))
		{
			_stack.push(token - '0');
		}
		else if (RPN::isOperator(token))
		{
			if (_stack.size() >= 2)
				RPN::applyOperator(token);
			else
				throw std::runtime_error("Error: Too many operators");
		}
	}
	if (_stack.size() == 1)
	{
		int value = _stack.top();
		_stack.pop();
		return (value);
	}
	else
	{
		while (!(_stack.empty()))
			_stack.pop();
		throw std::runtime_error("Error: Too many operands");
	}
}
