#pragma once
#include "ofMain.h"


class fish : public ofBaseApp{
    
public:
    void setup(ofPoint _pos);
    void update();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    float noiseIndex;
    float noiseIndey;
    
    ofPoint noise;
    
    ofPoint counter;
    ofPoint center;

    ofPoint finalPos;


    

    
    

    
    
    

    
    
    
};
