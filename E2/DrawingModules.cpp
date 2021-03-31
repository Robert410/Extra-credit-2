#include "DrawingModules.h"
#include <cmath>
using namespace ns;
float distance(Point P1, Point P2) {
	return sqrtf((P2.getX() - P1.getX()) * (P2.getX() - P1.getX()) + (P2.getY() - P1.getY()) * (P2.getY() - P1.getY()));
}

void drawLine(ns::Image& img, Point p1, Point p2, unsigned int color)
{
	for (int i = 0; i < img.height(); i++) {
		for (int j = 0; j < img.width(); j++) {
			int equation = j * p1.getY() + p1.getX() * p2.getY() + i * p2.getX() - p2.getX() * p1.getY() - j * p2.getY() - i * p1.getX();
			if ((-70 <= equation && equation <= 70) && ((p1.getX() <= j && j <= p2.getX() && p1.getY() <= i && i <= p2.getY()) || (p2.getX() <= j && j <= p1.getX() && p2.getY() <= i && i <= p1.getY())))
				img.setP(j, i, color);
		}
	}
}

void drawCircle(ns::Image& img, Point center, int radius, unsigned int color){
	for (int i = 0; i < img.height(); i++) {
		for (int j = 0; j < img.width(); j++) {
			Point P(j, i);
			float d = distance(center, P);//compute distance
			if (radius - 1 <= d && d <= radius + 1)//allow a little error -> if d is from the interval [radius-1,radius+1]
				img.setP(j, i, color);
		}
	}
}


void drawRectangle(ns::Image& img, Rectangle r, unsigned int color)
{
	unsigned int limitY = r.getY() + r.getH();
	unsigned int limitX = r.getX() + r.getW();

	unsigned int x = r.getX(), y = r.getY();

	while (x < limitX) {//top vertex
		img.setP(x, y, color);
		x++;
	}
	while (y < limitY) {//right vertex
		img.setP(x, y, color);
		y++;
	}
	while (x > r.getX()) {//bottom vertex
		img.setP(x, y, color);
		x--;
	}
	while (y > r.getY()) {//left vertex
		img.setP(x, y, color);
		y--;
	}
}

void drawRectangle(ns::Image& img, Point p1, Point p2, unsigned int color)
{
	/// <summary>
	/// Draw a rectangle between two given points
	/// </summary>
	/// <param name="img">my image</param>
	/// <param name="p1">first point</param>
	/// <param name="p2">second point</param>
	/// <param name="color">the color</param>
	Rectangle r(p1, p2);
	drawRectangle(img, r, color);
}


