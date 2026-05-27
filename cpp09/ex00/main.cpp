#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	bExchange;

	if (argc != 2)
	{
		std::cerr << "Usage: btc <input_file>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		bExchange.loadDatabase("data.csv");
		bExchange.processInputDB(argv[1]);
	}
	catch (const DatabaseOpenException& exception)
	{
		std::cerr << exception.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
