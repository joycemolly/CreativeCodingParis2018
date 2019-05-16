#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for(int i = 0; i < 100; i++){
        pts.push_back(ofPoint(ofRandom(-10,10),ofRandom(-10,10),ofRandom(-10,10)));
    }
    cam.setPosition(0,0,20);
    
    lookAtMe = ofRandom(0,pts.size()-1);
    cam.lookAt(pts[lookAtMe]);
    
    light.setPosition(0, 10, 10);
    light.enable();
    node.setPosition(0, 10, 10);
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef()*.01;
    ofPoint p(0,0,0);
    ofVec3f pos = node.getPosition();
    p.x += ofSignedNoise( time, pos.x*.01 );
    p.y += ofSignedNoise( time, pos.y*.01 );
    p.z += ofSignedNoise(pos.z*.01,time);
    node.setPosition(p*10);
    cam.lookAt(node);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    ofBoxPrimitive box;
    box.set( 1 );
    
    cam.begin();
    //node.draw();
    for(int i = 0; i < pts.size();i++){
        if(i==lookAtMe){
            ofSetColor(255, 0, 0);
        }else{
            ofSetColor(255);
        }
        box.setPosition(pts[i]);
        box.setScale(1);
        box.draw();
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    lookAtMe= ofRandom(0,pts.size()-1);
    cam.lookAt(pts[lookAtMe]);
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
