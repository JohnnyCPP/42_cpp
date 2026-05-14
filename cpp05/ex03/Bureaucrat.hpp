#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:

	const std::string	name;

	int					grade;

public:

	Bureaucrat();

	Bureaucrat(const std::string& name, int grade);

	~Bureaucrat();

	Bureaucrat(const Bureaucrat& that);

	Bureaucrat&	operator=(const Bureaucrat& that);

	std::string	getName() const;

	int			getGrade() const;

	void		incrementGrade(int amount);

	void		decrementGrade(int amount);

	void		signForm(AForm &form) const;

	void		executeForm(const AForm& form) const;

	class GradeTooHighException : public std::exception
	{
	public:

		virtual const char*	what() const throw()
		{
			return "Bureaucrat grade is too high (max 1)";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:

		virtual const char*	what() const throw()
		{
			return "Bureaucrat grade is too low (min 150)";
		}
	};
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif
