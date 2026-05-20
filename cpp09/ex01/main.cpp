#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN		rpn;
	double	result;

	if (argc != 2)
	{
		std::cerr << "Usage: RPN <expression>" << std::endl;
		return (1);
	}
	result = rpn.evaluate(argv[1]);
	if (result != 0 || (argv[1][0] == '0' && argv[1][1] == '\0'))
		std::cout << result << std::endl;
	return (0);
}
