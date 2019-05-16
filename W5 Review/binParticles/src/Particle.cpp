//
//  Particle.cpp
//  simpleParticles
//
//  Created by csugrue on 9/11/18.
//

#include "Particle.hpp"


Particle::Particle() {
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.8;
    radius = 10;
}

void Particle::setup(ofPoint _pos,ofPoint _vel){
    pos = _pos;
    vel = _vel;
    acc.set(0,0,0);
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::addRepulsion(ofPoint _pos, float _rad, float _scale){
    
    // calculate difference vector
    ofPoint diff = _pos - pos;
    
    // length of the vector is the distance
    if( diff.length() < _rad ){
        // calculate the direction vector first scale from 1 to 0 by dividing by the radius
        // then 1.0 - this value so that closer distances have a greate force
        diff *= 1.0 - (diff.length() / _rad);
        
        // scale and invert for repulsion
        addForce(-diff*_scale);
    }
}

void Particle::addAttraction(ofPoint _pos, float _rad, float _scale){
    ofPoint diff = _pos - pos;
    if( diff.length() < _rad ){
        diff *= 1.0-diff.length()/_rad;
        addForce(diff*_scale);
    }
}

void Particle::update() {
    
    // add acceleration to velocity
    vel += acc;
    // apply friction
    vel *= damp;
    // add velocity to the position
    pos += vel;
    // reset acceleration to 0
    acc *= 0.0;
    
    // bounce off sides
//    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
//        pos.x -= vel.x;
//        vel.x *= -1.0;
//    }
//    
//    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
//        pos.y -= vel.y;
//        vel.y *= -1.0;
//    }
}

void Particle::draw() {
    ofDrawCircle(pos, radius);
}
