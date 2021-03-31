#pragma once
#include "Image.h"
#include <iostream>

class ImageProcessing{

public:
	virtual void process( Image& src, Image& dst);
};

class adjustment : public ImageProcessing{
private:
	int alpha=1, beta=0;
public:
	adjustment();
	void process( Image& src, Image& dst) override;
	void setal(int nr) {
		alpha = nr;
	}
	void setbe(int nr) {
		beta = nr;
	}
};

class gamma : public ImageProcessing {
private:
	int tita = 1;
public:
	void process(Image& src, Image& dst) override;
};

class convolution : public ImageProcessing {
private:
	int kernel[4][4];

public:
	void process(Image& src, Image& dst) override;
	void setkernelIdentity();
	void setkernelBlur();
	void setkernelGaussian();
	void setkernelHorizontal();
	void setkernelVertical();
	int csp(Image& src, int x, int y);
};
