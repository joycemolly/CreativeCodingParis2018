//
//  fish.cpp
//  MidTermTest1
//
//  Created by 郑晴 on 10/4/18.
//

#include "fish.hpp"
void fish::setup(ofPoint _pos){
    pos = _pos;
//    pos=ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    counter.x = 0;
    counter.y = 0.5;

}

void fish::update(){
    
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;


    counter.x+=0.005f;
    counter.y+=0.005f;

    noiseIndex = ofNoise(counter.x);
    noiseIndey = ofNoise(counter.y);

    noise.x= ofMap(noiseIndex, 0, 1, -700, 700);
    noise.y= ofMap(noiseIndey, 0, 1, -700, 700);

    if(pos.x>ofGetWidth()||pos.y>ofGetWidth()||pos.x<0||pos.y<0){
        vel*=-1;
    }
    finalPos = pos + noise;
//    ofLog()<<pos;

}

void fish::draw(){
    ofDrawCircle(finalPos, 10);
    ofDrawCircle(finalPos, 5);

}

