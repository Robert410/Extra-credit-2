#include "Image.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

Image::Image() {
	///
	/// Constructor init
	///
	/*int** arr = new int* [1000];
	for (int i = 0; i < 1000; i++)
		arr[i] = new int[1000];*/
	this->m_data = new unsigned int * [1000];
	for (int i = 0; i < 1000; i++)
		this->m_data[i] = new unsigned int[1000];
	this->m_height = 0;
	this->m_width = 0;
}

Image::Image(unsigned int w, unsigned int h) {
	/// <summary>
	/// Constractor with given size
	/// </summary>
	/// <param name="w">width</param>
	/// <param name="h">height</param>
	this->m_height = h;
	this->m_width = w;
	this->m_data = NULL;
}

Image::Image(const Image& other) {
	/// <summary>
	/// Copy a constructor Image
	/// </summary>
	/// <param name="other">The other image for the copy</param>
	this->m_height = other.m_height;
	this->m_width = other.m_width;
	this->m_data = other.m_data;
}

Image::~Image() {
	/// <summary>
	/// deconstructor
	/// </summary>
	delete[] this->m_data;
}

unsigned int Image::width() const{
	/// <summary>
	/// Get the width of the image
	/// </summary>
	/// <returns>width</returns>
	return this->m_width;
}

unsigned int Image::height() const {
	/// <summary>
	/// Get the height of the image
	/// </summary>
	/// <returns>height</returns>
	return this->m_height;
}

Size Image::size() const{
	/// <summary>
	/// Get the size of the image if Size format(class)
	/// </summary>
	/// <returns>size image of type Class Size</returns>
	Size sizeImg;
	sizeImg.seth(this->m_height);
	sizeImg.setw(this->m_width);
	return sizeImg;
}

bool Image::load(std::string imagePath) {
	/// <summary>
	/// Load a image in format pgm and read everithing is needed
	/// </summary>
	/// <param name="imagePath">The file we are looking for</param>
	/// <returns>a boolean if the files was open or not</returns>
	bool ok = 1;
	std::string line;
	std::ifstream fin(imagePath);
	getline(fin, line);
	if (line == "")ok = 0;
	std::cout << line;
	fin >> this->m_height >> this->m_width;
	std::cout << "\n" << this->m_height << " " << this->m_width;
	int pixels;
	fin >> pixels;
	std::cout << ' ' << pixels;
	/*int** arr = new int* [1000];
	for (int i = 0; i < 1000; i++)
		arr[i] = new int[1000];*/
	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			fin >> this->m_data[i][j];
	return ok;
}

bool Image::save(std::string imagePath) {
	/// <summary>
	/// The our image in an external file
	/// </summary>
	/// <param name="imagePath">The file where will be saved</param>
	/// <returns>a bool if the file was open</returns>
	bool ok = 1;
	std::ofstream fout(imagePath);
	for (int i = 0; i < this->m_height; i++, fout << "\n")
		for (int j = 0; j < this->m_width; j++) {
			fout << this->m_data[i][j];
			fout << std::setw(8);
		}
	return ok;
}

std::ostream& operator<<(std::ostream& os,Image& dt) {
	/// <summary>
	/// Allows to cout<< an imd
	/// </summary>
	/// <param name="os">param for output</param>
	/// <param name="dt">our image which we display</param>
	/// <returns>the output</returns>
	dt.save("matrix.out");
	return os;
}

void Image::operator=(const Image& other) {
	/// <summary>
	/// copy an image into another img
	/// </summary>
	/// <param name="other">the image we are copying</param>
	for (int i = 0; i < other.m_height; i++)
		for (int j = 0; j < other.m_width; j++)
			this->m_data[i][j] = other.m_data[i][j];
}

void Image::operator+(const Image& i) {
	/// <summary>
	/// addition of two images
	/// </summary>
	/// <param name="i">the second img</param>
	for (int k = 0; k < i.m_height; k++)
		for (int j = 0; j < i.m_width; j++)
			this->m_data[k][j] += i.m_data[k][j];
}

void Image::operator-(const Image& i) {
	/// <summary>
	/// substract from an image other image
	/// </summary>
	/// <param name="i">the second image</param>
	for (int k = 0; k < i.m_height; k++)
		for (int j = 0; j < i.m_width; j++)
			this->m_data[k][j] -= i.m_data[k][j];
}

void Image::setP(unsigned int x, unsigned int y, unsigned int val) {
	/// <summary>
	/// set a valua at a given pixel
	/// </summary>
	/// <param name="x">x coordinate</param>
	/// <param name="y">y coordinate</param>
	/// <param name="val">value</param>
	this->m_data[x][y] = val;
}

static Image zeros(unsigned int width, unsigned int height) {
	/// <summary>
	/// fill an image with 0
	/// </summary>
	/// <param name="width">width of the image</param>
	/// <param name="height">height of the img</param>
	/// <returns>the img after</returns>
	Image img;
	for (int k = 0; k < height; k++)
		for (int j = 0; j < width; j++)
			img.setP(k, j, 0);
	return img;
}

static Image ones(unsigned int width, unsigned int height) {
	/// <summary>
	/// fill an image with 1
	/// </summary>
	/// <param name="width">width of the image</param>
	/// <param name="height">height of the img</param>
	/// <returns>the img after</returns>
	Image img;
	for (int k = 0; k < height; k++)
		for (int j = 0; j < width; j++)
			img.setP(k, j, 1);
	return img;
}

bool Image::isEmpty() const {
	/// <summary>
	/// Verify if a image is empty or not
	/// </summary>
	/// <returns>a boolean</returns>
	if (this->m_height == 0 or this->m_width == 0)
		return 0;
	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			if (this->m_data[i][j] == NULL)
				return 0;
	return 1;
}


unsigned int& Image::at(Point pt){
	/// <summary>
	/// Get a pixel at a given point
	/// </summary>
	/// <param name="pt">our point</param>
	/// <returns>the pixel</returns>
	return this -> m_data[pt.getX()][pt.getY()];
}

unsigned int& Image::at(unsigned int x, unsigned int y) {
	/// <summary>
	/// Get a pixel at a given point
	/// </summary>
	/// <param name="x">x coordinate</param>
	/// <param name="y">y coordinate</param>
	/// <returns>the pixel</returns>
	return this->m_data[x][y];
}

unsigned int* Image::row(int y) {
	/// <summary>
	/// Get a row of pixels of the image
	/// </summary>
	/// <param name="y">the row</param>
	/// <returns>That specific row in an array</returns>
	unsigned int *arr = new unsigned int[1000];
	for (int i = 0; i < this->m_width; i++)
		arr[i] = this->m_data[y][i];
	return arr;
}

void Image::release() {
	/// <summary>
	/// Release the space of the memory of the image
	/// </summary>
	delete[] this->m_data;
}