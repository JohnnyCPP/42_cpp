#include <string>
#include <iostream>
#include <cstdlib>

static	void	print(const std::string str)
{
	std::cout << str;
}

static	void	println()
{
	std::cout << std::endl;
}

static	void	println(const std::string str)
{
	::print(str);
	::println();
}

int	main()
{
	std::string		text;
	std::string		*stringPTR;
	std::string&	stringREF = text;

	text = "HI THIS IS BRAIN";
	stringPTR = &text;
	// ===== print memory =====
	print("Memory address of string variable:\t");
	std::cout << &text << std::endl;
	print("Memory address held by stringPTR:\t");
	std::cout << &stringPTR << std::endl;
	print("Memory address held by stringREF:\t");
	std::cout << &stringREF << std::endl;
	// ===== print value =====
	print("Value of string variable:\t\t");
	println(text);
	print("Value pointed to by stringPTR:\t\t");
	println(*stringPTR);
	print("Value pointed to by stringREF:\t\t");
	println(stringREF);
	return (EXIT_SUCCESS);
}
