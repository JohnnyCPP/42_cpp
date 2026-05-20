# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& that)
{
	*this = that;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & that)
{
	if (this != &that)
	{
		this->data = that.data;
	}
	return (*this);
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool	BitcoinExchange::isValidDate(std::string const& date) const
{
	int	year;
	int	month;
	int	day;

	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	std::stringstream	yss(date.substr(0, 4));
	std::stringstream	mss(date.substr(5, 2));
	std::stringstream	dss(date.substr(8, 2));
	yss >> year;
	mss >> month;
	dss >> day;
	if (year < 1970 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && this->isLeapYear(year))
		daysInMonth[1] = 29;
	return (day <= daysInMonth[month - 1]);
}

bool	BitcoinExchange::isValidValue(float value) const
{
	return (value >= 0 && value <= 1000);
}

float	BitcoinExchange::getExchangeRate(std::string const& date) const
{
	std::map<std::string, double>::const_iterator	it;
	
	it = this->data.find(date);
	if (it != this->data.end())
		return (static_cast<float>(it->second));
	it = this->data.lower_bound(date);
	if (it == this->data.begin())
		return (static_cast<float>(it->second));
	if (it == this->data.end() || it->first != date)
	{
		if (it != this->data.begin())
			it --;
	}
	return (static_cast<float>(it->second));
}

void	BitcoinExchange::loadDatabase(std::string const& filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::string		date;
	std::string		priceStr;
	double			price;
	size_t			commaPos;
	bool			firstLine;
	
	if (!file.is_open())
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return ;
	}
	firstLine = true;
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue ;
		}
		if (line.empty())
			continue ;
		commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue ;
		date = line.substr(0, commaPos);
		priceStr = line.substr(commaPos + 1);
		std::stringstream	ss(priceStr);
		ss >> price;
		this->data[date] = price;
	}
	file.close();
}

void	BitcoinExchange::processInput(std::string const& filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::string		date;
	std::string		valueStr;
	float			value;
	float			rate;
	size_t			pipePos;
	bool			firstLine;
	
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return ;
	}
	firstLine = true;
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue ;
		}
		if (line.empty())
			continue ;
		pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = line.substr(0, pipePos);
		valueStr = line.substr(pipePos + 1);
		while (!date.empty() && date[date.size() - 1] == ' ')
			date.erase(date.size() - 1);
		while (!date.empty() && date[0] == ' ')
			date.erase(0, 1);
		while (!valueStr.empty() && valueStr[0] == ' ')
			valueStr.erase(0, 1);
		if (!this->isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}
		std::stringstream	ss(valueStr);
		ss >> value;
		if (ss.fail())
		{
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue ;
		}
		if (!this->isValidValue(value))
		{
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		rate = this->getExchangeRate(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	file.close();
}
