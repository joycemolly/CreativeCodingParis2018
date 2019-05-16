#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    for(int i = 0; i < 100; i++){
        ofPoint p = ofPoint(i-50,0,0);
        pts.push_back(p);
    }
    
    ofSetBackgroundColor(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto & p: pts){
        p.y = ofSignedNoise(p.x*.01,ofGetElapsedTimef()*.1)*10;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    float thickness = 10;
    ofVec3f axis = ofVec3f(0,0,1);
    
    for(int i = 1; i < pts.size(); i++){
        
        ofVec3f thisPoint = pts[i-1];
        ofVec3f nextPoint = pts[i];
        
        ofVec3f dir = (nextPoint - thisPoint);
        dir = dir.getNormalized();
        
        ofVec3f sideA = dir.getRotated(-90, axis);
        ofVec3f sideB = dir.getRotated(90, axis);
        
        ofVec3f ptA = thisPoint+sideA*thickness;
        ofVec3f ptB = thisPoint+sideB*thickness;
        
        mesh.addVertex(ptA);
        mesh.addVertex(ptB);
        
    }
    
    cam.begin();
        mesh.draw();
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
