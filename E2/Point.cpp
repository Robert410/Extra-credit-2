#include <iostream>
#include "Point.h"

using namespace ns;
Point::Point() {
	/// <summary>
	/// Construct
	/// </summary>
	x = 0; y = 0;
}

Point::Point(int x, int y) {
	this->x = x; this->y = y;
}

unsigned int Point::getX() const {
	/// <summary>
	/// Get yhe X coordinate of the point
	/// </summary>
	return this->x;
}

unsigned int Point::getY() const {
	/// <summary>
	/// Get yhe Y coordinate of the point
	/// </summary>
	return this->y;
}

std::ostream& operator<<(std::ostream& os, const Point& P)
{
	os << "(" << P.getX() << "," << P.getY() << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point& P)
{
	unsigned int x, y;
	is >> x >> y;
	P.setX(x);
	P.setY(y);
	return is;
}