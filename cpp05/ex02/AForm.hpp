#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:

	const std::string	name;
	bool				isSigned;
	const int			signGrade;
	const int			execGrade;

public:

	AForm();
	AForm(const std::string& name, int signGrade, int execGrade);
	AForm(const AForm& that);
	virtual	~AForm();

	AForm&	operator=(const AForm& that);

	std::string		getName() const;
	bool			getIsSigned() const;
	int				getSignGrade() const;
	int				getExecGrade() const;

	void			beSigned(const Bureaucrat& bureaucrat);
	virtual void	execute(const Bureaucrat& executor) const = 0;

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

	class NotSignedException : public std::exception
	{
	public:

		virtual const char* what() const throw()
		{
			return "Form is not signed";
		}
	};
};

std::ostream& operator<<(std::ostream& stream, const AForm& form);

#endif
