#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
	std::fstream file("./database/data.csv");
	if (!file.is_open())
		throw std::runtime_error("Failed to open database file");
	std::string line;
	while (std::getline(file, line, ','))
	{
		if (line.empty())
			continue;
		if (line == "date,exchange_rate")
			continue;
	}
};
