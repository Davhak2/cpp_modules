#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	const static int bits = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float fl);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fx);
