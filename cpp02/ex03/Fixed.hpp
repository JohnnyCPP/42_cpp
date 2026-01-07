#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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

	Fixed(const int value);

	Fixed(const float value);

	float	toFloat(void) const;

	int		toInt(void) const;

	bool	operator>(const Fixed& that) const;

	bool	operator<(const Fixed& that) const;
	
	bool	operator>=(const Fixed& that) const;

	bool	operator<=(const Fixed& that) const;

	bool	operator==(const Fixed& that) const;

	bool	operator!=(const Fixed& that) const;

	Fixed	operator+(const Fixed& that) const;

	Fixed	operator-(const Fixed& that) const;

	Fixed	operator*(const Fixed& that) const;

	Fixed	operator/(const Fixed& that) const;

	// prefix
	Fixed&	operator++();
	Fixed&	operator--();
	// postfix
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed&		min(Fixed& a, Fixed& b);

	static const Fixed&	min(const Fixed& a, const Fixed& b);

	static Fixed&		max(Fixed& a, Fixed& b);

	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& out, Fixed const& value);

#endif
