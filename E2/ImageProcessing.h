#pragma once
#include "Image.h"
#include <iostream>

class ImageProcessing{

public:
	virtual void process( Image& src, Image& dst);
};

class adjustment : public ImageProcessing{
private:
	int alpha, beta;
public:
	void process( Image& src, Image& dst) override;
};

class gamma : public ImageProcessing {
private:
	int tita = 1;
public:
	void process(Image& src, Image& dst) override;
};

