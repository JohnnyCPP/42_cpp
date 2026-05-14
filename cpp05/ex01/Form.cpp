#include "Form.hpp"

Form::Form() : name("unknown"), isSigned(false), signGrade(150), execGrade(150)
{}

Form::Form(const std::string& name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& that) : name(that.name), isSigned(that.isSigned), signGrade(that.signGrade), execGrade(that.execGrade)
{}

Form::~Form()
{}

Form&	Form::operator=(const Form& that)
{
	if (this != &that)
		this->isSigned = that.isSigned;
	return (*this);
}

std::string	Form::getName() const
{
	return (name);
}

bool	Form::getIsSigned() const
{
	return (isSigned);
}

int	Form::getSignGrade() const
{
	return (signGrade);
}

int	Form::getExecGrade() const
{
	return (execGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& stream, const Form& form)
{
	stream << "Form: " << form.getName() 
		   << ", signed: " << (form.getIsSigned() ? "yes" : "no")
		   << ", sign grade required: " << form.getSignGrade()
		   << ", exec grade required: " << form.getExecGrade();
	return (stream);
}
