#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Set vertices
    mesh.addVertex(ofVec3f(0,0,0));
    mesh.addVertex(ofVec3f(0,10,0));
    mesh.addVertex(ofVec3f(10,10,0));
    mesh.addVertex(ofVec3f(10,0,0));
    
    // Set triangle indices
    // 0 --------- 3
    // |           |
    // |           |
    // 1 --------- 2
    
    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(2);
    
    mesh.addIndex(0);
    mesh.addIndex(2);
    mesh.addIndex(3);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
        mesh.drawWireframe();
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
