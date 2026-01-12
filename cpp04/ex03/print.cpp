#include "print.hpp"

void	println(const std::string& str)
{
	std::cout << str << std::endl;
}

std::string	toString(int n)
{
	std::stringstream	stream;

	stream << n;
	return (stream.str());
}
