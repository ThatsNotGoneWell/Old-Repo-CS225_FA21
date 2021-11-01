/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */

    int numR = theSource.getRows();
    int numC = theSource.getColumns();
    
    if(numR <= 0){
        return NULL;
    }else if(numC <= 0){
        return NULL;
    }else if(theTiles.empty()){
        return NULL;
    }

    MosaicCanvas * canvas = new MosaicCanvas(numR, numC);

    vector<Point<3>> DDDpoint(theTiles.size());
    map<Point<3>, int> the_map;
    for(unsigned long i = 0; i < theTiles.size(); i++) {
        auto temp = theTiles[i].getAverageColor();
        DDDpoint[i] = convertToXYZ(temp);
        the_map[DDDpoint[i]] = i;
    }
   
    
    KDTree<3> the_tree(DDDpoint);
    

    for (int i=0;i < numR;i++) {
        
        for(int j=0;j < numC;j++) {
            auto color_ = theSource.getRegionColor(i, j);
            auto color_next = convertToXYZ(color_);
            auto close = the_tree.findNearestNeighbor(color_next);
            
            canvas->setTile(i, j, &theTiles[the_map[close]]);
        }
    }
    return canvas;
}
