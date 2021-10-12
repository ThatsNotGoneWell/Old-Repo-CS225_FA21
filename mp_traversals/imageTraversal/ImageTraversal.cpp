#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
}

ImageTraversal::Iterator::Iterator(ImageTraversal *tr, PNG & p,Point & po, double & t) {
  /** @todo [Part 1] */
  store=tr;
  start_=po;
  tolerance_=t;
  png_=p;
  current_=store->peek();
  visited.resize(p.width()*p.height(),0);
}




bool ImageTraversal::Iterator::check(const Point & point) const {
  if(point.y<png_.height() && point.x<png_.width()) {
    HSLAPixel first = png_.getPixel(start_.x,start_.y);
    HSLAPixel second = png_.getPixel(point.x,point.y);
    bool checkV=visited[point.x + point.y * png_.width()];
    if(!checkV) {
      return calculateDelta(first,second)<tolerance_;
    }
  }
  return false;
}


/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  
  if (store->empty()) {
    return *this;
  } else {
    visited[current_.x + current_.y * png_.width()] = true;

    Point right_ = Point(current_.x + 1, current_.y);
    Point down_ = Point(current_.x, current_.y + 1);
    Point left_ = Point(current_.x - 1, current_.y);
    Point up_ = Point(current_.x, current_.y - 1);
    
    while (!store->empty() ) {
      Point temp=Point(store->peek().x, store->peek().y);
      bool checkV=visited[temp.x + temp.y * png_.width()];
      if(!checkV){
        break;
      }
      current_ = store->pop();

      }

    if (check(right_)) {
      store->add(right_);
    }
    if (check(down_)) {
      store->add(down_);
    }
    if (check(left_)) {
      store->add(left_);
    }
    if (check(up_)) {
      store->add(up_);
    }
    if (!store->empty()) {
      current_ = store->peek();
    }
  }
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  bool oneE = 0; 
  bool twoE = 0;

  if (store == NULL) { 
    oneE = 1; 
  }
  if (other.store == NULL) { 
    twoE = 1; 
  }

  if (!oneE)  { 
    oneE = store->empty(); 
  }
  if (!twoE) { 
    twoE = other.store->empty(); 
  }

  if (oneE && twoE) {
    return 0;
  } 
  else if ((!oneE)&&(!twoE)) {
    return (store != other.store); 
  }
  else {
    return 1;
  } 
}
