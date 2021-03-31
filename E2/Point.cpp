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