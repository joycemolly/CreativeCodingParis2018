//
//  Particle.hpp
//  Week3Class
//
//  Created by 郑晴 on 9/14/18.
//

#pragma once
#include "ofMain.h"


class Particle{
    
public:
    Particle();
    
    void setup(ofPoint _pos);
    void update();
    void draw();
    void addForce(ofPoint force);
    //_pos:attractor position
    //_rad:distance from attractor
    //scale:how much force to apply
    void addAttractionForce(ofPoint _pos, float _rad, float scale);
    void addRepulsionForce(ofPoint _pos, float _rad, float scale);

    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float damp;
    
    ofPoint noiseRandomOffset;
    
    float counter;
    
    
    
    
};
