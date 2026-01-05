#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class	Harl
{
private:

	void	info(void);
	void	debug(void);
	void	warning(void);
	void	error(void);

	void	(Harl::*getFunctionPtr(std::string level))(void);

public:

	Harl();

	~Harl();

	Harl(const Harl& that);

	Harl&	operator=(const Harl& that);

	void	complain(std::string level);
};

#endif
