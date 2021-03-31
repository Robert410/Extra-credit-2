#pragma once
#include "Image.h"
#include "Point.h"
#include "Rectangle.h"

#include "namespace.h"

void drawCircle(ns::Image& img, ns::Point center, int radius, unsigned int color);

void drawLine(ns::Image& img, ns::Point p1, ns::Point p2, unsigned int color);

void drawRectangle(ns::Image& img, ns::Rectangle r, unsigned int color);

void drawRectangle(ns::Image& img, ns::Point p1, ns::Point p2, unsigned int color);
