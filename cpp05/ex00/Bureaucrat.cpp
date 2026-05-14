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

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream);
}
