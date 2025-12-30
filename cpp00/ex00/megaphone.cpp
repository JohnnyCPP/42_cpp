#include <cstdlib>
#include <iostream>
#include <cctype>

const	std::string	NOISE = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

void	println(const std::string& str)
{
	std::cout << str << std::endl;
}

void	toUpper(std::string& str)
{
	int	length;
	int	i;

	length = static_cast<int>(str.length());
	i = 0;
	while (i < length)
	{
		str[i] = std::toupper(str[i]);
		i ++;
	}
}

void	printUpperCase(char **strList)
{
	std::string	message;
	int			i;

	if (!strList || !strList[0])
		return ;
	message = "";
	i = 0;
	while (strList[i])
		message += strList[i ++];
	toUpper(message);
	println(message);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		println(NOISE);
	else
		printUpperCase(argv + 1);
	return (EXIT_SUCCESS);
}
