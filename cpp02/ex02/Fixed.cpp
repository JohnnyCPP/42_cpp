#include "Fixed.hpp"

const int	::Fixed::fractionalBits = 8;

::Fixed::Fixed() :	value(0)
{
	std::cout	<< "Default constructor called"
				<< std::endl;
}

::Fixed::~Fixed()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

::Fixed::Fixed(const Fixed& that) :	value(that.value)
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
}

Fixed&	::Fixed::operator=(const Fixed& that)
{
	std::cout	<< "Copy assignment operator called"
				<< std::endl;
	if (this != &that)
	{
		this->value = that.getRawBits();
	}
	return (*this);
}

int		::Fixed::getRawBits(void) const
{
	std::cout	<< "getRawBits member function called"
				<< std::endl;
	return (this->value);
}

void	::Fixed::setRawBits(int const raw)
{
	std::cout	<< "setRawBits member function called"
				<< std::endl;
	this->value = raw;
}

::Fixed::Fixed(const int value)
{
	std::cout	<< "Int constructor called"
				<< std::endl;
	this->value = value << this->fractionalBits;
}

::Fixed::Fixed(const float value)
{
	std::cout	<< "Float constructor called"
				<< std::endl;
	this->value = ::roundf(value * (1 << this->fractionalBits));
}

float	::Fixed::toFloat(void) const
{
	float	value;

	value = static_cast<float>(this->value);
	return (value / (1 << this->fractionalBits));
}

int		::Fixed::toInt(void) const
{
	return (this->value >> this->fractionalBits);
}

bool	::Fixed::operator>(const Fixed& that) const
{
	return (this->value > that.value);
}

bool	::Fixed::operator<(const Fixed& that) const
{
	return (this->value < that.value);
}

bool	::Fixed::operator>=(const Fixed& that) const
{
	return (this->value >= that.value);
}

bool	::Fixed::operator<=(const Fixed& that) const
{
	return (this->value <= that.value);
}

bool	::Fixed::operator==(const Fixed& that) const
{
	return (this->value == that.value);
}

bool	::Fixed::operator!=(const Fixed& that) const
{
	return (this->value != that.value);
}

Fixed	Fixed::operator+(const Fixed& that) const
{
	Fixed	fixed;

	fixed.value = this->value + that.value;
	return (fixed);
}

Fixed	Fixed::operator-(const Fixed& that) const
{
	Fixed	fixed;

	fixed.value = this->value - that.value;
	return (fixed);
}

Fixed	Fixed::operator*(const Fixed& that) const
{
	Fixed		fixed;
	long long	aux;

	aux = (long long) this->value * (long long) that.value;
	fixed.value = aux / (1 << this->fractionalBits);
	return (fixed);
}

Fixed	Fixed::operator/(const Fixed& that) const
{
	Fixed		fixed;
	long long	aux;

	if (that.value == 0)
		fixed.value = 0;
	else
	{
		aux = (long long) this->value * (1 << this->fractionalBits);
		fixed.value = aux / that.value;
	}
	return (fixed);
}

// prefix
Fixed&	::Fixed::operator++()
{
	this->value += 1;
	return (*this);
}

Fixed&	::Fixed::operator--()
{
	this->value -= 1;
	return (*this);
}

// postfix
Fixed	Fixed::operator++(int)
{
	Fixed	aux(*this);

	this->value += 1;
	return (aux);
}

Fixed	Fixed::operator--(int)
{
	Fixed	aux(*this);

	this->value -= 1;
	return (aux);
}

Fixed&			::Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed&	::Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed&			::Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed&	::Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream&	operator<<(std::ostream& out, Fixed const& value)
{
	out << value.toFloat();
	return (out);
}
