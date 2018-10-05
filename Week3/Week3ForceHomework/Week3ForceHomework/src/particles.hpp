#include "ofMain.h"

class Particle{
    
public:
    
    Particle();
    void setup(ofPoint _pos,ofImage& flyImage);
    void update();
    void draw();
    void addForce(ofPoint force);
    void addRepulsionForce(ofPoint _pos,float _rad,float _scale);
    void addAttractionForce(ofPoint _pos,float _rad,float _scale);


    
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    float damp;
    
    ofImage img;
    float angle;
    
    float counter;



};
