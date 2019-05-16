#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    cam.setPosition(0,0,200);

    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    cam.orbitDeg(ofGetElapsedTimef()*2, 0, 200, ofVec3f(0, 100,0));
    cam.tiltDeg(-20);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofNode node;
    node.setPosition( 0,0,0);

    ofEnableDepthTest();
    cam.begin();
    
    node.draw();
    
    ofPushMatrix();
    ofRotateZDeg(90);
    ofDrawGridPlane(30);
    ofPopMatrix();
    
    
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
