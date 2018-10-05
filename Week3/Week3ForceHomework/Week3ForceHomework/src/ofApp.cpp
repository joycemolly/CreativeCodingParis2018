#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    flyImage.load("noun_Moth_1138135.png");

    
    for(int i =0; i<400; i++){
    Particle p;
    p.setup(ofPoint(ofRandom(ofGetWidth()),
                    ofRandom(ofGetHeight())),flyImage);
        particles.push_back(p);
        
        

    }
    



}

//--------------------------------------------------------------
void ofApp::update(){
    
    mouse = ofPoint(mouseX,mouseY);

    
    
    for(int i =0; i<particles.size();i++){
        
//        particles[i].addForce(ofPoint(0,0.01));
        particles[i].addRepulsionForce(mouse, 100, .5);

        particles[i].update();
        
        
        
    }
    
    for(int i =0; i<particles.size();i++){
        for(int j =0;j<i;j++){
            particles[i].addRepulsionForce(particles[j].pos, 35, .1);
            particles[j].addRepulsionForce(particles[i].pos, 35, .1);
        }
    }
    
//    angle = ofRandom(30,50);


    for (int i = 0; i<light.size(); i++) {
        light[i].update();
    }
    
    
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    
    for(int i =0;i<particles.size();i++){
        

        particles[i].draw();
 
        
    }
    
    



//    ofDrawCircle(mouse.x, mouse.y, 50);

    ofSetColor(255,100,0,100);
//    ofDrawCircle(mouse, d);
    
    for (int i = 0 ; i<light.size(); i++) {
        light[i].draw();
    }


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
    
//    ofDrawCircle(mouse.x, mouse.y, 50);

    for(int i =0; i<particles.size();i++){
        ofPoint mouse = ofPoint(mouseX,mouseY);
        particles[i].addAttractionForce(mouse, 500, 0.08);
        
    }
    
    
    d++;
    if(d>100){
        d=100;
    };
    
    
            Light l;
            l.setup(x,y,mouse);
            light.push_back(l);
    

    
    
    
    

    
    }

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    

    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    d = 0;
    light.clear();


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
