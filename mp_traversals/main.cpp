#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  
  
  PNG pic;
  pic.readFromFile("pacman.png");
  FloodFilledImage image(pic);
  DFS dfs_(pic, Point(100,120), 0.2);
  BFS bfs_(pic,Point(120,70),0.5);
  
  MyColorPicker newPic(1.005);
  image.addFloodFill(dfs_,newPic);
  MyColorPicker newPic2(1.000001);
  image.addFloodFill(bfs_,newPic2);
  

  Animation animation=image.animate(200);
  
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  
  return 0;
}
