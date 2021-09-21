#include "Image.h"
#include "StickerSheet.h"

int main() {
  Image alma, sticker1, sticker2, sticker3, output, scale2x;
  
  scale2x.readFromFile("scale2x.png");
  sticker1.readFromFile("i.png");
  sticker2.readFromFile("i.png");
  sticker3.readFromFile("i.png");
  
  StickerSheet mp2pic(scale2x, 4);
  //bug test
  std::cout<<"Reached Line"<<__LINE__<<std::endl;
  output = mp2pic.render();
  //bug test
  std::cout<<"Reached Line"<<__LINE__<<std::endl;
  output.writeToFile("myImage.png");
  //bug test
  std::cout<<"Reached Line"<<__LINE__<<std::endl;
  mp2pic.addSticker(sticker1, 15, 35);
  //bug test
  std::cout<<"Reached Line"<<__LINE__<<std::endl;
  mp2pic.addSticker(sticker2, 295, 60);
  mp2pic.addSticker(sticker2, 550, 60);
  mp2pic.addSticker(sticker3, 400, 140);
  //bug test
  std::cout<<"Reached Line"<<__LINE__<<std::endl;
  //output = mp2pic.render();
  //bug test
  std::cout<<"Reached Line"<<__LINE__<<std::endl;
  //output.writeToFile("myImage.png");
  return 0;
}
