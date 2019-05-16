#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    int radius = 200;
    
    for(int i = 0; i < 360; i+=10){
        ofNode n;
        n.setPosition(radius*cos(ofDegToRad(i)), radius*sin(ofDegToRad(i)), 0);
        nodes.push_back( n );
    }
    
    bRotated = true;
    
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    for(auto & n : nodes){
        // calculate direction center
        ofVec3f toCenter = n.getPosition()-ofVec3f(0,0,0);
      
        // normalize
        toCenter.normalize();
        
        // make rotation
        ofQuaternion rotation;
        
        
        if(bRotated){
            ofVec3f axis(0, 0, 1);
            rotation.makeRotate(axis, toCenter);
            n.setOrientation(rotation);
        }else
            n.setOrientation(rotation);
        
        n.draw();
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    bRotated = !bRotated;
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
