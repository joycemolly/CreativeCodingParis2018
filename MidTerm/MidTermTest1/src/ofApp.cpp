#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    
//    for(int i =0; i<50;i++){
//    p.setup();
//    particles.push_back(p);
//    }
    
//    radius = 0;
    
    counter = 0;
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    color.set(0);
    ofSetFrameRate(60);
    

    

    


}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i =0; i <particles.size();i++){
    particles[i].update();
    }
    

    
        for(int i =0; i <bigFishes.size();i++){
            for(int j =0; j < fishes.size();j++){
                bigFishes[i].update(fishes[j].finalPos);
            }
        }
        
    
    
    
        for(int i =0; i <fishes.size();i++){
            fishes[i].update();
        }
    
    
//    ofLog()<<choices;
    
    
        

    
    
        
    }



//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    ofSetColor(0,0,0,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for(int i =0; i <particles.size();i++){
        ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
        particles[i].draw();
    }
    
//    ofLog()<<radius;
    
//    for(int i =0; i <particles.size();i++){
//        for(int j =0; j <particles.size();j++){
//            float dist = (particles[i].pos-particles[j].pos).length();
//            if(dist<50){
//                ofDrawCircle((particles[i].pos+particles[j].pos)/2, 10);
////                particles[i].interferece(ofPoint((particles[i].pos.x+particles[j].pos.x)/2,
////                                         (particles[i].pos.x+particles[j].pos.x)/2));
//            }
//
//        }
//
//
//    }
    ofSetColor(155,100,200,200);
    for(int i =0; i <fishes.size();i++){
        fishes[i].draw();
    }
    
    ofSetColor(155,200,100,200);
    for(int i =0; i <bigFishes.size();i++){
        bigFishes[i].draw();
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
    
    for (int i=0 ; i<1 ; i++){
    Particle1 p;
    particles.push_back(p);
    particles[ particles.size() -1].setup(ofPoint(x,y));
        
        if(choices ==0){
        fish f;
        fishes.push_back(f);
        fishes[ fishes.size() -1].setup(ofPoint(x,y));
        }
        if(choices ==1){
        bigFish bf;
        bigFishes.push_back(bf);
        bigFishes[ bigFishes.size() -1].setup(ofPoint(x,y));
        }
        
    }
    
    choices = ofRandom(2);
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
