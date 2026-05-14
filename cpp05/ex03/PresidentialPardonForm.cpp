#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5), target("unknown")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& that) 
    : AForm(that), target(that.target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& that)
{
        if (this != &that)
        {
                AForm::operator=(that);
                this->target = that.target;
        }
        return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
        if (!getIsSigned())
                throw AForm::NotSignedException();
        if (executor.getGrade() > getExecGrade())
                throw AForm::GradeTooLowException();
        
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
