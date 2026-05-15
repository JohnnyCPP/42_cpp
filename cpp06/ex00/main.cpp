#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

void testCharConversions(void)
{
	std::cout << "\n========== TESTING CHAR CONVERSIONS ==========" << std::endl;
	
	std::string testValues[] = {
		"'c'", "'A'", "'Z'", "'0'", "'9'", "'!'", "' '", "'~'"
	};
	int numTests = 8;
	int i = 0;
	
	while (i < numTests)
	{
		std::cout << "\n--- Testing: " << testValues[i] << " ---" << std::endl;
		ScalarConverter::convert(testValues[i]);
		i++;
	}
}

void testIntConversions(void)
{
	std::cout << "\n========== TESTING INT CONVERSIONS ==========" << std::endl;
	
	std::string testValues[] = {
		"0", "42", "-42", "127", "-128", "2147483647", "-2147483648"
	};
	int numTests = 7;
	int i = 0;
	
	while (i < numTests)
	{
		std::cout << "\n--- Testing: " << testValues[i] << " ---" << std::endl;
		ScalarConverter::convert(testValues[i]);
		i++;
	}
}

void testFloatConversions(void)
{
	std::cout << "\n========== TESTING FLOAT CONVERSIONS ==========" << std::endl;
	
	std::string testValues[] = {
		"0.0f", "42.0f", "-42.0f", "3.14f", "-2.71f", "42.5f",
		"nanf", "+inff", "-inff"
	};
	int numTests = 9;
	int i = 0;
	
	while (i < numTests)
	{
		std::cout << "\n--- Testing: " << testValues[i] << " ---" << std::endl;
		ScalarConverter::convert(testValues[i]);
		i++;
	}
}

void testDoubleConversions(void)
{
	std::cout << "\n========== TESTING DOUBLE CONVERSIONS ==========" << std::endl;
	
	std::string testValues[] = {
		"0.0", "42.0", "-42.0", "3.14159", "-2.71828", "42.5",
		"nan", "+inf", "-inf"
	};
	int numTests = 9;
	int i = 0;
	
	while (i < numTests)
	{
		std::cout << "\n--- Testing: " << testValues[i] << " ---" << std::endl;
		ScalarConverter::convert(testValues[i]);
		i++;
	}
}

void testEdgeCases(void)
{
	std::cout << "\n========== TESTING EDGE CASES ==========" << std::endl;
	
	std::string testValues[] = {
		"2147483648",		// overflow int max + 1
		"-2147483649",		// overflow int min - 1
		"999999999999999",
		"0.0000001f",
		"1000000000.0",
		"'\\''",
		"'\"'",
		"'\\n'"
	};
	int numTests = 8;
	int i = 0;
	
	while (i < numTests)
	{
		std::cout << "\n--- Testing: " << testValues[i] << " ---" << std::endl;
		ScalarConverter::convert(testValues[i]);
		i++;
	}
}

void testInvalidInputs(void)
{
	std::cout << "\n========== TESTING INVALID INPUTS ==========" << std::endl;
	
	std::string testValues[] = {
		"hello", "42f", "42.f", ".42", "42.0ff", "''", "'ab'", "12abc", ""
	};
	int numTests = 9;
	int i = 0;
	
	while (i < numTests)
	{
		std::cout << "\n--- Testing: " << testValues[i] << " ---" << std::endl;
		ScalarConverter::convert(testValues[i]);
		i++;
	}
}

void runAllTests(void)
{
	std::cout << "==============================================" << std::endl;
	std::cout << "     SCALAR CONVERTER - COMPREHENSIVE TESTS    " << std::endl;
	std::cout << "==============================================" << std::endl;
	
	testCharConversions();
	testIntConversions();
	testFloatConversions();
	testDoubleConversions();
	testEdgeCases();
	testInvalidInputs();
	
	std::cout << "\n==============================================" << std::endl;
	std::cout << "                 TESTS COMPLETED               " << std::endl;
	std::cout << "==============================================" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal> or ./convert test" << std::endl;
		return 1;
	}
	std::string arg = argv[1];
	if (arg == "test")
		runAllTests();
	else
	{
		std::cout << "Converting: " << arg << std::endl;
		std::cout << "------------------------" << std::endl;
		ScalarConverter::convert(arg);
	}
	return 0;
}
