# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : data()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& that) : data(that.data)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & that)
{
	if (this != &that)
		data = that.data;
	return (*this);
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool	BitcoinExchange::isValidDate(std::string const& date) const
{
	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	year;
	int	month;
	int	day;

	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	std::stringstream	year_stream(date.substr(0, 4));
	std::stringstream	month_stream(date.substr(5, 2));
	std::stringstream	day_stream(date.substr(8, 2));
	year_stream >> year;
	month_stream >> month;
	day_stream >> day;
	if (year < 2009) // because Bitcoin didn't exist before 2009
		return (false);
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if (month == 2 && this->isLeapYear(year))
		daysInMonth[1] = 29;
	return (day <= daysInMonth[month - 1]);
}

bool	BitcoinExchange::isValidValue(float value) const
{
	return (value >= 0 && value <= 1000);
}

// return -1 when input.txt date is lower than data.csv any date
//
// otherwise, return exchange_rate or the exchange_rate of the lower match found
float	BitcoinExchange::getExchangeRate(std::string const& date) const
{
	std::map<std::string, double>::const_iterator	iterator;
	float											exchange_rate;
	
	iterator = data.find(date);
	if (iterator != data.end())
	{
		exchange_rate = static_cast<float>(iterator->second);
		return (exchange_rate);
	}
	iterator = data.lower_bound(date);
	if (iterator == data.begin() && iterator->first > date)
		return (-1);
	if (iterator == data.begin())
	{
		exchange_rate = static_cast<float>(iterator->second);
		return (exchange_rate);
	}
	if (iterator == data.end() || iterator->first != date)
	{
		if (iterator != data.begin())
			iterator --;
	}
	exchange_rate = static_cast<float>(iterator->second);
	return (exchange_rate);
}

bool	BitcoinExchange::wouldOverflow(double value, double rate) const
{
	if (value == 0.0 || rate == 0.0)
		return (false);
	if (value > 0.0 && rate > 0.0)
	{
		if (value > std::numeric_limits<float>::max() / rate)
			return (true);
	}
	else if (value < 0.0 && rate < 0.0)
	{
		if (value < std::numeric_limits<float>::max() / rate)
			return (true);
	}
	return (false);
}

double	BitcoinExchange::safeMultiply(double value, double rate) const
{
	if (wouldOverflow(value, rate))
		return (-1.0);
	return (value * rate);
}

void	BitcoinExchange::loadDatabase(std::string const& filename)
{
	std::ifstream		file(filename.c_str());
	std::string			line;
	std::string			date;
	std::string			lastDate;
	std::string			priceStr;
	double				price;
	size_t				commaPos;
	
	if (!file.is_open())
		throw DatabaseOpenException("Error: could not open database file.");
	if (!std::getline(file, line))
	{
		file.close();
		throw DatabaseOpenException("Error: the database is empty.");
	}
	if (line != "date,exchange_rate")
	{
		file.close();
		throw DatabaseOpenException("Error: invalid database header. Expected 'date,exchange_rate'.");
	}
	while (std::getline(file, line))
	{
		if (line.empty())
			throw DatabaseOpenException("Error: found an empty line in the database file.");
		commaPos = line.find(',');
		if (commaPos == std::string::npos)
			throw DatabaseOpenException("Syntax error: the comma is missing in a line of the database file.");
		date = line.substr(0, commaPos);
		if (!isValidDate(date))
			throw DatabaseOpenException("Syntax error: invalid date in the database file.");
		if (data.find(date) != data.end())
		{
			std::stringstream errorMsg;
			errorMsg << "Error: duplicate date found in database => " << date;
			throw DatabaseOpenException(errorMsg.str());
		}
		if (!lastDate.empty() && date <= lastDate)
		{
			std::stringstream errorMsg;
			errorMsg << "Error: dates are not in chronological order: current '" << date 
			         << "' is lower than previous '" << lastDate << "'";
			throw DatabaseOpenException(errorMsg.str());
		}
		priceStr = line.substr(commaPos + 1);
		std::stringstream	stream(priceStr);
		stream >> price;
		if (stream.fail() || priceStr[0] == '.')
			throw DatabaseOpenException("Error: an error occurred converting a price string into a double when parsing the database file.");
		if (price < 0)
			throw DatabaseOpenException("Error: the value of a price found in the database file is less than zero.");
		data[date] = price;
		lastDate = date;
	}
	file.close();
	if (this->data.empty())
		throw DatabaseOpenException("Error: the database is empty.");
}

void	BitcoinExchange::processInputDB(std::string const& filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::string		date;
	std::string		valueStr;
	float			value;
	float			rate;
	size_t			pipePos;
	double			result;
	
	if (!file.is_open())
		throw DatabaseOpenException("Error: could not open input database.");
	if (!std::getline(file, line))
	{
		file.close();
		throw DatabaseOpenException("Error: the input database is empty.");
	}
	if (line != "date | value")
	{
		file.close();
		throw DatabaseOpenException("Error: invalid input database header. Expected 'date | value'.");
	}
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: found an empty line in the input database file." << std::endl;
			continue ;
		}
		pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: the pipe is missing in a line of the input database file." << std::endl;
			continue ;
		}
		date = line.substr(0, pipePos);
		if (!date.empty() && date[date.size() - 1] == ' ')
			date.erase(date.size() - 1);
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}
		valueStr = line.substr(pipePos + 1);
		if (!valueStr.empty() && valueStr[0] == ' ')
			valueStr.erase(0, 1);
		std::stringstream	stream(valueStr);
		stream >> value;
		if (stream.fail())
		{
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue ;
		}
		if (!isValidValue(value))
		{
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		rate = getExchangeRate(date);
		if (rate == -1)
		{
			std::cerr << "Error: according to the database file, bitcoin does not have an exchange rate on this date => " << date << std::endl;
			continue ;
		}
		result = safeMultiply(static_cast<double>(value), static_cast<double>(rate));
		if (result == -1.0)
		{
			std::cerr << "Error: the product of this value overflows the maximum value of a float (" << value << " * " << rate << ")" << std::endl;
			continue ;
		}
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	file.close();
}
