#include <iostream>
#include <iomanip>
#include <fstream>
#include "ImageProcessing.h"
#include "DrawingModules.h"
#include "Tests.h"
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace ns;


int kernel[3][3];

void setkernelIdentity() {
	/// <summary>
	/// converring kernel
	/// </summary>
	kernel[0][0] = 0; kernel[0][1] = 0; kernel[0][2] = 0;
	kernel[1][0] = 0; kernel[1][1] = 1; kernel[1][2] = 0;
	kernel[2][0] = 0; kernel[2][1] = 0; kernel[2][2] = 0;
}

void setkernelBlur() {
	/// <summary>
	/// converring kernel
	/// </summary>
	kernel[0][0] = 1; kernel[0][1] = 1; kernel[0][2] = 1;
	kernel[1][0] = 1; kernel[1][1] = 1; kernel[1][2] = 1;
	kernel[2][0] = 1; kernel[2][1] = 1; kernel[2][2] = 1;
}

void setkernelGaussian() {
	/// <summary>
	/// converring kernel
	/// </summary>
	kernel[0][0] = 1; kernel[0][1] = 2; kernel[0][2] = 1;
	kernel[1][0] = 2; kernel[1][1] = 4; kernel[1][2] = 2;
	kernel[2][0] = 1; kernel[2][1] = 2; kernel[2][2] = 1;
}

void setkernelHoFrizontal() {
	/// <summary>
	/// converring kernel
	/// </summary>
	kernel[0][0] = 1; kernel[0][1] = 2; kernel[0][2] = 1;
	kernel[1][0] = 0; kernel[1][1] = 0; kernel[1][2] = 0;
	kernel[2][0] = -1; kernel[2][1] = -2; kernel[2][2] = -1;
}

int sobel(int x) {
	return ((x / 4 + 255) / 2);
}


convolution fct3(kernel, sobel);

void setkernelVertical() {
	/// <summary>
	/// converring kernel
	/// </summary>
	kernel[0][0] = -1; kernel[0][1] = 0; kernel[0][2] = 1;
	kernel[1][0] = -2; kernel[1][1] = 0; kernel[1][2] = 2;
	kernel[2][0] = -1; kernel[2][1] = 0; kernel[2][2] = 1;
}


