#pragma once
#include "Image.h"
#include <iostream>
#include "namespace.h"

class ns::ImageProcessing{

public:
	virtual void process(ns::Image& src, ns::Image& dst);
};

class adjustment : public ns::ImageProcessing{
private:
	int alpha=1, beta=0;
public:
	adjustment();
	void process(ns::Image& src, ns::Image& dst) override;
	void setal(int nr) {
		alpha = nr;
	}
	void setbe(int nr) {
		beta = nr;
	}
};

class gamma : public ns::ImageProcessing {
private:
	int tita = 1;
public:
	void process(ns::Image& src, ns::Image& dst) override;
	void setT(int nr) {
		tita = nr;
	}
};

class convolution : public ns::ImageProcessing {
private:
	int kernel[4][4];

public:
	void process(ns::Image& src, ns::Image& dst) override;
	void setkernelIdentity();
	void setkernelBlur();
	void setkernelGaussian();
	void setkernelHorizontal();
	void setkernelVertical();
	int csp(ns::Image& src, int x, int y);
};
