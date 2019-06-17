#include "IntensityImageStudent.h"

/*
Geen documentatie nodig :)
*/
IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//TODO: Nothing
}
/*
Kopieert alle waardes van de eerste image naar de tweede.
Gebruikt de width en height van de image om te bepalen hoe groot hij is.
*/
IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight())
, newInt(new Intensity[other.getWidth()* other.getHeight()]) {
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		newInt[i] = other.newInt[i];
	}
	//TODO: Create a copy from the other object -- done
}
/*
Geen documentatie nodig :)
*/
IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height),
	newInt(new Intensity[width * height]) {
	//TODO: Initialize pixel storage -- done
}
/*
Geen documentatie nodig :)
*/
IntensityImageStudent::~IntensityImageStudent() {
	delete[] newInt;
	//TODO: delete allocated objects -- done
}
/*
Delete de oude storage en maakt een nieuwe aan.
*/
void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] newInt;
	this->newInt = new Intensity[width * height];
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage) -- done
}
/*
Delete de storage van het object en maakt een nieuwe aan met de waardes van &other.
*/
void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete[] newInt;
	this->newInt = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < other.getWidth() * other.getHeight(); i++) {
		newInt[i] = other.newInt[i];
	}
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage) -- done
}
/*
Set de waarde van de pixel.
Gebruikt "y * getWidth() om om de goede horizontale as te komen om daarna de goede X waarde te krijgen.
*/
void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	newInt[y * getWidth() + x] = pixel;
}
/*
Row-Major Order is al standaard in dit geval, dus krijgt de pixel gewoon een niewue waarde.
*/
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
/*
Zelfde systeem als setPixel(x, y)
*/
Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return newInt[y * getWidth() + x];
}
/*
Zelfde systeem als getPixel(i)
*/
Intensity IntensityImageStudent::getPixel(int i) const {
	return newInt[i];
}