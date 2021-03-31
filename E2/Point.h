#pragma once
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
};

