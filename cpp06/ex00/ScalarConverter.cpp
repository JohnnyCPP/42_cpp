#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{}

ScalarConverter::ScalarConverter(const ScalarConverter& that) 
{ 
	(void) that; 
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& that)
{
	(void) that;
	return *this;
}

ScalarConverter::~ScalarConverter() 
{}

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal)
{
	size_t i;

	i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i ++;
	if (i >= literal.length())
		return false;
	for (; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	size_t i = 0;
	bool hasDot = false;
	bool hasF = false;

	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	if (literal[i] == '-' || literal[i] == '+')
		i ++;
	if (i >= literal.length())
		return false;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (literal[i] == 'f' || literal[i] == 'F')
		{
			if (hasF || i != literal.length() - 1)
				return false;
			hasF = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	return hasF && (hasDot || literal.find('.') != std::string::npos);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	size_t i = 0;
	bool hasDot = false;

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	if (literal[i] == '-' || literal[i] == '+')
		i ++;
	if (i >= literal.length())
		return false;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	return hasDot;
}

void ScalarConverter::convertFromChar(const std::string& literal)
{
	char c = literal[1];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

// interprets an integer value in a byte string pointed to by str.
//
// long      strtol( const char* str, char** str_end, int base );

void ScalarConverter::convertFromInt(const std::string& literal)
{
	long intValue = std::strtol(literal.c_str(), NULL, 10);
	float f = static_cast<float>(intValue);
	double d = static_cast<double>(intValue);

	if (intValue < 0 || intValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (intValue < 32 || intValue == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;

	if (intValue > std::numeric_limits<int>::max() || intValue < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(intValue) << std::endl;

	if (static_cast<long>(f) != intValue)
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;
	
	if (static_cast<long>(d) != intValue)
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

// interprets a floating point value in a byte string pointed to by str.
//
// double      strtod ( const char* str, char** str_end );

void ScalarConverter::convertFromFloat(const std::string& literal)
{
	float f;
	
	if (literal == "nanf")
		f = std::numeric_limits<float>::quiet_NaN();
	else if (literal == "+inff")
		f = std::numeric_limits<float>::infinity();
	else if (literal == "-inff")
		f = -std::numeric_limits<float>::infinity();
	else
		f = static_cast<float>(std::strtod(literal.c_str(), NULL));
	
	double d = static_cast<double>(f);
	int i = static_cast<int>(f);
	
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		std::cout << "char: impossible" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		std::cout << "int: impossible" << std::endl;
	else if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	
	if (literal == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (literal == "+inff")
		std::cout << "float: +inff" << std::endl;
	else if (literal == "-inff")
		std::cout << "float: -inff" << std::endl;
	else if (f - static_cast<int>(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	
	if (literal == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (literal == "+inff")
		std::cout << "double: +inf" << std::endl;
	else if (literal == "-inff")
		std::cout << "double: -inf" << std::endl;
	else if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& literal)
{
	double d;
	
	if (literal == "nan")
		d = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "+inf")
		d = std::numeric_limits<double>::infinity();
	else if (literal == "-inf")
		d = -std::numeric_limits<double>::infinity();
	else
		d = std::strtod(literal.c_str(), NULL);
	
	float f = static_cast<float>(d);
	int i = static_cast<int>(d);
	
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		std::cout << "char: impossible" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		std::cout << "int: impossible" << std::endl;
	else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	
	if (literal == "nan")
		std::cout << "float: nanf" << std::endl;
	else if (literal == "+inf")
		std::cout << "float: +inff" << std::endl;
	else if (literal == "-inf")
		std::cout << "float: -inff" << std::endl;
	else if (f - static_cast<int>(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	
	if (literal == "nan")
		std::cout << "double: nan" << std::endl;
	else if (literal == "+inf")
		std::cout << "double: +inf" << std::endl;
	else if (literal == "-inf")
		std::cout << "double: -inf" << std::endl;
	else if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (isChar(literal))
		convertFromChar(literal);
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else
		std::cout << "Error: Invalid literal format" << std::endl;
}
