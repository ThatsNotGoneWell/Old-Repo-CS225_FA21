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
    
    
    
    
    
    if(max==num_stickers){
        return;
    }
    //temporary store the content and put in new value
    Image **temp_BG=new Image*[max];
    for(unsigned i=0;i<max;i++){
        temp_BG[i]=NULL;
    }
    unsigned *temp_Xc=new unsigned[num_stickers];
    unsigned *temp_Yc=new unsigned[num_stickers];
    if(num_stickers<max){
        for(unsigned i=0;i<num_stickers;i++){
        temp_BG[i]=new Image();
        *temp_BG[i]=*stickerz[i];
        temp_Xc[i]=X_coor[i];
        temp_Yc[i]=Y_coor[i];
    }
    }else{
    for(unsigned i=0;i<max;i++){
        temp_BG[i]=new Image();
        *temp_BG[i]=*stickerz[i];
        temp_Xc[i]=X_coor[i];
        temp_Yc[i]=Y_coor[i];
    }num_stickers = max;
    }
    // delete[] stickerz;
	// delete[] X_coor;
	// delete[] Y_coor;
    //clear();

    clear();
    stickerz=temp_BG;
    temp_BG=NULL;
    X_coor=temp_Xc;
	temp_Xc=NULL;
    Y_coor=temp_Yc;
	temp_Yc=NULL;
    max_=max;
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
            *stickerz[i]=*stickerz[i+1];
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
    Image output;
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
    output = BGImage;
    output.resize(Xmax, Ymax);

    for(unsigned i = 0; i < num_stickers; i++){
        if(stickerz[i] != NULL){
            for(unsigned int m = X_coor[i]; m < (X_coor[i]+ stickerz[i]->width()); m++){
                for(unsigned int n = Y_coor[i]; n < (Y_coor[i]+ stickerz[i]->width()); n++){
                    HSLAPixel & pixel1=output.getPixel(m, n);
                    HSLAPixel & pixel2=stickerz[i]->getPixel((m - X_coor[i]), (n - Y_coor[i]));
                    if(pixel2.a != 0){
                        pixel1 = pixel2;
                    }
                }
            }
        }
    }
    return output;
}






void StickerSheet::copy(const StickerSheet&other){
    max_=other.max_;
    num_stickers=other.num_stickers;
    BGImage=other.BGImage;
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
void StickerSheet::clear(){
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
