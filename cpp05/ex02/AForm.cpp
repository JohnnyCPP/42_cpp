#include "AForm.hpp"

AForm::AForm() : name("unknown"), isSigned(false), signGrade(150), execGrade(150)
{}

AForm::AForm(const std::string& name, int signGrade, int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& that) : name(that.name), isSigned(that.isSigned), signGrade(that.signGrade), execGrade(that.execGrade)
{}

AForm::~AForm()
{}

AForm&	AForm::operator=(const AForm& that)
{
	if (this != &that)
		this->isSigned = that.isSigned;
	return (*this);
}

std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::getIsSigned() const
{
	return (isSigned);
}

int	AForm::getSignGrade() const
{
	return (signGrade);
}

int	AForm::getExecGrade() const
{
	return (execGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= signGrade)
		isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& stream, const AForm& form)
{
	stream << "Form: " << form.getName() 
		   << ", signed: " << (form.getIsSigned() ? "yes" : "no")
		   << ", sign grade required: " << form.getSignGrade()
		   << ", exec grade required: " << form.getExecGrade();
	return (stream);
}
