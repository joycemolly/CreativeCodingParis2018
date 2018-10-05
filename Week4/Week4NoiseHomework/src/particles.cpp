//
//  particles.cpp
//  Week4NoiseHomework
//
//  Created by 郑晴 on 9/28/18.
//

#include "particles.hpp"

void PixelParticle::setup( ofPoint _pos, ofColor _color, float _size){
    homePos = _pos;
    size = _size;
    color = _color;
    vel.x = ofRandom(-200, 200);
    vel.y = ofRandom(-500, -200);
    
    xNoiseIndex = ofRandomf();///////????????
    yNoiseIndex = ofRandomf();//////?????????
}

void PixelParticle::update(){
    //    acc.y = 9.8; // acclerate 9.8 pixels per second
    //    vel += acc;
    //    pos += vel * deltaTime;
    //    acc.set(0, 0);
    
    //float nx = ofNoise(ofRandom(0.1));
    //float ny = ofNoise(ofRandom(0.1));
    
    xNoiseIndex += 0.01;
    yNoiseIndex += 0.02;
    
    noiseOffset.x = ofNoise(xNoiseIndex)*100 ;
    noiseOffset.y = ofNoise(yNoiseIndex) *100;
    
    
    
    
    //    pos.x = ofMap(nx, 0, 1, (ofGetWidth()/2.0)-pos.x-5,  (ofGetWidth()/2.0)-pos.x+5);
    //    pos.y = ofMap(ny, 0, 1, (ofGetHeight()/2.0)-pos.y-5,  (ofGetHeight()/2.0)-pos.y+5);
    
    
}

void PixelParticle::draw(){
    ofSetColor(color);
    ofDrawRectangle(homePos+noiseOffset, size, size);
}



