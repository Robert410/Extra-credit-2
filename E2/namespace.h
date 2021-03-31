#pragma once

namespace ns {
	class Image;
	class ImageProcessing;
	class Point;
	class Rectangle;
	class Size;

	void drawCircle(ns::Image& img, ns::Point center, int radius, unsigned int color);

	void drawLine(ns::Image& img, ns::Point p1, ns::Point p2, unsigned int color);

	void drawRectangle(ns::Image& img, ns::Rectangle r, unsigned int color);

	void drawRectangle(ns::Image& img, ns::Point p1, ns::Point p2, unsigned int color);

}
