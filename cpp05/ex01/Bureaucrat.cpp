#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown"), grade(150) 
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) 
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat& that) : name(that.name), grade(that.grade)
{}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& that)
{
	if (this != &that)
		this->grade = that.grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int			Bureaucrat::getGrade() const
{
	return (grade);
}

void		Bureaucrat::incrementGrade(int amount)
{
	if ((grade - amount) < 1)
		throw Bureaucrat::GradeTooHighException();
	grade -= amount;
}

void		Bureaucrat::decrementGrade(int amount)
{
	if ((grade + amount) > 150)
		throw Bureaucrat::GradeTooLowException();
	grade += amount;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const Form::GradeTooLowException& exception)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
				  << " because their grade (" << this->getGrade()
				  << ") is too low (requires grade " << form.getSignGrade() << ")" 
				  << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream);
}
