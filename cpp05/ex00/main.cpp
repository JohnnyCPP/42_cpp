#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "Attempting to instantiate Jonas 69 and Bob 151..." << std::endl;
    try
    {
        Bureaucrat jonas("Jonas", 69);
		std::cout << jonas << std::endl;
        Bureaucrat bob("Bob", 151);
		std::cout << bob << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
	std::cout << "Attempting to instantiate Lola 1 and Lalo 0..." << std::endl;
    try
    {
        Bureaucrat lola("Lola", 1);
		std::cout << lola << std::endl;
        Bureaucrat lalo("Lalo", 0);
		std::cout << lalo << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }
	return (0);
}
