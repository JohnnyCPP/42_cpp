#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
        std::string target;

public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& that);
        ~PresidentialPardonForm();

        PresidentialPardonForm& operator=(const PresidentialPardonForm& that);

        void execute(const Bureaucrat& executor) const;
};

#endif
