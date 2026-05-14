#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "=== Creating Bureaucrats ===" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 50);
	Bureaucrat intern("Intern", 150);
	Bureaucrat medium("Medium", 100);
	
	std::cout << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;
	std::cout << medium << std::endl;
	
	std::cout << "\n=== Creating Forms ===" << std::endl;
	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm pardon("Arthur");
	
	std::cout << shrub << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	
	std::cout << "\n=== Testing Execution Without Signing ===" << std::endl;
	std::cout << "\n--- Boss trying to execute unsigned shrub form ---" << std::endl;
	boss.executeForm(shrub);
	
	std::cout << "\n=== Signing Forms ===" << std::endl;
	std::cout << "\n--- Intern signing shrub form (req 145) ---" << std::endl;
	intern.signForm(shrub);
	
	std::cout << "\n--- Manager signing forms ---" << std::endl;
	manager.signForm(robotomy);
	manager.signForm(shrub);
	
	std::cout << "\n--- Boss signing pardon form (req 25) ---" << std::endl;
	boss.signForm(pardon);
	
	std::cout << "\n=== Testing Execution After Signing ===" << std::endl;
	std::cout << "\n--- Medium executing shrub form (exec 137, medium grade 100) ---" << std::endl;
	medium.executeForm(shrub);
	
	std::cout << "\n--- Boss executing shrub form ---" << std::endl;
	boss.executeForm(shrub);
	
	std::cout << "\n--- Intern executing robotomy form (exec 45, intern grade 150) ---" << std::endl;
	intern.executeForm(robotomy);
	
	std::cout << "\n--- Manager executing robotomy form (exec 45, manager grade 50) ---" << std::endl;
	manager.executeForm(robotomy);
	
	std::cout << "\n--- Boss executing robotomy form ---" << std::endl;
	boss.executeForm(robotomy);
	
	std::cout << "\n--- Medium executing pardon form (exec 5, medium grade 100) ---" << std::endl;
	medium.executeForm(pardon);
	
	std::cout << "\n--- Boss executing pardon form ---" << std::endl;
	boss.executeForm(pardon);
	return (0);
}
