#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), target("unknown")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& that) 
    : AForm(that), target(that.target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& that)
{
        if (this != &that)
        {
                AForm::operator=(that);
                this->target = that.target;
        }
        return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
        if (!getIsSigned())
                throw AForm::NotSignedException();
        if (executor.getGrade() > getExecGrade())
                throw AForm::GradeTooLowException();
        
        std::string filename = target + "_shrubbery";
        std::ofstream file(filename.c_str());
        
        if (!file.is_open())
        {
                std::cerr << "Error: Could not create file " << filename << std::endl;
                return;
        }
        
        file << "      /\\      " << std::endl;
        file << "     /\\/\\     " << std::endl;
        file << "    /\\/\\/\\    " << std::endl;
        file << "   /\\/\\/\\/\\   " << std::endl;
        file << "  /\\/\\/\\/\\/\\  " << std::endl;
        file << " /\\/\\/\\/\\/\\/\\ " << std::endl;
        file << "/\\/\\/\\/\\/\\/\\/\\" << std::endl;
        file << "      ||      " << std::endl;
        file << "      ||      " << std::endl;
        
        file.close();
        std::cout << "Created shrubbery at " << filename << std::endl;
}
