#pragma once
#include "Image.h"
#include <iostream>

#define edge0 mat3(1, 0, -1, 0, 0, 0, -1, 0, 1)
#define edge1 mat3(0, 1, 0, 1, -4, 1, 0, 1, 0)
#define edge2 mat3(-1, -1, -1, -1, 8, -1, -1, -1, -1)
#define sharpen mat3(0, -1, 0, -1, 5, -1, 0, -1, 0)
#define box_blur mat3(1, 1, 1, 1, 1, 1, 1, 1, 1) * 0.1111
#define gaussian_blur mat3(1, 2, 1, 2, 4, 2, 1, 2, 1) * 0.0625
#define emboss mat3(-2, -1, 0, -1, 1, 1, 0, 1, 2)

class ImageProcessing{

public:
	virtual void process( Image& src, Image& dst);
};

class adjustment : public ImageProcessing{
private:
	int alpha=1, beta=0;
public:
	void process( Image& src, Image& dst) override;
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
};
