#include "ImageProcessing.h"
#include <math.h>

void ImageProcessing::process(Image& src, Image& dst) {
	for (unsigned int i = 0; i < src.height(); i++)
		for (unsigned int j = 0; j < src.width(); j++) {
			dst.setP(i, j, dst.at(i,j));
		}
	dst.setH(src.height());
	dst.setW(src.width());
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
			dst.setP(i, j, val * this->alpha + this->beta);
		}
	dst.setH(src.height());
	dst.setW(src.width());
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

	dst.setH(src.height());
	dst.setW(src.width());
}

void convolution::setkernelIdentity() {
	kernel[0][0] = 0; kernel[0][1] = 0; kernel[0][2] = 0;
	kernel[1][0] = 0; kernel[1][1] = 1; kernel[1][2] = 0;
	kernel[2][0] = 0; kernel[2][1] = 0; kernel[2][2] = 0;
}

void convolution::process(Image& src, Image& dst) {
	int fs = 3;
	setkernelIdentity();
	for(int y = fs/2; y < src.height(); y++)
		for (int x = fs / 2; x < src.width(); x++) {
			float newpix;
			for (int dy = -fs / 2; dy <= fs / 2; dy++){
				for (int dx = -fs / 2; dx <= fs / 2; dx++){
					newpix = src.at(y + dy, x + dx) * kernel[dy + fs / 2][dx + fs / 2];
					dst.setP(y + dy, x + dx, newpix);
				}
			}
		}
	dst.setH(src.height());
	dst.setW(src.width());
}