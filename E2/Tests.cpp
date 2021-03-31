#include "Tests.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ImageProcessing.h"
#include "DrawingModules.h"
#include <cassert>

void testPoint() {
	std::cout << "Point tests.\n";
	Point a(2, 3), a1;
	assert(a.getX() == 2);
	assert(a.getY() == 3);
	Point b(0, 0);
	assert(b.getX() == 0);
	assert(b.getY() == 0);
}

void testRectangle() {
	std::cout << "Rectangle tests.\n";
	Rectangle r(1, 2, 3, 4), v;
	assert(r.getX() == 1);
	assert(r.getY() == 2);
	assert(r.getW() == 3);
	assert(r.getH() == 4);

	Rectangle r0(0, 0, 0, 0);
	assert(r0.getX() == 0);
	assert(r0.getY() == 0);
	assert(r0.getW() == 0);
	assert(r0.getH() == 0);
}

void testImg() {
	std::cout << "Image tests.\n";
	Image img;
	Image img1(800, 700), img2;
	img.zeros(800, 700);

	assert(img.width() == 800);
	assert(img.height() == 700);

	Size sz;
	sz = img.size();
	assert(sz.geth() == 700);
	assert(sz.getw() == 800);

	assert(img2.load("brain.pgm")==1);
	assert(img2.height() == 720);
	assert(img2.width() == 486);

	Image cop, sum;
	cop = img2;
	assert(cop.width() == 486);

	cop + img2;
	cop - img2;

	assert(cop.isEmpty() == 0);
	assert(cop.at(1, 1) == 60);

	Point b(2, 2);
	assert(cop.at(b) == 60);
	unsigned int* arr = new unsigned int[1000];
	arr = img2.row(4);
	assert(arr[0] == 60);

	adjustment fct;
	Image dst;
	fct.process(img2, dst);
	assert(dst.save("matrix.pgm") == 1);
}

void testALL() {
	testPoint();
	testRectangle();
	testImg();
}