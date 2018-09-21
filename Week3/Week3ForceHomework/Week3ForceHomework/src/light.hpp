
#include "ofMain.h"
class Light{
    
public:
    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    
    void setup(float _x, float _y, ofPoint _pos);
    void update();
    void draw();
    
    float x;        // position
    float y;
    float speedY;   // speed and direction
    float speedX;
    int dim;        // size
    ofColor color;


    
};

