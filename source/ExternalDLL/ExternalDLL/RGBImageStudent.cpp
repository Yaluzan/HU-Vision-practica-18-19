#include "RGBImageStudent.h"
#include <iostream>

RGBImageStudent::RGBImageStudent() : RGBImage() {
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight())
, newRGB(new RGB[other.getWidth()* other.getHeight()]) {
	for (int i = 0; i < other.getWidth() * other.getHeight(); i++) {
		newRGB[i] = other.newRGB[i];
	}
	std::cout << other.getHeight() << "   " << other.getWidth() << "fuck";
	//TODO: Create a copy from the other object - should be done
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height),
newRGB(new RGB[width * height]){

	//TODO: Initialize pixel storage - should be done
}

RGBImageStudent::~RGBImageStudent() {
	delete[] newRGB;
	//TODO: delete allocated objects - should be done
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] newRGB;
	this->newRGB = new RGB[width * height];
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage) - should be done
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[] newRGB;
	this->newRGB = new RGB[other.getWidth() * other.getHeight()];
	for (int i = 0; i < other.getWidth() * other.getHeight(); i++) {
		newRGB[i] = other.newRGB[i];
	}

	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage) - should be done
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	newRGB[y * getWidth() + x] = pixel;
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	newRGB[i] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order" -- already done
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return newRGB[y * getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return newRGB[i];

	//TODO: see setPixel(int i, RGB pixel)
}