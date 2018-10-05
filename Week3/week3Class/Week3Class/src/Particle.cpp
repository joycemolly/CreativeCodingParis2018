//
//  Particle.cpp
//  Week3Class
//
//  Created by 郑晴 on 9/14/18.
//

#include "Particle.hpp"


Particle::Particle(){
    
    pos.set(0,0,0);
    vel.set(0,0,0);
    acc.set(0,0,0);
    damp =.9;
    
}

void Particle::setup( ofPoint _pos){
    
    pos =_pos;
    vel.set(ofRandom(-1,1),ofRandom(-1,1));
    
    noiseRandomOffset.set(ofRandom(10),ofRandom(10),ofRandom(10));


    
}

void Particle::update(){
    
    counter +=0.1;
    float x =ofNoise(counter, counter);
    float y =ofNoise(counter, counter);

    
    vel+=acc;
    vel*=damp;//decrease vel over time with "friction"
    pos+=vel;
    acc*=0.0;
    
   
    
}
void Particle::draw(){
    
    ofDrawCircle(pos.x,pos.y,10);
    ofLog() << pos;
    
}

void Particle::addForce(ofPoint force){
    acc+=force;
    
}

void Particle::addAttractionForce(ofPoint _pos,float _rad,float scale){
    ofPoint diff = _pos-pos;//calaulate difference between my position and attractor position
    
    if(diff.length()<_rad){
        diff*=1.0 -(diff.length()/_rad);
        //same as: acc+=diff*scale
        addForce(diff*scale);
    }
    
}

void Particle::addRepulsionForce(ofPoint _pos,float _rad,float scale){
    ofPoint diff = _pos-pos;//calaulate difference between my position and attractor position
    
    if(diff.length()<_rad){
        diff*=(diff.length()/_rad)-1;//??
        //same as: acc+=diff*scale
        addForce(diff*scale);
    }
    
}


    



