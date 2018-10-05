//
//  fish.cpp
//  MidTermTest1
//
//  Created by 郑晴 on 10/4/18.
//

#include "biggerFish.hpp"
void bigFish::setup(ofPoint _pos){
    pos = _pos;
    //    pos=ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    counter.x = 0.4;
    counter.y = 0.2;
    
    r = 20;
    color.set(100,100,0);
    

    

}


void bigFish::update(ofPoint _pos){
    
//    p = _pos;
    if(r > 20){
        
        r -= .1;
    }
    
    center.x = ofGetWidth()/2;
    center.y = ofGetHeight()/2;
    
    
    counter.x+=0.002f;
    counter.y+=0.002f;
    
    noiseIndex = ofNoise(counter.x);
    noiseIndey = ofNoise(counter.y);
    
    noise.x= ofMap(noiseIndex, 0, 1, -700, 700);
    noise.y= ofMap(noiseIndey, 0, 1, -700, 700);
    
    for(int i =0; i <moreFishes.size();i++){
        moreFishes[i].update();
    }
    
    if(pos.x>ofGetWidth()||pos.y>ofGetWidth()||pos.x<0||pos.y<0){
        vel*=-1;
    }
    
    
    float dis = ((pos+noise)-_pos).length();//////// the distance
    if(dis<100){
        
        r = 80;
//        r = sin(ofGetFrameRate()*10);
        ofLog()<< "eat";
        color.set(255,100,0);
        
        

        
        
        
    }else{
        ofLog()<< "not eat";
//        r = 40;
        //r = 10;
        color.set(100,100,0);

    }
}
void bigFish::draw(){
    
    ofDrawCircle(pos+noise,10);
    ofSetColor(color);
    ofDrawCircle(pos+noise, r);
//    ofDrawCircle(pos+noise, 20);

    
    

}




