#include <iostream>
#include <iomanip>
#include <fstream>
#include "ImageProcessing.h"

int main() {
	Image img1, img2;
	img1.load("brain.pgm");
	gamma fct;
	//fct.process(img1, img2);
	//img2.save("matrix.out");
	convolution fct2;
	fct2.process(img1, img2);
	img2.save("matrix.out");
	return 0;
}