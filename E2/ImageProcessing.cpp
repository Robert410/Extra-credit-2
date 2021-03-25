#include "ImageProcessing.h"
#include <math.h>
void adjustment::process(Image& src, Image& dst) {
	/// <summary>
	/// Brightness and contrast adjustment
	/// </summary>
	/// <param name="src">our image</param>
	/// <param name="dst">the new image</param>
	for(unsigned int i=0;i<src.height();i++)
		for(unsigned int j=0;j<src.width();j++){
			unsigned int val= src.at(i, j);
			dst.setP(i, j, val * this->alpha + this->beta);
		}
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
			dst.setP(i, j, val);
	}
}