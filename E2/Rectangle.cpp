#include "Rectangle.h"

Rectangle::Rectangle() {
	/// <summary>
	/// constructor
	/// </summary>
	x = 0; y = 0; w = 0; h = 0;
}

Rectangle::Rectangle(int xPos, int yPos, int width, int height) {
	this->x = xPos;
	this->y = yPos;
	this->w = width;
	this->h = height;
}


int Rectangle::getX()const {
	/// <summary>
	/// get the x coordinate
	/// </summary>
	return this->x;
}



int Rectangle::getY()const {
	/// <summary>
	/// get the y coordinate
	/// </summary>
	return this->y;
}

int Rectangle::getH()const {
	/// <summary>
	/// get the height coordinate
	/// </summary>

	return this->h;
}

int Rectangle::getW()const {
	/// <summary>
	/// get the width coordinate
	/// </summary>
	return this->w;
}