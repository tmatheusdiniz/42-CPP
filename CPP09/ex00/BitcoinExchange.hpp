#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _database;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void	loadDatabase(const std::string& filename);
		void	processInput(const std::string& filename) const;

		double	getRateForDate(const std::string& date) const;

		static bool	isValidDate(const std::string& date);
		static bool	parseValue(const std::string& str, double& value,
						std::string& error);
		static std::string	trim(const std::string& str);
};

#endif
