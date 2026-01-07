#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
private:

	int					value;
	static const int	fractionalBits;

public:

	Fixed();

	~Fixed();

	Fixed(const Fixed& that);

	Fixed&	operator=(const Fixed& that);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
