#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <cstdlib>
# include <climits>
# include <stdexcept>
# include <limits>
# include <cmath>

class	DatabaseOpenException : public std::runtime_error
{
public:

	DatabaseOpenException(const std::string& msg) : std::runtime_error(msg)
	{}
};

class BitcoinExchange
{
private:

	std::map<std::string, double>	data;

	bool	isLeapYear(int year) const;
	bool	isValidDate(std::string const& date) const;
	bool	isValidValue(float value) const;
	float	getExchangeRate(std::string const& date) const;
	bool	wouldOverflow(double value, double rate) const;
	double	safeMultiply(double value, double rate) const;

public:

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const& that);
	~BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange const& that);

	void	loadDatabase(std::string const& filename);
	void	processInputDB(std::string const& filename);
};

#endif
