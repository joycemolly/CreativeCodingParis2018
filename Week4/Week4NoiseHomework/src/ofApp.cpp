#include "ofApp.h"


//--------------------------------------------------------------

    
    void ofApp::setup(){
        
        ofSetVerticalSync(true);
        ofSetWindowShape(500, 500);
        ofSetWindowTitle("Vangogh");
        ofSetFrameRate(60);
        ofBackground(10, 10, 10);
        ofSetCylinderResolution(50, 4);
        ofSetConeResolution(50, 4);
        ofEnableDepthTest();
        
        Vangogh.load("van.png");
        
        offset.x = ofGetWidth()/2.0 - (Vangogh.getWidth()/2.0);
        offset.y = ofGetHeight()/2.0 - (Vangogh.getHeight()/2.0);
        size = 1;
        
        
        
        
    }
    





//--------------------------------------------------------------
void ofApp::update(){
    
    counter+=0.01;
    for(int i =0; i<particles.size(); i++){
        
        particles[i].update();
    }
    
//    float time = ofGetFrameRate();
//    for(auto & verts:line.getVertices()){
//        verts.x += ofSignedNoise(verts.x + time,verts.x + time, counter);
//        verts.y += ofSignedNoise(counter,verts.y + time);
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    for(int i=0; i <particles.size();i++){
        particles[i].draw();
    }
    
    
    ofLog()<<size;
    fbo.end();
    fbo.draw(80,80);
//
//    ofColor(100,100,100);
//    line.draw();
    
    
    
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key=='w'){
        size++;
        for(int i=0; i <particles.size();i++){
            particles[i].size = size;
        }
    }else if(key=='s'){
        size--;
        for(int i=0; i <particles.size();i++){
            particles[i].size = size;
        }
    }
    
    if(particles.size()==0 && key=='h') {
        
        
        for(int y=0; y<Vangogh.getHeight(); y+=size) {
            for(int x=0; x<Vangogh.getWidth(); x+=size) {
                ofPoint pos;
                pos.set(x*2, y*2);
                pos += offset;
                
                PixelParticle v;
                v.setup(pos, Vangogh.getColor(x, y), size);  //////???????
                particles.push_back(v);
                
                
                
            }
        }
    }
    
    if(key=='j') {
        
        particles.clear();
    }
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    
    ofPoint point;
    point.set(x, y);
    line.addVertex(point);
    
    

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
