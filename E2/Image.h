#pragma once
#include <string>
#include "ImageProcessing.h"
#include "ImgSize.h"
#include "Point.h"
#include "Rectangle.h"
#include "namespace.h"

class ns::Image{

private:
	unsigned int** m_data;
	unsigned int m_width;
	unsigned int m_height;
	char type;
	int number;
public:
	//cONSTRUCTOR
	Image(); //1
	Image(unsigned int w, unsigned int h); //1
	Image(const Image& other) = delete; 
	~Image(); //1

	friend class ImageProcessing;

	//getters for the height and width of the image
	Size size() const; //1
	unsigned int width() const; //1
	unsigned int height() const; //1

	//two methods that load and save an image from/to a .pgm filex
	
	//P2 720 486 255
	bool load(std::string imagePath); //1


	bool save(std::string imagePath); //1

	//overload
	friend std::ostream& operator<<(std::ostream& os, Image& dt); //1
	void operator=(const Image& other); //1
	void operator+(const Image& i); //1
	void operator-(const Image& i); //1
	void operator*(const Image& i); 
	
	//image empty or not
	bool isEmpty() const; //1

	//pixel at a given point
	unsigned int at(Point pt); //1
	unsigned int at(unsigned int x, unsigned int y); //1

	//s a pointer to a row in the image
	unsigned int* row(int y);  //1

	//releases the memory allocated for the image
	void release();//1

	//a portion of the image to filter or apply some operation on
	bool getROI(Image& roiImg, Rectangle roiRect);
	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	
	//special image filled with 0/1
	void zeros(unsigned int width, unsigned int height); //1
	void ones(unsigned int width, unsigned int height); //1
	void whitefill(unsigned int width, unsigned int height);
	//setpixel
	void setP(unsigned int x, unsigned int y, unsigned int val);
	
	void setH(unsigned int H) {
		this->m_height = H;
	}

	void setW(unsigned int H) {
		this->m_width = H;
	}

	unsigned int getP(int x, int y) {
		return m_data[x][y];
	}

	void setType(char n) {
		type = n;
	}
	void setNr(int nr) {
		number = nr;
	}
	char gettype() {
		return type;
	}
	int getnumber() {
		return number;
	}
};