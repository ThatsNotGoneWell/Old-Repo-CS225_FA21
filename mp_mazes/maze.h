/* Your code here! */
#pragma once
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "dsets.h"
#include <queue>

using namespace cs225;
class SquareMaze {
    public:
        SquareMaze();
        void makeMaze(int width, int height);
        void makeMazeH(int dir,int second,int width);
        bool canTravel(int x, int y, int dir) const;
        void setWall(int x, int y, int dir, bool exist);
        std::vector<int> solveMaze();
        PNG* drawMaze() ;
        
        PNG* drawMazeWithSolution();
        PNG * drawMazeH(PNG * result);
        void setPixel(HSLAPixel & pixel_);

    private:
        int width_ = 0;
        int height_ = 0;
        int area = width_ * height_;
        int destination=0;
        std::vector<int> walls;
        DisjointSets disjoint_set;
        bool random_bool();
        int random_int();
        std::queue<int> q;
        std::vector<int> bfs();
};
