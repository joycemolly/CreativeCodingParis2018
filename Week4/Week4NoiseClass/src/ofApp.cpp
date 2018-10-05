#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    counter = 0;
    fbo.allocate(ofGetWidth(),ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::update(){
    counter +=0.01;//increment counter to move through noise
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    ofSetColor(0,0,0,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255);
    for(int i =0;i<100;i++){
    float x =ofNoise(counter,i*0.005)*ofGetWidth();
    float y =ofNoise(i*0.005,counter)*ofGetHeight();
    ofDrawCircle(x, y, 4);
    }
    fbo.end();
    fbo.draw(0,0);
    
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
