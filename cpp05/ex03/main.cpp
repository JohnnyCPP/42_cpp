#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "=== Creating Intern and Bureaucrats ===" << std::endl;
	Intern someIntern;
	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 50);
	Bureaucrat nobody("Nobody", 140);
	
	std::cout << "\n=== Testing Intern Creating Valid Forms ===" << std::endl;

	std::cout << "\n--- Creating Shrubbery Form ---" << std::endl;
	AForm* shrub = someIntern.makeForm("shrubbery creation", "garden");
	if (shrub)
	{
			std::cout << *shrub << std::endl;
			nobody.signForm(*shrub);
			boss.executeForm(*shrub);
			delete shrub;
	}
	
	std::cout << "\n--- Creating Robotomy Form ---" << std::endl;
	AForm* robot = someIntern.makeForm("robotomy request", "Bender");
	if (robot)
	{
			std::cout << *robot << std::endl;
			manager.signForm(*robot);
			manager.executeForm(*robot);
			boss.executeForm(*robot);
			delete robot;
	}
	
	std::cout << "\n--- Creating Presidential Pardon Form ---" << std::endl;
	AForm* pardon = someIntern.makeForm("presidential pardon", "Arthur");
	if (pardon)
	{
			std::cout << *pardon << std::endl;
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
			delete pardon;
	}
	
	std::cout << "\n=== Testing Intern Creating Invalid Form ===" << std::endl;
	try
	{
			AForm* invalid = someIntern.makeForm("invalid form", "nowhere");
			if (invalid)
					delete invalid;
	}
	catch (const std::exception& e)
	{
			std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Testing Memory Management ===" << std::endl;
	AForm* forms[3];
	forms[0] = someIntern.makeForm("shrubbery creation", "yard");
	forms[1] = someIntern.makeForm("robotomy request", "Robot");
	forms[2] = someIntern.makeForm("presidential pardon", "Fry");
	for (int i = 0; i < 3; i++)
	{
			if (forms[i])
			{
					std::cout << "\nProcessing: " << *forms[i] << std::endl;
					boss.signForm(*forms[i]);
					boss.executeForm(*forms[i]);
					delete forms[i];
			}
	}
	
	std::cout << "\n=== Testing with Different Bureaucrat Grades ===" << std::endl;
	Intern anotherIntern;
	Bureaucrat lowLevel("LowLevel", 150);
	AForm* shrub2 = anotherIntern.makeForm("shrubbery creation", "test");
	if (shrub2)
	{
			std::cout << *shrub2 << std::endl;
			lowLevel.signForm(*shrub2);
			boss.signForm(*shrub2);
			lowLevel.executeForm(*shrub2);
			boss.executeForm(*shrub2);
			delete shrub2;
	}
	return (0);
}
