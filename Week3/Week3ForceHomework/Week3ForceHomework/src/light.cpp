#include "light.hpp"

void Light::setup(float _x, float _y,ofPoint _pos){
    
    pos = _pos;
//    x = ofRandom(0, ofGetWidth());      // give some random positioning
//    y = ofRandom(0, ofGetHeight());
    
    speedX = ofRandom(-1, 1);           // and random speed and direction
    speedY = ofRandom(-1, 1);
    
}

void Light::update(){
    
    if(pos.x < 0 ){
        pos.x = 0;
        speedX *= -1;
    } else if(pos.x > ofGetWidth()){
        pos.x = ofGetWidth();
        speedX *= -1;
    }
    
    if(pos.y < 0 ){
        pos.y = 0;
        speedY *= -1;
    } else if(pos.y > ofGetHeight()){
        pos.y = ofGetHeight();
        speedY *= -1;
    }
    
    pos.x+=speedX;
    pos.y+=speedY;

    
}

void Light::draw(){
    
    ofSetColor(220,ofRandom(100,150),0,50);
    ofDrawCircle(pos, 10);
    
    
}






