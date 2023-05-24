#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Point &obj);
		Point(const float x, const float y);
		Point &operator=(const Point &obj);
		~Point();

		const Fixed &getX() const;
		const Fixed &getY() const;
	private:
		const Fixed _x;
		const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
