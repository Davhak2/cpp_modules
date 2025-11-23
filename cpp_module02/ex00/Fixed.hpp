#pragma once

#include <iostream>

class Fixed {
	private:
		int value;
		const static int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
