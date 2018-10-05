#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(ofColor::ghostWhite);
    gui.setup();
    gui.add(freSlider.setup("Sin Freq",1,.25,10));



}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0; i<8000;i+=5){
        float sinValue = sin(ofGetElapsedTimef()+freSlider);
        float angle = ofDegToRad(i);
        float x = ofGetWidth()/2+(0.1f*i)*cos(angle);
        float y = ofGetHeight()/2+(0.1f*i)*sin(angle);
        ofSetColor(ofColor::lightCoral);
        ofDrawCircle(x, y, sinValue*(i*0.01));
    }
    gui.draw();
    
    
    


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
