#include <iostream>
#include <iomanip>
#include "Image.h"
#include <fstream>

int main() {
	Image img;
	img.load("brain.pgm");
	img.save("matrix.out");
	return 0;
}