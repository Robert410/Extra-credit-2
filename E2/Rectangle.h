#pragma once
#include "Point.h"
#include "namespace.h"

class ns::Rectangle
{
public:
	Rectangle(int x, int y, int w, int h);
	Rectangle(Point P1, Point P2);
	Rectangle();
	int getX()const;
	int getY()const;
	int getW()const;
	int getH()const;
private:
	int x;
	int y;
	int w;
	int h;
};