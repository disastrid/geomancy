#include "ofApp.h"


float height, width, center, diagonal;
float sqrt_2 = 1.4142135623731;
int alpha = 0;
float phase = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    height = ofGetHeight()/2;
    width = ofGetWidth()/2;
    center = ofGetHeight()/4;
    ofSetCircleResolution(500);
    
    diagonal = ofGetHeight()/2 * sqrt_2;
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    if (alpha < 255 || alpha <= 0) {
//        alpha++;
//    }  else if (alpha >= 255)
//        alpha--;
    
    alpha = 255 * abs(osc1.sinewave(1200));
//    alpha = 255 * abs(osc1.saw(1200));
//    alpha = 255 * abs(osc1.triangle(220));
//    alpha = 255 * osc1.square(4);
//    ofSetColor(255, 0, 0, alpha);
}

//--------------------------------------------------------------
void ofApp::draw(){
        ofSetColor(255, 0, 0);

//    ofSetColor(255, 0, 0, 255);
    
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

    
    // This works to lay out leaf arcs:
//    drawLeaf(true);
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2,ofGetWidth()/2);
//    drawLeaf(true);
//    ofPopMatrix();
//    
//
//    ofPushMatrix();
//    ofTranslate(ofGetWidth(),0);
//    ofRotate(90);
//    drawLeaf(true);
//    ofPopMatrix();
//    
//    ofPushMatrix();
//    ofTranslate(0,ofGetWidth());
//    ofRotate(-90);
//    drawLeaf(true);
//    ofPopMatrix();
    
    // Lay out columns:
//    drawVertCentre(true, 1);
    
    // draw 1/3 sections of each square:
    
//    drawThirds(4, true);
    drawThirds(1, false);
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

//void ofApp::drawVertCentre(bool filled int version) {
//    // version 1 = vertical column, centre middle
//    // version 2 = horizontal column, centre middle
//    // version 3 = combined 1 & 2; cross
//    // version 4 = top column
//    // version 5 = edge column
//    // version 6 =
//    
//}

void ofApp::drawThirds(int mode, bool filled) {
    // mode 0: section 1 active
    // mode 1: section 2 active
    // mode 2: section 3 active
    // mode 3: section 1 & 2 active
    // mode 4: section 2 & 3 active
    // mode 5: section 1 & 3 active
    
    if (filled) {
        ofFill();
    
        ofBeginShape();
        ofVertex(width, height);
        switch(mode) {
            case 0:
                ofVertex(0, height);
                ofVertex(0, height/2);
                break;
            case 1:
                ofVertex(0, height/2);
                ofVertex(0,0);
                ofVertex(width/2, 0);
                break;
            case 2:
                ofVertex(width/2, 0);
                ofVertex(width, 0);

                break;
            case 3:
                ofVertex(0, height);
                ofVertex(0,0);
                ofVertex(width/2, 0);
                break;
            case 4:
                ofVertex(0, height/2);
                ofVertex(0,0);
                ofVertex(width, 0);
                break;
            case 5:
                ofVertex(0, height);
                ofVertex(0, height/2);
                ofVertex(width, height);
                ofVertex(0, height);
                ofVertex(width/2, 0);
                break;
        }
        ofVertex(width, height);

        ofEndShape();
    } else {
        // draw lines describing the shape
        switch(mode) {
            case 0:
                ofDrawLine(width, height, 0, height);
                ofDrawLine(width, height, 0, height/2);
                break;
            case 1:
                ofDrawLine(width, height, 0, height/2);
                ofDrawLine(width, height, width/2, 0);
                break;
            case 2:
                ofDrawLine(width, height, width/2, 0);
                ofDrawLine(width, height, width, 0);
                
                break;
            case 3:
                ofVertex(0, height);
                ofVertex(0,0);
                ofVertex(width/2, 0);
                break;
            case 4:
                ofVertex(0, height/2);
                ofVertex(0,0);
                ofVertex(width, 0);
                break;
            case 5:
                ofVertex(0, height);
                ofVertex(0, height/2);
                ofVertex(width, height);
                ofVertex(0, height);
                ofVertex(width/2, 0);
                break;
        }
    }
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