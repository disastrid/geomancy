#ifndef _GEOMANCY
#define _GEOMANCY

#pragma once
#include "ofMain.h"

class Geomancy : public ofBaseApp{
    
    public:
    void setup();
    void drawLeaf(bool positive);
    float tileDim = 100;
    float blockDim = 100;
    int blockCounter = 0;
    extern int tileArrayCounter = 0;
    // Declare the constructor
    Geomancy();
};
#endif