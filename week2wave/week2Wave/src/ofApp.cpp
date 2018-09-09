#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    

    
    gui.setup();
    gui.add(freSlider.setup("Sin Freq",1,.25,10));

    

    

}

//--------------------------------------------------------------
void ofApp::update(){
    
//    for(int i=0; i<numBoxX;i++){
//
//        for(int i=0; i<numBoxY;i++){
//
//            float x = i*boxSize
//        }
//
//
//
//
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    float sinValue = ofMap(sin(ofGetElapsedTimef()),-1,1,20,100);
//    ofLog() << sinValue;
//
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 20+sinValue);
    
    
//    for(int x =0;x<ofGetWidth();x+=50){
//        float cosValue = ofMap( cos( (freSlider*x*.01)*ofGetElapsedTimef()) ,-1, 1,0,20);
//
//        for(int y =0; y<ofGetHeight();y+=50){
//
//            float sinValue = ofMap( sin( (freSlider*y*.01)*ofGetElapsedTimef()) ,-1, 1,0,20);
//            ofDrawRectangle(x,y,sinValue, cosValue);
//        }
//
//    }
//
//    gui.draw();
    
    
    
    
//    for(int i =0; i <360;i+=30){
//        float angle = ofDegToRad(i);
//        float x =ofGetWidth()/2+(i*.5)*cos(angle);
//        float y =ofGetHeight()/2+(i*.5)*sin(angle);
//        ofDrawCircle(x, y, 20);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    float targetAngle = atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZRad(targetAngle);
    ofDrawRectangle(0, 0, 50, 50);
    ofPopMatrix();
    
    
    
    
    
    

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
