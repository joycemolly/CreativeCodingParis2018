#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    xDestation = ofGetWidth()-20;
    ofSetBackgroundColor(ofColor::honeyDew);
    
    pos0A.x =pos1A.x=pos2A.x=pos3A.x=pos4A.x=pos5A.x=pos6A.x=pos7A.x=pos8A.x=0;
    
    
    //linear
    pos0B.x = xDestation;
    
    //inOutSine
    pos1B.x = xDestation;
    
    //inQuad
    pos2B.x = xDestation;
    
    //inQuad
    pos3B.x = xDestation;
    
    //inOutQuad
    pos4B.x = xDestation;
    
    //inQuint
    pos5B.x = xDestation;
    
    //outQuint
    pos6B.x = xDestation;
    
    //inOutQuint
    pos7B.x = xDestation;
    
    //inSine
    pos8B.x = xDestation;
    
    //outSine
    pos9B.x = xDestation;
    
    //inExpo
    pos10B.x = xDestation;


}

//--------------------------------------------------------------
void ofApp::update(){
    
    //linear
    if(pct1<1) pct1+=.0023;
    
    point0.x = (1-pct1)*pos0A.x+pct1*pos0B.x;
    
    //inOutSine
    float mPct1 = inOutSine(pct1);
    point1.x = (1-mPct1)*pos1A.x+mPct1*pos1B.x;
    
    //inQuad
    float nPct1 = inQuad(pct1);
    point2.x = (1-nPct1)*pos2A.x+nPct1*pos2B.x;
    
    //outQuad
    float oPct1 = outQuad(pct1);
    point3.x = (1-oPct1)*pos3A.x+oPct1*pos3B.x;
    
    //inOutQuad
    float pPct1 = inOutQuad(pct1);
    point4.x = (1-pPct1)*pos4A.x+pPct1*pos4B.x;
    
    //inQuint
    float qPct1 = inQuint(pct1);
    point5.x = (1-qPct1)*pos5A.x+qPct1*pos5B.x;
    
    //outQuint
    float rPct1 = outQuint(pct1);
    point6.x = (1-rPct1)*pos6A.x+rPct1*pos6B.x;
    
    //inOutQuint
    float sPct1 = inOutQuint(pct1);
    point7.x = (1-sPct1)*pos7A.x+sPct1*pos7B.x;
    
    //inSine
    float tPct1 = inSine(pct1);
    point8.x = (1-tPct1)*pos8A.x+tPct1*pos8B.x;
    
    //outSine
    float uPct1 = outSine(pct1);
    point9.x = (1-uPct1)*pos9A.x+uPct1*pos9B.x;
    
    //inExpo
    float vPct1 = inExpo(pct1);
    point10.x = (1-vPct1)*pos10A.x+vPct1*pos10B.x;
    
    
//    cout<<point0.x;
//    cout<<point1.x;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0);
    ofDrawRectangle(point0.x,100, 20, 20);
    ofDrawRectangle(point1.x,130, 20, 20);
    ofDrawRectangle(point2.x,160, 20, 20);
    ofDrawRectangle(point3.x,190, 20, 20);
    ofDrawRectangle(point4.x,220, 20, 20);
    ofDrawRectangle(point5.x,250, 20, 20);
    ofDrawRectangle(point6.x,280, 20, 20);
    ofDrawRectangle(point7.x,310, 20, 20);
    ofDrawRectangle(point8.x,340, 20, 20);
    ofDrawRectangle(point9.x,370, 20, 20);
    ofDrawRectangle(point10.x,400, 20, 20);

}



float ofApp::inOutSine(float t){
        return 0.5 * (1+sin(PI*(t-0.5)));
    }

float ofApp::inQuad(float t){
    return t * t;
}

float ofApp::outQuad(float t){
    return t * (2 - t);
}

float ofApp::inOutQuad(float t){
    return t < .5 ? 2 * t * t : -1 + (4 - 2 * t) * t;
}

float ofApp::inQuint(float t){
    return t * t * t * t * t;
}

float ofApp::outQuint(float t){
    return 1 + (--t) * t * t * t * t;
}

float ofApp::inOutQuint(float t){
    return t < .5 ? 16 * t * t * t * t * t : 1 + 16 * (--t) * t * t * t * t;
}

float ofApp::inSine(float t){
    return -1 * cos(t / 1 * (PI * 0.5)) + 1;
}

float ofApp::outSine(float t){
    return sin(t / 1 * (PI * 0.5));
}

float ofApp::inExpo(float t){
    return (t == 0) ? 0 : pow(2, 10 * (t - 1));
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
