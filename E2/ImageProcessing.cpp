#include "ImageProcessing.h"
#include <math.h>

using namespace ns;

unsigned int clip(unsigned int n) {
	if (n < 0)
		return 0;
	if (n > 255)
		return 255;
	return n;
}

void ImageProcessing::process(Image& src, Image& dst) {
	for (unsigned int i = 0; i < src.height(); i++)
		for (unsigned int j = 0; j < src.width(); j++) {
			dst.setP(i, j, clip(dst.at(i,j)));
		}
	dst.setH(src.height());
	dst.setW(src.width());
	dst.setNr(src.getnumber());
	dst.setType(src.gettype());
}

void adjustment::process(Image& src, Image& dst) {
	/// <summary>
	/// Brightness and contrast adjustment
	/// </summary>
	/// <param name="src">our image</param>
	/// <param name="dst">the new image</param>
	for(unsigned int i=0;i<src.height();i++)
		for(unsigned int j=0;j<src.width();j++){
			unsigned int val= src.at(i, j);
			dst.setP(i, j, clip(val * this->alpha + this->beta));
		}
	dst.setH(src.height());
	dst.setW(src.width());
	dst.setNr(src.getnumber());
	dst.setType(src.gettype());
}

void gamma::process( Image& src, Image& dst) {
	/// <summary>
	/// Gamma correction.
	/// </summary>
	/// <param name="src">Our image</param>
	/// <param name="dst">The new image</param>
	for (unsigned int i = 0; i < src.height(); i++)
		for (unsigned int j = 0; j < src.width();j++) {
			unsigned int val = pow(src.at(i, j),this->tita);
			dst.setP(i, j, clip(val));
	}

	dst.setH(src.height());
	dst.setW(src.width());
	dst.setNr(src.getnumber());
	dst.setType(src.gettype());
}

/*
int movx[9] = { -1,-1,-1,0,0,0,1,1,1 };
int movy[9] = { -1,0,1,-1,0,1,-1,0,1 };

int convolution::csp(Image& src, int x, int y) {
	/// <summary>
	/// computing pixel
	/// </summary>
	/// <param name="src">my img</param>
	/// <param name="x">x coordinate</param>
	/// <param name="y">y coordinate</param>
	/// <returns>sum</returns>
	setkernelHorizontal();
	int sum = 0, i2 = 0, j2 = 0;
	for (int i = 0; i < 9; i++) {
		if (j2 == 3) {
			j2 = 0;
			i2++;
		}
		if(movx[i] >= 0 and movy[i] >= 0 and (x + movx[i]<src.height()) and (y + movy[i] < src.width()))
		sum += src.getP(x + movx[i], y + movy[i]) * kernel[i2][j2];
		j2++;
	}
	return sum;
}

void convolution::process(Image& src, Image& dst) {
	/// <summary>
	/// convolution convert
	/// </summary>
	/// <param name="src">my image</param>
	/// <param name="dst">new image</param>
	
	dst.zeros(src.width(), src.height());
	for (int i = 0; i < dst.height(); i++) {
		for (int j = 0; j < dst.width(); j++) {
			dst.setP(i, j, clip(csp(src, i, j)));
		}
	}
	dst.setH(src.height());
	dst.setW(src.width());
	dst.setNr(src.getnumber());
	dst.setType(src.gettype());
}
*/
adjustment::adjustment() {
	/*int a, b;
	std::cout << "Give the alpha: ";
	std::cin >> a;

	std::cout << "Give the beta: ";
	std::cin >> b;
	alpha = a;
	beta = b;
	std::cout << alpha;*/
	alpha = 1; beta = 0;
}

gamma::gamma() {
	tita = 1;
}

int movx[9] = { -1,-1,-1,0,0,0,1,1,1 };
int movy[9] = { -1,0,1,-1,0,1,-1,0,1 };

int convolution::csp(Image& src, int x, int y) {
	int sum = 0, i2 = 0, j2 = 0;
	for (int i = 0; i < 9; i++) {
		if (j2 == 3) {
			j2 = 0;
			i2++;
		}
		sum += src.getP(x + movx[i], y + movy[i]) * kernel[i2][j2];
		j2++;
	}
	return sum;
}

void convolution::transform() {
	int aux;
	for (int i = 0; i < 3; i++) {
		aux = kernel[0][i];
		kernel[0][i] = kernel[2][i];
		kernel[2][i] = aux;
	}
	for (int i = 0; i < 3; i++) {
		aux = kernel[i][0];
		kernel[i][0] = kernel[i][2];
		kernel[i][2] = aux;
	}
}

int convolution::identity_function(int x) {
	return x;
}

convolution::convolution() {
	kernel[1][1] = 1;
	clip = &identity_function;
}

convolution::convolution(int k[3][3], int (*po)(int)) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			kernel[i][j] = k[i][j];
	transform();
	clip = po;
}

void convolution::process(ns::Image& src, ns::Image& dst) {
	dst.zeros(src.width(), src.height());
	for (int i = 2; i < dst.height(); i++) {
		for (int j = 2; j < dst.width(); j++) {
			dst.setP(i, j, clip(csp(src, i, j)));
		}
	}
}