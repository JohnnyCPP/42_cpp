#include "Intern.hpp"

AForm* Intern::createShrubbery(const std::string& target)
{
        return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target)
{
        return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target)
{
        return new PresidentialPardonForm(target);
}

Intern::Intern()
{
}

Intern::Intern(const Intern& that)
{
        (void) that;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& that)
{
        (void) that;
        return (*this);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
        t_formType formTypes[] = {
                {"shrubbery creation", &Intern::createShrubbery},
                {"robotomy request", &Intern::createRobotomy},
                {"presidential pardon", &Intern::createPresidential}
        };
        
        for (size_t i = 0; i < sizeof(formTypes) / sizeof(formTypes[0]); i++)
        {
                if (formName == formTypes[i].name)
                {
                        std::cout << "Intern creates " << formName << std::endl;
                        return (formTypes[i].creator(target));
                }
        }
        
        std::cerr << "Error: Intern cannot create \"" << formName 
                  << "\" - form type not recognized" << std::endl;
        throw Intern::FormNotFoundException();
        return (NULL);
}
