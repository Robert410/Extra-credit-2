#pragma once

#include "namespace.h"


class ns::Size
{
private:
	unsigned int m_width;
	unsigned int m_height;
public:
	void setw(unsigned int w);
	void seth(unsigned int h);
	unsigned int getw() {
		return m_width;
	}
	unsigned int geth() {
		return m_height;
	}
};

