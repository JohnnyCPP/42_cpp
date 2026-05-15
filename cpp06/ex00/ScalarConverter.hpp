#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <limits>
# include <cmath>
# include <cstdlib>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter& that);
		ScalarConverter& operator=(const ScalarConverter& that);
		~ScalarConverter();

		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		
		static void convertFromChar(const std::string& literal);
		static void convertFromInt(const std::string& literal);
		static void convertFromFloat(const std::string& literal);
		static void convertFromDouble(const std::string& literal);

	public:

		static void convert(const std::string& literal);
};

#endif
