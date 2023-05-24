#include "../inc/Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const Point &obj): _x(obj._x), _y(obj._y) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point &Point::operator=(const Point &obj) {
	const_cast<Fixed &>(_x) = obj.getX();
	const_cast<Fixed &>(_y) = obj.getY();
	return *this;
}

Point::~Point() {}

const Fixed &Point::getX() const {
	return _x;
}

const Fixed &Point::getY() const {
	return _y;
}

