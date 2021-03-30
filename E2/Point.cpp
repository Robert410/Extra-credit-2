#include "Point.h"

Point::Point() {
	/// <summary>
	/// Construct
	/// </summary>
	x = 0; y = 0;
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