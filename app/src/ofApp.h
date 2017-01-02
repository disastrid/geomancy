#pragma once
#include "ofxMaxim.h"
#include "ofMain.h"
#include <string>

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void drawQuarterPie(int totalSteps, float totalDistance, float posX, float posY, float startAngle, float circleRadius);
    void drawQuarterPie_negative(int totalSteps, float totalDistance, float posX, float posY, float startAngle, float circleRadius);
    void drawCentreArc(int totalSteps, float totalDistance, float posX, float posY, float startAngle);
    void drawLeaf(bool positive);
    void blendShapes();
    void drawThirds(int mode, bool filled);
    maxiOsc osc1;
    float height, width, center, diagonal;
    float sqrt_2 = 1.4142135623731;
    int alpha = 0;
    float phase = 0;
    int blockDim, tileDim;

};
