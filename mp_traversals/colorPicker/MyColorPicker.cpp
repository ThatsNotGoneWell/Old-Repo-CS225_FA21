#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  HSLAPixel pixel(hue_,saturation_,luminance_);
  //index=1/x;
  hue_*=index;
  saturation_*=index;
  luminance_*=index;
  while(index<0){
    index*=-1;
  }
  while(hue_>=360){
    hue_-=360;
  }
  while(saturation_>=1){
    saturation_-=1;
  }
  while(luminance_>=1){
    luminance_-=1;
  }
  return pixel;
}

MyColorPicker::MyColorPicker(double index)
:index(index),hue_(1),saturation_(0.5),luminance_(0.5) { }
