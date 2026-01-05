#include "Harl.hpp"

void	::Harl::info(void)
{
	std::cout	<< "[ INFO ] "
				<< std::endl;
	std::cout	<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void	::Harl::debug(void)
{
	std::cout	<< "[ DEBUG ] "
				<< std::endl;
	std::cout	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
				<< std::endl;
}

void	::Harl::warning(void)
{
	std::cout	<< "[ WARNING ] "
				<< std::endl;
	std::cout	<< "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
				<< std::endl;
}

void	::Harl::error(void)
{
	std::cout	<< "[ ERROR ] "
				<< std::endl;
	std::cout	<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl;
}

::Harl::Harl()
{}

::Harl::~Harl()
{}

::Harl::Harl(const Harl& that)
{
	(void) that;
}

Harl&	::Harl::operator=(const Harl& that)
{
	(void) that;
	return (*this);
}

void	(Harl::*Harl::getFunctionPtr(std::string level))(void)
{
	std::string	levels[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};
	void		(Harl::*functions[4])(void) = 
	{
		&Harl::info,
		&Harl::debug,
		&Harl::warning,
		&Harl::error
	};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			return (functions[i]);
		i ++;
	}
	return (NULL);
}

void	::Harl::complain(std::string level)
{
	void	(Harl::*function)(void) = getFunctionPtr(level);

	if (function != NULL)
	{
		(this->*function)();
		return ;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
