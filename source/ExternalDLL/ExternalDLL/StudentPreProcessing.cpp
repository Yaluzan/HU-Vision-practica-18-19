#include "StudentPreProcessing.h"
#include <iostream>
#include "ImageIO.h"
#include "ImageFactory.h"

/*
stepToIntensityImage
RGB &image

Wij maken een nieuwe intensity image aan vanuit de imagefactory 
die alle groene waardes krijgt van de RGB image. Dit is verder uitgelegd in het verslag.


Return IntensityImage pointer van ImageFactory

*/
IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	//std::cout << "| Width: " << image.getWidth() << "| Height: " << image.getHeight();
	IntensityImage * intensity = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getWidth() *image.getHeight(); i++) {
		intensity->setPixel(i, image.getPixel(i).g);
	}
	return intensity;
}

//IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
//	return nullptr;
//}
//
//IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
//	return nullptr;
//}




IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}