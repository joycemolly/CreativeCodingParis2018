#pragma once
#include "ofMain.h"


class PixelParticle{
public:
    void setup(ofPoint _pos, ofColor _color, float _size);
    void update();
    void draw();
    bool isDone();
    
    float size;
    ofColor color;
    ofPoint homePos;
    ofPoint noiseOffset;
    ofPoint vel;
    ofPoint acc;
    
    float xNoiseIndex;
    float yNoiseIndex;
    
};
