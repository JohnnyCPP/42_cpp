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
