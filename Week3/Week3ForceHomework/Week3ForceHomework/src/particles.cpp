//
//  particles.cpp
//  Week3ForceHomework
//
//  Created by 郑晴 on 9/18/18.
//

#include "particles.hpp"

Particle::Particle(){
    
    pos.set(0, 0);
    vel.set(0, 0);
    acc.set(0, 0);
    damp = .09;
}

void Particle::setup(ofPoint _pos, ofImage& flyImage){
    img = flyImage;
    pos = _pos;
    vel.set(ofRandom(-1,1), ofRandom(-1,1));
    
}

void Particle::update(){
    
    ofPoint mouse;
    mouse.set(ofGetMouseX(), ofGetMouseY());
    vel+=acc;
    pos+=vel;
    acc*=0;
    
    if(vel.x>7 || vel.y>7 || vel.x<-7 || vel.y<-7){
        
        vel*=damp;
        
    }
    if(pos.x>ofGetWidth()||pos.y>ofGetHeight()||pos.y<0||pos.x<0){
        vel*=-1;
    }
    
    ofLog()<<vel;
    
    angle =  atan2(pos.x - mouse.x, pos.y - mouse.y);

    
    counter +=1;
    
}

void Particle::draw(){
    
    //ofDrawCircle(pos, 20);
    ofPushMatrix();
//    ofTranslate(pos.x + ofNoise(counter,pos.x), pos.y+ofNoise(counter,pos.y));
    ofTranslate(pos.x , pos.y);
    ofRotate(ofRadToDeg(angle)-90);
    ofScale(0.08, 0.08);
    ofSetColor(255,255,255,50);
    
    img.draw(-img.getWidth()/2.0, -img.getHeight()/2.0);
    ofPopMatrix();
    //ofDrawLine(pos, ofPoint(pos.x+10,pos.y+10));
    
}

void Particle::addForce(ofPoint force){
    
    acc+=force;
    
}

void Particle::addRepulsionForce(ofPoint _pos,float _rad,float _scale){
    
    ofPoint diff;
    diff = _pos-pos;
    if(diff.length()<_rad){
        diff*=(diff.length()/_rad)-1;
        addForce(diff*_scale);
        
    }
}

void Particle::addAttractionForce(ofPoint _pos,float _rad,float scale){
    ofPoint diff = _pos-pos;//calaulate difference between my position and attractor position
    
    if(diff.length()<_rad){
        diff*=1-(diff.length()/_rad);//??
        //same as: acc+=diff*scale
        addForce(diff*scale);
    }
}



