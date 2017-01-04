#include "ofApp.h"

float height, width, center, diagonal, shortSide, smallHypotenuse;
float sqrt_2 = 1.4142135623731;
float angle;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0,255,0);
    height = ofGetHeight();
    width = ofGetWidth();
    center = ofGetHeight()/2;
    ofSetCircleResolution(500);
    angle = 0;
    diagonal = ofGetHeight() * sqrt_2;
    shortSide = sqrt(height/2 * height/2 + width/2 * width/2);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    angle += 1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xb5de10);

//    ofTranslate(width, height);
//    ofPushMatrix();
//    ofRotate(180);
//        drawQuarterPie(50, PI/2, 0, 0, PI/2, ofGetWidth());
//        ofSetColor(255,0,0);
//        drawQuarterPie_negative(50, PI/2, 0, 0, PI/2, ofGetWidth());
//    ofPopMatrix();

//        drawQuarterPie(50, PI/2, 0, 0, PI/2, ofGetWidth());
//        ofSetColor(255,0,0);
//        drawQuarterPie_negative(50, PI/2, 0, 0, PI/2, ofGetWidth());
//    ofSetColor(0,0,255);
//    drawCentreArc(50, PI/2, width, height, 3*PI/2);

//    ofNoFill();
//        drawQuarterPie(50, PI/2, 0, 0, PI/2, ofGetWidth());
//        drawQuarterPie(50, PI/2, width, height, 3*PI/2, ofGetWidth());

//    drawLeaf(true);
    ofSetColor(255, 255, 0);
    ofFill();
    ofDrawCircle(center, center, width/2);

    rotateRects(0);
    rotateRects(1);
    rotateRects(2);
    rotateRects(3);
    rotateRects(4);
    rotateRects(5);
    rotateRects(6);
    rotateRects(7);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::drawQuarterPie(int totalSteps, float totalDistance, float posX, float posY, float startAngle, float circleRadius){
    
    int numSteps = totalSteps;
    
    float oneAngleUnit = totalDistance / float(numSteps-1);
    float radius = circleRadius;
    float startTheta = startAngle;
    float startX = posX;
    float startY = posY;
    
    
    // Draw an arc.
    ofBeginShape();
    ofVertex(startX, startY);
    
    for (int i = 0; i < numSteps; i++){
        float anglef = startTheta - (float(i) * oneAngleUnit);
        
        float x = startX + radius * cos(anglef);
        float y = startY + radius * sin(anglef);
        ofVertex(x,y);
        //        angleCalculator += oneAngleUnit;
        //    			radius 	+= radiusAdder;
    }
    
    ofVertex(startX, startY);
    ofEndShape();
}

void ofApp::drawQuarterPie_negative(int totalSteps, float totalDistance, float posX, float posY, float startAngle, float circleRadius){
    
    int numSteps = totalSteps;
    
    float oneAngleUnit = totalDistance / float(numSteps-1);
    float radius = circleRadius;
    float startTheta = startAngle;
    float startX = abs(posX - width);
    float startY = abs(posY - height);
    
    
    // Draw an arc.
    ofBeginShape();
    ofVertex(startX, startY);
    
    for (int i = 0; i < numSteps; i++){
        float anglef = startTheta - (float(i) * oneAngleUnit);
        
        float x = posX + radius * cos(anglef);
        float y = posY + radius * sin(anglef);
        ofVertex(x,y);
        //        angleCalculator += oneAngleUnit;
        //    			radius 	+= radiusAdder;
    }
    
    ofVertex(startX, startY);
    ofEndShape();
}

void ofApp::drawCentreArc(int totalSteps, float totalDistance, float otherX, float otherY, float startAngle) {
    
    
    int numSteps = totalSteps;
    
    float oneAngleUnit = totalDistance / float(numSteps-1);
    float radius = diagonal - ofGetWidth();
    float startTheta = startAngle;
    float startX = otherX;
    float startY = otherY;
    
    
    // Draw an arc.
    ofBeginShape();
    ofVertex(startX, startY);
    
    for (int i = 0; i < numSteps; i++){
        float anglef = startTheta - (float(i) * oneAngleUnit);
        
        float x = startX + radius * cos(anglef);
        float y = startY + radius * sin(anglef);
        ofVertex(x,y);
        //        angleCalculator += oneAngleUnit;
        //    			radius 	+= radiusAdder;
    }
    
    ofVertex(startX, startY);
    ofEndShape();
    
}

void ofApp::drawLeaf(bool positive) {
    // draw the oval shape that is the result of two overlapping quarter pies.
//    drawQuarterPie(50, PI/2, 0, 0, PI/2, ofGetWidth());
//    drawQuarterPie(50, PI/2, width, height, 3*PI/2, ofGetWidth());
    int numSteps = 50;
    
    float oneAngleUnit = PI/2 / float(numSteps-1);
    float radius = ofGetWidth();
    float startTheta = PI;
    float startX = 200;
    float startY = 200;
    
    
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

void ofApp::blendShapes() {
    ofPushMatrix();
    
    ofTranslate(100,0,0);
    
    ofSetPolyMode(OF_POLY_WINDING_POSITIVE);
    ofBeginShape();
    
    
    ofVertex(300,500);
    ofVertex(380,550);
    ofVertex(300,600);
    
    ofNextContour(true);
    
    for (int i = 0; i < 20; i++){
        float anglef = ((float)i / 20.0f) * TWO_PI;
        float x = 340 + 30 * cos(anglef);
        float y = 550 + 30 * sin(anglef);
        ofVertex(x,y);
    }
    ofNextContour();
    
    ofVertex(300,400);
    ofVertex(400,400);
    ofVertex(350,600);
    
    ofEndShape(true);
}

void ofApp::rotateRects(int whichSize) {
    // whichSize 0 = full
    // whichSize 1 = smaller, side * 0.7654
    float sideLength;
    float mult1 = 1;
    float mult2 = -1;
    mult1 = whichSize + 1;
    mult2 = (whichSize + 1) * -1;
    sideLength = shortSide;
    float rotateCoeff;
    rotateCoeff= whichSize + 0.25;
    for (int i = 0; i < whichSize; i++) {
        sideLength *= 0.707;
    }

    ofSetRectMode(OF_RECTMODE_CENTER);

    if (whichSize % 2 != 0) {
        ofSetColor(255,255,0, 255 - whichSize * 50);
        ofNoFill();
    } else {
        ofSetColor(255,0,0, 255  - whichSize * 50);
        ofFill();
    }

    ofPushMatrix();
    ofTranslate(center,center);
    // sqaure is straight:
        ofPushMatrix();
        ofRotate(angle * rotateCoeff);
        ofDrawRectangle (0, 0, sideLength, sideLength);
        ofPopMatrix();
        
        // square is upright:
        ofPushMatrix();
        ofRotate((angle + 45) * 2 * rotateCoeff);
        ofDrawRectangle(0, 0, sideLength, sideLength);
        ofPopMatrix();
        
        ofRotate(30);
        ofPushMatrix();
        ofRotate((angle + 30) * -1 * rotateCoeff);
        ofDrawRectangle (0, 0, sideLength, sideLength);
        ofPopMatrix();
        
        ofPushMatrix();
        ofRotate((angle + 60) * -1 * 2 * rotateCoeff);
        ofDrawRectangle (0, 0, sideLength, sideLength);
        ofPopMatrix();
    ofPopMatrix();
}