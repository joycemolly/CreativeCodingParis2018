//
//  Particle.hpp
//  simpleParticles
//
//  Created by csugrue on 9/11/18.
//

#pragma once
#include "ofMain.h"


class Particle {
public:
    Particle();
    
    void setup(ofPoint _pos,ofPoint _vel);
    void addForce(ofPoint _force);
    
    void addRepulsion(ofPoint _pos, float _rad, float _scale);
    void addAttraction(ofPoint _pos, float _rad, float _scale);
    
    void update();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    float radius;
    float damp;
    
    unsigned int bitFlagW;
    unsigned int bitFlagH;
    
};
