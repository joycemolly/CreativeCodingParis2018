//
//  lines.cpp
//  Week2 RotateGifHomework
//
//  Created by 郑晴 on 9/13/18.
//

#include "lines.hpp"
#include "ofMain.h"

lines::lines(){
    
}

void lines::setup(){
    
    x = ofGetWidth();
    
    
    
}

void lines::update(){
    
    
    
}

void lines::draw(float mPct){
    
    x = (1-mPct)*x + mPct*ofGetMouseX();
    
    for(int i=0; i <ofGetHeight();i+=10){
        
        ofDrawCircle(x+i*0.5, i, 1);
        
    }


    
}
