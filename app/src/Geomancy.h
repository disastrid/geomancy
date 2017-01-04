#ifndef _GEOMANCY
#define _GEOMANCY

#pragma once
#include "ofMain.h"

class Geomancy {
    
    public:
    void setup();
    void drawLeaf(bool positive);
    float tileDim = 100;
    float blockDim = 100;
    int blockCounter = 0;
    // Declare the constructor
    Geomancy();
    
    int NBLOCKS = 9;
    int NTILES = 4;
    
};

//class Block {
//public:
//    Block(); // block constructor
//    
//private:
////    Tile tiles[NTILES];
//};

class Tile {
public:
    Tile(); // tile constructor
};
#endif