#pragma once
class Rectangle
{
public:
	Rectangle(int x, int y, int w, int h);
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