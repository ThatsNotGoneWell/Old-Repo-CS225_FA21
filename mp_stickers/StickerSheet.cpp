#include "StickerSheet.h"
#include "Image.h"

using namespace cs225;


StickerSheet::StickerSheet(const Image & picture, unsigned max) {
    
    BGImage = new Image(picture);
    
    max_=max;
    X_coor=new unsigned[max];
    Y_coor=new unsigned[max];
    stickerz=new Image*[max];
    

    num_stickers=0;
    for(unsigned i=0; i<max;i++){
        stickerz[i]=NULL;
    }
}

StickerSheet::StickerSheet(const StickerSheet & other){
    copy(other);
}

StickerSheet::~StickerSheet() {
    clear();
}

void StickerSheet::copy(const StickerSheet & other) {
    
    BGImage = new Image(*(other.BGImage));
    


    max_=other.max_;
    num_stickers=other.num_stickers;
    X_coor=new unsigned[max_];
    Y_coor=new unsigned[max_];
    stickerz=new Image*[max_];

    for (unsigned i = 0; i < max_; i++){
        stickerz[i] = NULL;
    }

    for (unsigned i=0;i<num_stickers;i++){
        stickerz[i]=new Image();
        *stickerz[i]=*(other.stickerz[i]);
        X_coor[i]=other.X_coor[i];
        Y_coor[i]=other.Y_coor[i];
    }
}

void StickerSheet::clear() {
    
    delete BGImage;

    for (unsigned i=0;i<num_stickers;i++){
        delete stickerz[i];
        stickerz[i]=NULL;
    }
    delete[] stickerz;
    stickerz= NULL;
    delete[] X_coor;
    X_coor=NULL;
    delete[] Y_coor;
    Y_coor=NULL;
}

int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y) {
    if(num_stickers == max_) {
        return -1;
    } else {
        stickerz[num_stickers] = new Image(sticker);
        X_coor[num_stickers] = x;
        Y_coor[num_stickers] = y;
        unsigned layer = num_stickers;
        num_stickers++;
        return layer;
    }
}



void StickerSheet::changeMaxStickers(unsigned max) {
    Image ** stickers_after = new Image * [num_stickers];
    unsigned * x_values_after = new unsigned[num_stickers];
    unsigned * y_values_after = new unsigned[num_stickers];
    
    for(unsigned i = 0; (i < num_stickers); i++) {
        stickers_after[i] = stickerz[i];
        x_values_after[i] = X_coor[i];
        y_values_after[i] = Y_coor[i];
    }
    delete[] X_coor;
    delete[] Y_coor;
    delete[] stickerz;

    stickerz = new Image * [max];
    X_coor = new unsigned[max];
    Y_coor = new unsigned[max];

    while(max < num_stickers) {
        delete stickers_after[num_stickers - 1];
        stickers_after[num_stickers - 1] = NULL;
        num_stickers--;
    }

    for(unsigned i = 0; (i < num_stickers); i++) {
        stickerz[i] = stickers_after[i];
        X_coor[i] = x_values_after[i];
        Y_coor[i] = y_values_after[i];
    }

    max_ = max;

    delete[] stickers_after;
    delete[] x_values_after;
    delete[] y_values_after;

    stickers_after = NULL;
    x_values_after = NULL;
    y_values_after = NULL;



    
}


Image * StickerSheet::getSticker(unsigned index) {
    

    if(index<num_stickers){
        return stickerz[index];
    }else{
        return NULL;
    }
}

const StickerSheet & StickerSheet::operator=(const StickerSheet & other) {
    clear();
    copy(other);
    return *this;
}	

void StickerSheet::removeSticker(unsigned index) {
    


    if(index<num_stickers){
        for(unsigned i=index;i<num_stickers-1;i++){
            *stickerz[i]=*stickerz[i+1];
            X_coor[i]=X_coor[i+1];
            Y_coor[i]=Y_coor[i+1];
        }
        delete stickerz[num_stickers-1];
        stickerz[num_stickers]=NULL;
        num_stickers--;
    }
}	

Image StickerSheet::render() const {
    Image output = Image(*BGImage);
    for(unsigned int i = 0; i < num_stickers; i++) {
        if(output.width() < X_coor[i] + stickerz[i]->width()) {
            output.resize(X_coor[i] + stickerz[i]->width(), output.height());
        }
        if(output.height() < Y_coor[i] + stickerz[i]->height()) {
            output.resize(output.width(), Y_coor[i] + stickerz[i]->height());
        }
        for(unsigned int x = 0; x < stickerz[i]->width(); x++) {
            for(unsigned int y = 0; y < stickerz[i]->height(); y++) {
                HSLAPixel & pixel = stickerz[i]->getPixel(x, y);
                HSLAPixel & bg_pixel = output.getPixel(x + X_coor[i], y + Y_coor[i]);
                if(pixel.a != 0) {
                    bg_pixel = pixel;
                }
            }
        }
    }
    return output;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
    if(index >= num_stickers) {
        return false;
    } else {
        X_coor[index] = x;
        Y_coor[index] = y;
        return true;
    }
}
