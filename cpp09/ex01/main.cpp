#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN		rpn;
	double	result;

	if (argc != 2)
	{
		std::cerr << "Usage: RPN <expression>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const RPNOperationException& exception)
	{
		std::cerr << exception.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
