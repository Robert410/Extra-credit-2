#include <iostream>
#include <iomanip>
#include "Image.h"
#include <fstream>

int main() {
	Image img;
	img.load("brain.pgm");
	std::cout << img;
	return 0;
}