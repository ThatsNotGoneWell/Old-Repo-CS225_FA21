#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>

#include <iostream>
#include <cmath>
#include <cstdlib>

#include "intro.h"

using cs225::HSLAPixel;
using cs225::PNG;
using namespace cs225;

PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

// HSLAPixel* myFavoriteColor(double hue) {
//     HSLAPixel p(hue, 0.8, 0.5);
//     return &p;
// }

void rotate(std::string inputFile, std::string outputFile) {
  // Load in.png
    PNG* original = new PNG();

    original->readFromFile(inputFile);
    unsigned width = original->width();
    unsigned height = original->height();

    // Create out.png
    PNG* output;
    output=setupOutput(width, height);

    

    // Load our favorite color to color the outline
    //HSLAPixel* myPixel = myFavoriteColor(11);
    
    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned x = 0; x < width; x++) {
        for (unsigned y = 0; y < height; y++) {
            // Calculate the pixel difference
            //HSLAPixel& out = original->getPixel(x - 1, y - 1);
            
            HSLAPixel& in = original->getPixel(x, y);
            //double diff = std::fabs(curr.h - prev.h);

            
            
            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            HSLAPixel& outRotated = output->getPixel(width-x-1, height-y-1);
            // if (diff > 20) {
            //     currOutPixel = *myPixel;
            // }
            outRotated = in;
        }
    }
    
    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    //delete myPixel;
    delete output;
    delete original;
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  
  //smog background
  for (unsigned x = 0; x < width; x++) {
        for (unsigned y = 0; y < height; y++) {
            HSLAPixel & pixel = png.getPixel(x, y);
            
              pixel.h = 198;
              pixel.s = 0.2-0.2*(y/(double)height);
              pixel.l = 0.7-0.2*(y/(double)height);
            }
    }

  //background building
  for (unsigned x = 0; x < width; x++) {
        for (unsigned y = height-height/10; y < height; y++) {
            HSLAPixel & pixel = png.getPixel(x, y);
            
            pixel.h = 0;
            pixel.s = 0.2-0.2*(y/(double)height);
            pixel.l = 0.6-0.1*(y/(double)height);
        }
  }
  //building 1
  for (unsigned x = 350; x < 450; x++) {
        for (unsigned y = height/3; y < height; y++) {
            HSLAPixel & pixel = png.getPixel(x, y);
            
            pixel.h = 45;
            pixel.s = 0.2-0.2*(y/(double)height);
            pixel.l = 0.6-0.1*(y/(double)height);
        }
  }
  //building 2

  for (unsigned x = 100; x < 210; x++) {
        for (unsigned y = height-3*height/10; y < height; y++) {
            HSLAPixel & pixel = png.getPixel(x, y);
            
            pixel.h = 45;
            pixel.s = 0.1-0.1*(y/(double)height);
            pixel.l = 0.6-0.1*(y/(double)height);
        }
  }
  //building 3
  for (unsigned x = 200; x < 340; x++) {
        for (unsigned y = height/2; y < height; y++) {
            HSLAPixel & pixel = png.getPixel(x, y);
            
            pixel.h = 216;
            pixel.s = 0.2-0.2*(y/(double)height);
            pixel.l = 0.6-0.1*(y/(double)height);
        }
  }
  //building 4
  for (unsigned x = 550; x < 720; x++) {
        for (unsigned y = height-2*height/5; y < height; y++) {
            HSLAPixel & pixel = png.getPixel(x, y);
            
            pixel.h = 180;
            pixel.s = 0.1-0.1*(y/(double)height);
            pixel.l = 0.6-0.1*(y/(double)height);
        }
  }
  //building 5
  for (unsigned x = 435; x < 660; x++) {
        for (unsigned y = 2*height/3; y < height; y++) {
            HSLAPixel & pixel = png.getPixel(x, y);
            
            pixel.h = 11;
            pixel.s = 0.2-0.2*(y/(double)height);
            pixel.l = 0.6-0.1*(y/(double)height);
        }
  }
  
  
  //building 6
  for (unsigned x = 150; x < 380; x++) {
        for (unsigned y = height-2*height/11; y < height; y++) {
            HSLAPixel & pixel = png.getPixel(x, y);
            
            pixel.h = 235;
            pixel.s = 0.1-0.1*(y/(double)height);
            pixel.l = 0.6-0.1*(y/(double)height);
        }
  }
  return png;
}
