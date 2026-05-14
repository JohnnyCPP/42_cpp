#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:

        typedef struct s_formType
        {
                std::string name;
                AForm* (*creator)(const std::string& target);
        } t_formType;
        
        static AForm* createShrubbery(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
        static AForm* createPresidential(const std::string& target);
        
public:

        Intern();
        Intern(const Intern& that);
        ~Intern();
        
        Intern& operator=(const Intern& that);
        
        AForm* makeForm(const std::string& formName, const std::string& target) const;
        
        class FormNotFoundException : public std::exception
        {
        public:
                virtual const char* what() const throw()
                {
                        return "Form not found";
                }
        };
};

#endif
