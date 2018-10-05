#pragma once
#include "ofMain.h"


class Particle1 : public ofBaseApp{
    
public:
    void setup(ofPoint _pos);
    void update();
    void draw();
    void grow();
    void interferece( ofPoint _pos);

    ofPoint pos;
    float radius;
    int color;
    
    float radius2;
    float counter;
    bool color1;
};
