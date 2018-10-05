#include "ofApp.h"
#include "lines.hpp"
#include "lines2.hpp"



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(50);
    counter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    color.r = mouseX;
    color.g = mouseY;
    color.b = mouseY;
    
    counter+= 1;
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    float targetAngle = atan2(mouseY-ofGetHeight()/2, mouseX-ofGetWidth()/2);
    float targetAngle2 = atan2(ofGetHeight()/2-mouseY, ofGetWidth()/2-mouseX);
    
    for(int x=0;x<ofGetWidth()/2;x+=60){

        for(int y =0;y<ofGetHeight()/2;y+=60){
            ofPushMatrix();
            ofTranslate(x+ofGetWidth()/2-200,y+ofGetHeight()/2-200);
            ofRotateZRad(targetAngle);
            ofSetColor(color);
            ofDrawRectangle(x+ofNoise(counter), y, x*.1, y*.1);
            ofPopMatrix();

        }

    }
    
        for(int x=0;x<ofGetWidth()/2;x+=60){
            
            for(int y =0;y<ofGetHeight()/2;y+=60){
            ofPushMatrix();
            ofTranslate(x+ofGetWidth()/2-100,y+ofGetHeight()/2-100);
            ofRotateZRad(targetAngle2);
            ofDrawRectangle(x, y, x*.1, y*.1);
            ofPopMatrix();

        }

    }
    
//    ofLog()<<mouseX;
    
//    lines.draw(0.02);
//    lines2.draw(0.5);
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
