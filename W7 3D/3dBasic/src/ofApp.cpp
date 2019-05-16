#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    light.setPosition(0, 10, 10);
    light.enable();
    
    cam.setDistance(50);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofEnableDepthTest();
    cam.begin();
    
    ofPushMatrix();
        ofRotateZDeg(90);
        ofDrawGridPlane();
    ofPopMatrix();
    
    ofEnableLighting();
        ofDrawBox(0,0,0,4);
    ofDisableLighting();
    
    cam.end();
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
