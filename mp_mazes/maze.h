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
        bool makeMazeH(int rInt,int dir,int second,int width);
        bool canTravel(int x, int y, int dir) const;
        void setWall(int x, int y, int dir, bool exist);
        std::vector<int> solveMaze();
        PNG* drawMaze() /*const*/;
        PNG* drawMazeWithSolution();
        std::vector<int> findLongest(std::vector<int> output,std::vector<int> solved,int cur_longest_index);
        PNG * drawMazeH(PNG * result);
        void setPixel(HSLAPixel & pixel_);

    private:
        int width_ = 0;
        int height_ = 0;
        int area = width_ * height_;
        std::vector<int> walls;
        DisjointSets disjoint_set;
        bool random_bool();
        int random_int();
        std::queue<int> q;
        std::vector<int> solveMazeH();
};
