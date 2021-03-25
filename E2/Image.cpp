#include "Image.h"
#include <string>
#include <iostream>
#include <fstream>

Image::Image() {
	///
	/// Constructor init
	///
	/*int** arr = new int* [1000];
	for (int i = 0; i < 1000; i++)
		arr[i] = new int[1000];*/
	this->m_data = new int* [1000];
	for (int i = 0; i < 1000; i++)
		this->m_data[i] = new int[1000];
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
		for (int j = 0; j < this->m_width; j++)
			fout << this->m_data[i][j] << " ";
	return ok;
}

