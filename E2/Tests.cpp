#include "Tests.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ImageProcessing.h"
#include "DrawingModules.h"
#include <cassert>

using namespace ns;

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
	assert(img2.width() == 720);
	assert(img2.height() == 486);

	Image cop, sum;
	cop = img2;
	assert(cop.height() == 486);

	cop + img2;
	cop - img2;

	assert(cop.isEmpty() == 0);
	assert(cop.at(1, 1) == 60);

	Point b(2, 2);
	assert(cop.at(b) == 60);
	unsigned int* arr = img2.row(2);

	Image dst;

	Image Roi;
	cop.getROI(Roi, 50, 50, 100, 300);
	assert(Roi.isEmpty() == 0);

	Image Roi2;
	Rectangle r(1, 2, 200, 200);
	Point P1(50, 150), P2(80, 120);
	cop.getROI(Roi2, r);
	assert(Roi2.isEmpty() == 0);

	Image ones;
	assert(ones.isEmpty() == 1);
	ones.ones(cop.height(), cop.width());
	assert(ones.isEmpty() == 0);

	ones.setP(5, 5, 5);
	assert(ones.getP(5, 5) == 5);
	ones.setH(500);
	assert(ones.height() == 500);
	ones.setW(400);
	assert(ones.width() == 400);
	ones.setType('C');
	assert(ones.gettype() == 'C');
	ones.setNr(4);
	assert(ones.getnumber() == 4);

	ImageProcessing image;
	Image dest;
	image.process(cop, dest);

	adjustment fct;
	Image dst1;
	fct.setal(1);
	fct.setbe(0);
	fct.process(img2, dst1);

	gamma fct2;
	Image dst2;
	fct2.setT(1);
	fct2.process(img2, dst2);

	convolution fct3;
	Image dst3;
	fct3.process(img2, dst3);

	assert(dst.save("matrix.pgm") == 1);
	
	
	drawLine(img2, P1, P2, 0);
	drawCircle(img2, P1, 50, 0);
	Point  p2(300, 250);
	Image one;
	one.whitefill(633, 621);
	//drawCircle(one, P1, 10, 0);
	//draw.drawLine(one, P1, P2, 0);
	//drawLine(one, P1, P2, 0);

	drawRectangle(one, r, 0);
	delete[] arr;
}

void testdraw() {
	std::cout << "Drawing tests\n";
	Image x;
	Rectangle r(100, 100, 100, 130);
	Point P1(200, 321), P2(460, 340), center(200, 200);
	x.load("brain.pgm");
	//x.getROI(x, 160, 120, 320, 240);
	//x.getROI(x,r);

	//Adjustment adj;
	//adj.setBrightness(-100);
	//adj.setContrast(1);
	//adj.process(x, x);

	//Gamma gm;
	//gm.setTita(0.5);
	//gm.process(x,x);

	drawCircle(x, center, 100, 0);
	
	drawLine(x, P1, P2, 0);
	
	drawRectangle(x, P1, P2, 0);
	//setkernelHoFrizontal();
	//convolution fct(kernel,sobel);
	Image dst;
	//fct.process(x, dst);
	drawRectangle(x, r, 0);
	//dst.save("D:\\school\\oop\\4\\Lab 4\\E2\\E2\\matrix.asci.pgm");
	
}

void testALL() {
	testPoint();
	testRectangle();
	testImg();
	testdraw();
}