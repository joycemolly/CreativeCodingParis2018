//
//  fish.cpp
//  MidTermTest1
//
//  Created by 郑晴 on 10/4/18.
//

#include "babyFish.hpp"
void babyFish::setup(ofPoint _pos){
    pos = _pos;

    
    
}

void babyFish::update(){
    acc+=ofPoint(ofRandom(-10,10)),ofPoint(ofRandom(-10,10));
    vel+=acc;
    pos+=vel;
    acc*=0;
    
    
    

    
}

void babyFish::draw(){
    ofSetColor(255);
    ofDrawCircle(pos, 10);
}


