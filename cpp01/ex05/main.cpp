#include "Harl.hpp"
#include <cstdlib>

int	main()
{
	Harl	harl;
    Harl	harl2;

    std::cout << "=== Testing INFO level ===" << std::endl;
    harl.complain("INFO");
    std::cout << "=== Testing DEBUG level ===" << std::endl;
    harl.complain("DEBUG");
    std::cout << "=== Testing WARNING level ===" << std::endl;
    harl.complain("WARNING");
    std::cout << "=== Testing ERROR level ===" << std::endl;
    harl.complain("ERROR");
    std::cout << "=== Testing invalid level ===" << std::endl;
    harl.complain("INVALID");
    // Test multiple complaints
    std::cout << "=== Testing multiple complaints ===" << std::endl;
    harl.complain("DEBUG");
    harl.complain("WARNING");
    harl.complain("ERROR");
    // Test with different Harl instances
    std::cout << "=== Testing different Harl instance ===" << std::endl;
    harl2.complain("INFO");
	return (EXIT_SUCCESS);
}
