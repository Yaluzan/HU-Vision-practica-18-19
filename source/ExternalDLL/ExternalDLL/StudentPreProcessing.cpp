#include "StudentPreProcessing.h"
#include <iostream>
#include "ImageIO.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent intensity(image.getWidth(), image.getHeight());
	for (int i = 0; i < image.getHeight() * image.getWidth(); i++) {
		intensity.setPixel(i, image.getPixel(i).g);
	//intensity.setPixel(i, 244);
	}
	std::cout << image.getHeight() << "   " << image.getWidth() << " oof ";
	ImageIO::saveIntensityImage(intensity , ImageIO::getDebugFileName("Pre-processing-2.png"));

	return &intensity;
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