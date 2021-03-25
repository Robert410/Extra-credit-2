#pragma once
#include <string>
#include "ImgSize.h"
#include "Point.h"
#include "Rectangle.h"

class Image{

private:
	unsigned int** m_data;
	unsigned int m_width;
	unsigned int m_height;

public:
	//cONSTRUCTOR
	Image(); //1
	Image(unsigned int w, unsigned int h); //1
	Image(const Image& other); //1
	~Image(); //1

	
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
	static Image zeros(unsigned int width, unsigned int height); //1
	static Image ones(unsigned int width, unsigned int height); //1

	//setpixel
	void setP(unsigned int x, unsigned int y, unsigned int val);
};