#include "RGBImageStudent.h"
#include <iostream>

/*
Geen documentatie nodig :)
*/
RGBImageStudent::RGBImageStudent() : RGBImage() {
	//TODO: Nothing
}
/*
Kopieert alle waardes van de eerste image naar de tweede.
Gebruikt de width en height van de image om te bepalen hoe groot hij is.
*/
RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight())
, newRGB(new RGB[other.getWidth()* other.getHeight()]) {
	for (int i = 0; i < other.getWidth() * other.getHeight(); i++) {
		newRGB[i] = other.newRGB[i];
	}
	//TODO: Create a copy from the other object - should be done
}
/*
Geen documentatie nodig :)
*/
RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height),
newRGB(new RGB[width * height]){

	//TODO: Initialize pixel storage - should be done
}
/*
Geen documentatie nodig :)
*/
RGBImageStudent::~RGBImageStudent() {
	delete[] newRGB;
	//TODO: delete allocated objects - should be done
}
/*
Delete de oude storage en maakt een nieuwe aan.
*/
void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] newRGB;
	this->newRGB = new RGB[width * height];
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage) - should be done
}
/*
Delete de storage van het object en maakt een nieuwe aan met de waardes van &other.
*/
void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[] newRGB;
	this->newRGB = new RGB[other.getWidth() * other.getHeight()];
	for (int i = 0; i < other.getWidth() * other.getHeight(); i++) {
		newRGB[i] = other.newRGB[i];
	}

	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage) - should be done
}
/*
Set de waarde van de pixel.
Gebruikt "y * getWidth() om om de goede horizontale as te komen om daarna de goede X waarde te krijgen.
*/

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	newRGB[y * getWidth() + x] = pixel;
	//TODO: no comment needed :)
}

/*
Row-Major Order is al standaard in dit geval, dus krijgt de pixel gewoon een niewue waarde.
*/
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
/*
Zelfde systeem als setPixel(x, y)
*/
RGB RGBImageStudent::getPixel(int x, int y) const {
	return newRGB[y * getWidth() + x];
}
/*
Zelfde systeem als getPixel(i)
*/

RGB RGBImageStudent::getPixel(int i) const {
	return newRGB[i];

	//TODO: see setPixel(int i, RGB pixel)
}