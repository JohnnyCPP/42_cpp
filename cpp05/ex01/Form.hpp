#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:

	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			execGrade;

public:

	Form();
	Form(const std::string& name, int signGrade, int execGrade);
	Form(const Form& that);
	~Form();

	Form&	operator=(const Form& that);

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	void		beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:

		virtual const char* what() const throw()
		{
			return "Form grade is too high (max 1)";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:

		virtual const char* what() const throw()
		{
			return "Form grade is too low (min 150)";
		}
	};
};

std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif
