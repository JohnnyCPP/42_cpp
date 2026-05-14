#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "=== Testing Form Creation with invalid grades ===" << std::endl;
	try
	{
		Form invalid("Invalid", 0, 100);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Form invalid2("Invalid2", 100, 151);
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Testing Form Creation with valid grades ===" << std::endl;
	Form taxForm("Tax Form", 50, 30);
	Form loanForm("Loan Form", 100, 80);
	std::cout << taxForm << std::endl;
	std::cout << loanForm << std::endl;

	std::cout << "\n=== Testing Bureaucrat Creation ===" << std::endl;
	Bureaucrat highLevel("Alice", 30);
	Bureaucrat lowLevel("Bob", 120);
	Bureaucrat mediumLevel("Charlie", 75);
	std::cout << highLevel << std::endl;
	std::cout << lowLevel << std::endl;
	std::cout << mediumLevel << std::endl;
	
	std::cout << "\n=== Testing Signing Forms ===" << std::endl;

	std::cout << "\n--- Alice (grade 30) signing Tax Form (req 50) ---" << std::endl;
	highLevel.signForm(taxForm);
	std::cout << taxForm << std::endl;
	
	std::cout << "\n--- Bob (grade 120) signing Tax Form (req 50) ---" << std::endl;
	lowLevel.signForm(taxForm);
	std::cout << taxForm << std::endl;
	
	std::cout << "\n--- Charlie (grade 75) signing Loan Form (req 100) ---" << std::endl;
	mediumLevel.signForm(loanForm);
	std::cout << loanForm << std::endl;
	
	std::cout << "\n--- Alice signing already signed Tax Form again ---" << std::endl;
	highLevel.signForm(taxForm);
	
	std::cout << "\n=== Testing edge cases ===" << std::endl;
	Form topSecret("Top Secret", 1, 1);
	Bureaucrat intern("Intern", 150);
	Bureaucrat boss("Boss", 1);
	std::cout << topSecret << std::endl;
	std::cout << intern << std::endl;
	std::cout << boss << std::endl;
	
	std::cout << "\n--- Intern trying to sign Top Secret form ---" << std::endl;
	intern.signForm(topSecret);
	
	std::cout << "\n--- Boss signing Top Secret form ---" << std::endl;
	boss.signForm(topSecret);
	std::cout << topSecret << std::endl;
	return (0);
}
