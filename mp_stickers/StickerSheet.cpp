#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"
#include "Image.h"

//using namespace std;

StickerSheet::StickerSheet(const Image &picture, unsigned max){
    max_=max;
    X_coor=new unsigned[max];
    Y_coor=new unsigned[max];
    stickerz=new Image*[max];
    BGImage=picture;
    X_coor=0;
    Y_coor=0;

    num_stickers=0;
    for(unsigned i=0; i<max;i++){
        stickerz[i]=NULL;
    }
    
    
}

StickerSheet::~StickerSheet(){
    clear();
}
StickerSheet::StickerSheet (const StickerSheet &other){
    copy(other);
}
const StickerSheet &StickerSheet::operator= (const StickerSheet &other){
    if(this!=&other){
        clear();
        copy(other);
    }
    return *this;
}
void StickerSheet::changeMaxStickers (unsigned max){
    max_=max;
    if(max==num_stickers){
        return;
    }
    //temporary store the content and put in new value
    Image **temp_BG=new Image*[num_stickers];
    unsigned *temp_Xc=new unsigned[num_stickers];
    unsigned *temp_Yc=new unsigned[num_stickers];
    for(unsigned i=0;i<num_stickers;i++){
        temp_BG[i]=stickerz[i];
        temp_Xc[i]=X_coor[i];
        temp_Yc[i]=Y_coor[i];
    }
    // delete[] stickerz;
	// delete[] X_coor;
	// delete[] Y_coor;
    clear();

    stickerz=new Image*[max];
    X_coor=new unsigned[max];
    Y_coor=new unsigned[max];

    if(max<num_stickers){
        for(unsigned i=max;i<num_stickers;i++){
            delete temp_BG[i];
            temp_BG[i]=NULL;
        }
        num_stickers=max;
        for(unsigned i=0;i<num_stickers;i++){
            stickerz[i]=temp_BG[i];
            X_coor[i]=temp_Xc[i];
            Y_coor[i]=temp_Yc[i];
        }
    }
    else{
        for(unsigned i=0;i<num_stickers;i++){
            stickerz[i]=temp_BG[i];
            X_coor[i]=temp_Xc[i];
            Y_coor[i]=temp_Yc[i];
        }
    }
    delete[] temp_BG;
	delete[] temp_Xc;
	delete[] temp_Yc;
}
int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
    if(num_stickers<max_){
        if(stickerz[num_stickers]==NULL){
            stickerz[num_stickers]=new Image();
        }
        *stickerz[num_stickers]=sticker;
        X_coor[num_stickers]=x;
        Y_coor[num_stickers]=y;
        num_stickers++;
        return (num_stickers-1);
    }
    return -1;
}
bool StickerSheet::translate (unsigned index, unsigned x, unsigned y){
    if(index<num_stickers){
        X_coor[index]=x;
        Y_coor[index]=y;
        return 1;
    }else{
        return 0;
    }
}
void StickerSheet::removeSticker (unsigned index){
    if(index<num_stickers){
        for(unsigned i=index;i<num_stickers-1;i++){
            stickerz[i]=stickerz[i+1];
            X_coor[i]=X_coor[i+1];
            Y_coor[i]=Y_coor[i+1];
        }
        delete stickerz[num_stickers-1];
        stickerz[num_stickers]=NULL;
        num_stickers--;
    }
}
Image *StickerSheet::getSticker (unsigned index){
    if(index<num_stickers){
        return stickerz[index];
    }else{
        return NULL;
    }
    
}
Image StickerSheet::render () const{
    Image new_image;
    unsigned Xmax = BGImage.width();
    unsigned Ymax = BGImage.height();

    for (unsigned i = 0; i < num_stickers; i++){
        if(stickerz[i] != NULL){
            if(X_coor[i] + stickerz[i]->width() > Xmax){
                Xmax = X_coor[i] + stickerz[i]->width();
            }
            if(Y_coor[i] + stickerz[i]->height() > Ymax){
                Ymax = Y_coor[i] + stickerz[i]->height();
            }
        }
    }
    new_image = BGImage;
    new_image.resize(Xmax, Ymax);

    for(unsigned i = 0; i < num_stickers; i++){
        if(stickerz[i] != NULL){
            for(unsigned m = X_coor[i]; m < (X_coor[i] + stickerz[i]->width()); m++){
                for(unsigned n = Y_coor[i]; n < (Y_coor[i] + stickerz[i]->height()); n++){
                    HSLAPixel & pixel1=new_image.getPixel(m, n);
                    HSLAPixel & pixel2=stickerz[i]->getPixel((m - X_coor[i]), (n - Y_coor[i]));
                    if(pixel2.a != 0){
                        pixel1 = pixel2;
                    }
                }
            }
        }
    }
    return new_image;
}






void StickerSheet::copy(const StickerSheet&other){
    max_=other.max_;
    num_stickers=other.num_stickers;
    BGImage=other.BGImage;
    X_coor=new unsigned[max_];
    Y_coor=new unsigned[max_];
    stickerz=new Image*[max_];

    for (unsigned i=0;i<num_stickers;i++){
        stickerz[i]=new Image();
        *stickerz[i]=*(other.stickerz[i]);
        X_coor[i]=other.X_coor[i];
        Y_coor[i]=other.Y_coor[i];
    }
}
void StickerSheet::clear(){
    for (unsigned i=0;i<num_stickers;i++){
        delete stickerz[i];
        stickerz[i]=NULL;
    }
    delete[] stickerz;
    delete[] X_coor;
    delete[] Y_coor;
}
