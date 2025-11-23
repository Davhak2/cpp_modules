#pragma once

#include <iostream>
#include <cmath>

class Fixed {
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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fx);

