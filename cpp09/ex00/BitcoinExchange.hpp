#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <climits>

class BitcoinExchange
{
	private:

		std::map<std::string, double>	data;

		bool	isLeapYear(int year) const;
		bool	isValidDate(std::string const& date) const;
		bool	isValidValue(float value) const;
		float	getExchangeRate(std::string const& date) const;

	public:

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const& that);
		~BitcoinExchange();
		BitcoinExchange& operator=(BitcoinExchange const& that);

		void	loadDatabase(std::string const& filename);
		void	processInput(std::string const& filename);
};

#endif
