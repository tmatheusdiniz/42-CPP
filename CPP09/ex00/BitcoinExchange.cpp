#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

static std::string	trim(const std::string& s)
{
	const std::string	spaces = " \t\r\n\v\f";
	std::size_t	first = s.find_first_not_of(spaces);

	if (first == std::string::npos)
		return ("");
	return (s.substr(first, s.find_last_not_of(spaces) - first + 1));
}

BitcoinExchange::BitcoinExchange()
{
	this->loadDatabase("./database/data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Failed to open database file");
	this->_database.clear();
	std::string	line;
	while (std::getline(file, line))
	{
		line = trim(line);
		if (line.empty())
			continue;
		if (line == "date,exchange_rate")
			continue;
		std::size_t comma = line.find(',');
		if (comma == std::string::npos)
			throw std::runtime_error("Invalid database line: " + line);
		std::string	date = trim(line.substr(0, comma));
		std::string	rate = trim(line.substr(comma + 1));
		double	value;
		if (!isValidDate(date))
			throw std::runtime_error("Invalid date in database: " + date);
		if (!parseValue(rate, value) || value < 0)
			throw std::runtime_error("Invalid rate in database: " + rate);
		this->_database[date] = value;
	}
	if (this->_database.empty())
		throw std::runtime_error("Database is empty");
}

/*
** The map is ordered by date, and the dates are zero-padded, so lexicographic
** order matches chronological order. upper_bound gives the first date strictly
** after the one we want; stepping back once lands on the closest lower date.
*/
double BitcoinExchange::getRateForDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator	it;

	it = this->_database.upper_bound(date);
	if (it == this->_database.begin())
		throw std::runtime_error("no exchange rate available before this date");
	--it;
	return (it->second);
}

void BitcoinExchange::processInput(const std::string& filename) const
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("could not open file.");

	std::string	line;
	bool		first = true;
	while (std::getline(file, line))
	{
		line = trim(line);
		if (first)
		{
			first = false;
			if (line == "date | value")
				continue;
		}
		if (line.empty())
			continue;

		std::size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string	date = trim(line.substr(0, pipe));
		std::string	rawValue = trim(line.substr(pipe + 1));
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		double	value;
		if (!parseValue(rawValue, value))
		{
			std::cout << "Error: bad input => " << rawValue << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			double	rate = this->getRateForDate(date);
			std::cout << date << " => " << value << " = "
				<< value * rate << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}

bool BitcoinExchange::parseValue(const std::string& s, double& out)
{
	if (s.empty())
		return (false);

	std::size_t	i = 0;
	if (s[i] == '+' || s[i] == '-')
		++i;
	if (i == s.size())
		return (false);

	bool	dot = false;
	bool	digit = false;
	for (; i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			if (dot || !digit || i == s.size() - 1)
				return (false);
			dot = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(s[i])))
			digit = true;
		else
			return (false);
	}
	if (!digit)
		return (false);
	out = std::atof(s.c_str());
	return (true);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (std::size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);
	if (day < 1)
		return (false);

	static const int	mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int					maxDay = mdays[month - 1];
	bool				leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (month == 2 && leap)
		maxDay = 29;
	return (day <= maxDay);
}
