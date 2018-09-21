//
//  lines2.hpp
//  Week2 RotateGifHomework
//
//  Created by 郑晴 on 9/13/18.
//

#ifndef lines2_hpp
#define lines2_hpp
#include "ofMain.h"
#include <stdio.h>

class lines2 {
    
public:
    
    void setup();
    void update();
    void draw(float mPct);
    
    lines2();
    float x;
    
    float mPct;
    
};
#endif /* lines2_hpp */
