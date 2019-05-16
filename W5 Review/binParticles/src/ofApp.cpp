#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i = 0; i < 2000; i++){
        Particle p;
        particles.push_back(p);
        particles[i].setup( ofPoint(
                                    ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()) ), ofPoint(0,0,0) );
    }
    
    // init the bins (function in binner.cpp)
    setupBins(ofGetWidth(), ofGetHeight(), 15,15);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // compute bins
    for (int i = 0; i < particles.size(); i++){
        computeBinPosition( particles[i].pos.x, particles[i].pos.y,  &(particles[i].bitFlagW), &(particles[i].bitFlagH));
    }
    
    float particleDist = 20;
    
    for (int i = 0; i < particles.size(); i++){

        unsigned int bitFlagH_pta = particles[i].bitFlagH;
        unsigned int bitFlagW_pta = particles[i].bitFlagW;

        for (int j = 0; j < i; j++){

            unsigned int bitFlagH_ptb = particles[j].bitFlagH;
            unsigned int bitFlagW_ptb = particles[j].bitFlagW;

            if ((bitFlagW_pta & bitFlagW_ptb) && (bitFlagH_pta & bitFlagH_ptb)){
                particles[i].addRepulsion( particles[j].pos,particleDist,.25);
                particles[j].addRepulsion( particles[i].pos,particleDist,.25);
            }
        }
    }
    
    // old method:

//    for( int i = 0; i < particles.size(); i++){
//
//        for( int j = 0; j < i; j++){
//            particles[i].addRepulsion(particles[j].pos, particleDist, 0.25);
//            particles[j].addRepulsion(particles[i].pos, particleDist, 0.25);
//        }
//    }


    
    for (int i = 0; i < particles.size(); i++){
        particles[i].addAttraction( ofPoint(500,500),1500,0.0001);
        particles[i].addRepulsion( ofPoint(mouseX,mouseY),100,0.7);
        particles[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
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
