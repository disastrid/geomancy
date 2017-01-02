#include "Geomancy.h"
#include "ofApp.h"

// Geomancy is the parent class for the project. This is the class that lays out the blocks in the main app (really just translates to a location, then draws what it needs to - a holder). The real idea of the master class is to declare all the variables that the children classes will need.

// Geomancy (lays out 9 blocks)
    // Blocks (each collects and lays out 4 tiles, stored in an array 0-3)
        // Tiles (the actual geometric shapes - where all the drawing, timing and magic happens)

// The constructor. All objects should get these variables.
Geomancy::Geomancy() {
    tileDim = 100;
    blockDim = tileDim * 2;
    
}

void Geomancy::drawLeaf(bool positive) {
    // draw the oval shape that is the result of two overlapping quarter pies.
    //    drawQuarterPie(50, PI/2, 0, 0, PI/2, ofGetWidth());
    //    drawQuarterPie(50, PI/2, width, height, 3*PI/2, ofGetWidth());
    int numSteps = 50;
    
    float oneAngleUnit = PI/2 / float(numSteps-1);
    float radius = width;
    float startTheta = PI/2;
    float startX = 0;
    float startY = 0;
    
    
    // Draw an arc.
    ofBeginShape();
    if (!positive)
        ofVertex(abs(startX-width), abs(startY-height));
    
    for (int i = 0; i < numSteps; i++){
        float anglef = startTheta - (float(i) * oneAngleUnit);
        
        float x = startX + radius * cos(anglef);
        float y = startY + radius * sin(anglef);
        ofVertex(x,y);
        //        angleCalculator += oneAngleUnit;
        //    			radius 	+= radiusAdder;
    }
    if (!positive) {
        ofVertex(abs(startX-width), abs(startY-height));
        ofEndShape();
        ofBeginShape();
    }
    
    startTheta = 3*PI/2;
    startX = width;
    startY = height;
    
    if (!positive) {
        ofVertex(0, 0);
    }
    for (int i = 0; i < numSteps; i++){
        float anglef = startTheta - (float(i) * oneAngleUnit);
        
        float x = startX + radius * cos(anglef);
        float y = startY + radius * sin(anglef);
        ofVertex(x,y);
        //        angleCalculator += oneAngleUnit;
        //    			radius 	+= radiusAdder;
    }
    if (!positive)
        ofVertex(0, 0);
    
    ofEndShape();
}
