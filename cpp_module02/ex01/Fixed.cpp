#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	value = num << bits;
}

Fixed::Fixed(const float fl)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(fl * (1 << bits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return value >> bits;
}

float Fixed::toFloat(void) const
{
	return (float)value / (float)(1 << bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fx)
{
	out << fx.toFloat();
	return out;
}
