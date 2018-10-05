#pragma once
#include "ofMain.h"
#include "fish.hpp"
#include "babyFish.hpp"




class bigFish : public ofBaseApp{
    
public:
    void setup(ofPoint _pos);
    void update(ofPoint _pos);
//    void update(vector<fish> fishes);
    void draw();
    void grow();

    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    float noiseIndex;
    float noiseIndey;
    
    ofPoint noise;
    
    ofPoint counter;
    ofPoint center;
   
    ofPoint p;
    float r;
    
    vector<fish> moreFishes;
    fish f;
    
    ofColor color;
    bool eat = false;

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};