void testInput() {
	/// <summary>
	/// Creating an UI
	/// </summary>
	std::cout << "Input testing\n";
	Image x, dst;
	std::string imgg1 = "brain.pgm";
	std::string imgg2 = "dragon.ascii.pgm";
	std::string imgg3 = "venus2.ascii.pgm";
	std::cout << "\n"
		<< " 1 - Image 1.\n"
		<< " 2 - Image 2.\n"
		<< " 3 - Image 3.\n"
		<< " Enter: ";
	int k;
	std::cin >> k;
	if (k == 1)x.load(imgg1);
	else if (k == 2)x.load(imgg2);
	else if (k == 3)x.load(imgg3);
	std::cout << "\n\nImage loaded! lets begin!\n";
	int choice;
	dst = x;
	do {
		std::cout << "\n"
			<< " 1 - Brightness and contrast adjustment.\n"
			<< " 2 - Gamma correction.\n"
			<< " 3 - Image convolution.\n"
			<< " 4 - Drawing <3\n"
			<< " 5 - Exit.\n"
			<< " Enter: ";
		std::cin >> choice;
		if (choice == 1) {
			int alpha, beta;
			std::cout << " >>> Give the alpha: ";
			std::cin >> alpha;
			std::cout << " >>> Give the beta: ";
			std::cin >> beta;
			adjustment fct;
			fct.setal(alpha);
			fct.setbe(beta);
			fct.process(x, dst);
			x = dst;
			std::cout << "\n >>> IMAGE CHANGED!\n";
		}
		else if (choice == 2) {
			int tita;
			std::cout << " >>> Give the tita: ";
			std::cin >> tita;
			gamma fct2;
			fct2.setT(tita);
			fct2.process(x, dst);
			x = dst;
			std::cout << "\n >>> IMAGE CHANGED!\n";
		}
		else if (choice == 3) {
			int k;
			std::cout << "\n"
				<< " >>> 1 - Identity kernel.\n"
				<< " >>> 2 - Mean blur kernel.\n"
				<< " >>> 3 - 3x3 Gaussian blur kernel.\n"
				<< " >>> 4 - Horizontal Sobel kernel\n"
				<< " >>> 5 - Vertical Sobel kernel.\n"
				<< "     >>> Enter: ";
			std::cin >> k;
			if (k == 1)setkernelIdentity();
			else if (k == 2)setkernelBlur();
			else if (k == 3)setkernelGaussian();
			else if (k == 4)setkernelHoFrizontal();
			else if (k == 5)setkernelVertical();
			convolution fct3(kernel, sobel);
			fct3.process(x, dst);
			x = dst;
			std::cout << "\n >>> IMAGE CHANGED!\n";
		}
		else if (choice == 5) {
			std::cout << "Exit...\n";
		}
		else if (choice == 4) {
			int k;
			std::cout << "\n"
				<< " >>> 1 - Draw a line.\n"
				<< " >>> 2 - Draw a circle.\n"
				<< " >>> 3 - Draw a rectangle.\n"
				<< "     >>> Enter: ";
			std::cin >> k;
			if (k == 1) {
				Point p1, p2; int a;
				std::cout << " >>> X of the first point: ";
				std::cin >> a; p1.setX(a);
				std::cout << " >>> Y of the first point: ";
				std::cin >> a; p1.setY(a);
				std::cout << " >>> X of the second point: ";
				std::cin >> a; p2.setX(a);
				std::cout << " >>> Y of the second point: ";
				std::cin >> a; p2.setY(a);
				drawLine(dst, p1, p2, 0);
			}
			else if (k == 2) {
				Point center; int radius, a;
				std::cout << " >>> X of the center point: ";
				std::cin >> a; center.setX(a);
				std::cout << " >>> Y of the center point: ";
				std::cin >> a; center.setY(a);
				std::cout << " >>> The radius of the circle: ";
				std::cin >> radius;
				drawCircle(dst, center, radius, 0);
			}
			else if (k == 3) {
				int x, y, h, w;
				std::cout << " >>> X of the left up point: ";
				std::cin >> x;
				std::cout << " >>> Y of the left up point: ";
				std::cin >> y;
				std::cout << " >>> Height of the rectangle: ";
				std::cin >> h;
				std::cout << " >>> Width of the rectangle: ";
				std::cin >> w;
				Rectangle r(x, y, h, w);
				drawRectangle(dst, r, 0);
			}
		}
		else
			std::cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";


	} while (choice != 5);
	dst.save("D:\\school\\oop\\4\\Lab 4\\E2\\E2\\matrix.asci.pgm");
}

int main() {
	setkernelBlur();
	setkernelGaussian();
	setkernelIdentity();
	setkernelVertical();
	setkernelHoFrizontal();
	//Image img1, img2;
	//img1.load("brain.pgm");
	//gamma fct;
	//fct.process(img1, img2);
	//img2.save("matrix.out");
	//convolution fct2;
	//fct2.process(img1, img2);
	//Image x(9999, 9999);
	//Rectangle r(160, 120, 320, 240);
	//Point center(300, 221), P2(460, 340), P1(260, 340);

	//Adjustment adj;
	//adj.setBrightness(-100);
	//adj.setContrast(1);
	//adj.process(x, x);

	//Gamma gm;
	//gm.setTita(0.5);
	//gm.process(x,x);

	//drawCircle(x, center, 100, 0);
	//DrawingModules dw;
	//dw.drawCircle(img1, center, 100, 0);
	
	//dw.drawLine(img1, P1, P2, 0);
	//img1.save("matrix.out");


	testInput();

	testALL();
	_CrtDumpMemoryLeaks();
	return 0;
}