//
//  lines2.cpp
//  Week2 RotateGifHomework
//
//  Created by 郑晴 on 9/13/18.
//

#include "lines2.hpp"
#include "ofMain.h"

lines2::lines2(){
    
}

void lines2::setup(){
    
    x = ofGetWidth();
    
    
    
}

void lines2::update(){
    
    
    
}

void lines2::draw(float mPct){
    
    x = (1-mPct)*x + mPct*ofGetMouseX();
    
    for(int i=0; i <ofGetHeight();i+=10){
        
        ofDrawCircle(x+i*0.5, i, 1);
        
    }
}
