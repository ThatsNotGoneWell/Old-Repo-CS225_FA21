#include <iostream>
#include <cmath>
#include <cstdlib>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "Image.h"

using cs225::HSLAPixel;
using cs225::PNG;
using namespace cs225;




void Image::darken() {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.l<0.1){
                pixel.l=0;
            }else{
                pixel.l=pixel.l-0.1;
            }
            //HSLAPixel& outRotated = output->getPixel(width-x-1, height-y-1);
            
            //outRotated = in;
        }
    }
    
    // Save the output file
    //output->writeToFile(outputFile);

    // Clean up memory
    //delete myPixel;
    //delete output;
    //delete original;
}



void Image::darken(double amount) {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.l<amount){
                pixel.l=0;
            }else{
                pixel.l=pixel.l-amount;
            }
            
        }
    }
    
    
}

void Image::lighten() {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.l>0.9){
                pixel.l=1;
            }else{
                pixel.l=pixel.l+0.1;
            }
            
        }
    }   
}

void Image::lighten(double amount) {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.l>1-amount){
                pixel.l=1;
            }else{
                pixel.l=pixel.l+amount;
            }
            
        }
    }
    
    
}






void Image::saturate() {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.s>0.9){
                pixel.s=1;
            }else{
                pixel.s=pixel.s+0.1;
            }
            
        }
    }
    
}



void Image::saturate(double amount) {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.s+amount>1){
                pixel.s=1;
            }else{
                pixel.s=pixel.s+amount;
            }
            
        }
    }
    
    
}

void Image::desaturate() {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.s>0.9){
                pixel.s=1;
            }else{
                pixel.s=pixel.s+0.1;
            }
            
        }
    }   
}

void Image::desaturate(double amount) {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.s>1-amount){
                pixel.s=1;
            }else{
                pixel.s=pixel.s+amount;
            }
            
        }
    }
    
    
}


void Image::greyscale() {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            pixel.s=0;
            
        }
    }   
}

void Image::rotateColor(double degrees) {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.h+degrees>=360){
                pixel.h=pixel.h+degrees-360;
            }else{
                pixel.h=pixel.h+degrees;
            }
            
        }
    }   
}

void Image::illinify() {
    
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            if(pixel.h>113.5 && pixel.h<293.5){
                pixel.h = 216;
            }else{
                pixel.h = 11;
            }
            
        }
    }   
}

void Image::scale(unsigned w, unsigned h) {
    
    PNG *output = new PNG(w,h);
    
    //relocate the pixels
    for (unsigned int x = 0; x < w; x++) {
        for (unsigned int y = 0; y < h; y++) {
            
            HSLAPixel & scaled = output->getPixel(x, y);
            unsigned relocatedX = (unsigned)( (float)x / w * this->width());
            unsigned relocatedY = (unsigned)( (float)y / h * this->height());
			scaled=this->getPixel(relocatedX, relocatedY);
			
        }
    }
    //resize
    this->resize(w,h);
    //assign new image to the original
    for (unsigned int x = 0; x < w; x++) {
        for (unsigned int y = 0; y < h; y++) {
            
            HSLAPixel& pixel = this->getPixel(x, y);
            
			HSLAPixel & scaled = output->getPixel(x, y);
			pixel=scaled;
        }
    }
    delete output;
}

void Image::scale(double factor) {
    unsigned int scaledX= this->width()*factor;
    unsigned int scaledY= this->height()*factor;
    scale(scaledX,scaledY);
     
}
