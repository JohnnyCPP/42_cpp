#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), target("unknown")
{
        std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
        std::srand(std::time(0));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& that) 
    : AForm(that), target(that.target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& that)
{
        if (this != &that)
        {
                AForm::operator=(that);
                this->target = that.target;
        }
        return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
        if (!getIsSigned())
                throw AForm::NotSignedException();
        if (executor.getGrade() > getExecGrade())
                throw AForm::GradeTooLowException();
        
        std::cout << "* DRILLING NOISES * ";
        std::cout << "Brrrrrrrrrrrrrrrrr... ";
        std::cout << "Zzzzzzzzzzzzzzzzz... ";
        std::cout << "Grrrrrrrrrrrrrrrr... " << std::endl;
        
        int success = std::rand() % 2;
        if (success)
                std::cout << target << " has been robotomized successfully!" << std::endl;
        else
                std::cout << "Robotomy failed on " << target << "!" << std::endl;
}
