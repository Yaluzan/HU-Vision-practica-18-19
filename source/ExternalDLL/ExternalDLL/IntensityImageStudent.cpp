#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight())
, newInt(new Intensity[other.getHeight()* other.getWidth()]) {
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		newInt[i] = other.newInt[i];
	}
	//TODO: Create a copy from the other object -- done
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height),
	newInt(new Intensity[width * height]) {
	//TODO: Initialize pixel storage -- done
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] newInt;
	//TODO: delete allocated objects -- done
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] newInt;
	this->newInt = new Intensity[width * height];
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage) -- done
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete[] newInt;
	this->newInt = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < other.getWidth() * other.getHeight(); i++) {
		newInt[i] = other.newInt[i];
	}
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage) -- done
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	newInt[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	newInt[i] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order" -- done	
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

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return newInt[y * getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return newInt[i];
}