#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	bExchange;

	if (argc != 2)
	{
		std::cerr << "Usage: btc <input_file>" << std::endl;
		return (1);
	}
	bExchange.loadDatabase("data.csv");
	bExchange.processInput(argv[1]);
	return (0);
}
