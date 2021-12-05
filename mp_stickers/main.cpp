#include "Image.h"
#include "StickerSheet.h"

int main() {
  Image alma, sticker1, sticker2, sticker3, output;
  
  alma.readFromFile("alma.png");
  sticker1.readFromFile("i.png");
  sticker2.readFromFile("i.png");
  sticker3.readFromFile("i.png");
  
  StickerSheet mp2pic(alma, 4);
  
  
  
  mp2pic.addSticker(sticker1, 15, 35);
  
  
  mp2pic.addSticker(sticker2, 550, 60);
  
  
  output = mp2pic.render();
  
  output.writeToFile("myImage.png");
  return 0;
}
