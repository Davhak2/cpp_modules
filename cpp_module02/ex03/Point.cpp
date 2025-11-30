#include "Point.hpp"

Point::Point() : _x(Fixed()), _y(Fixed()) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {}

Point::~Point() {}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}
