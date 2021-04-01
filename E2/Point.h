#pragma once
#include <iostream>
#include "namespace.h"

class ns::Point
{
private:
	unsigned int x;
	unsigned int y;
public:
	Point();
	Point(int x, int y);
	unsigned int getX() const;
	unsigned int getY() const;
	void setX(unsigned int s) {
		x = s;
	}
	void setY(unsigned int s) {
		y = s;
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& P);
	friend std::istream& operator>>(std::istream& os, Point& P);
};

