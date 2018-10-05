//
//  lines.hpp
//  Week2 RotateGifHomework
//
//  Created by 郑晴 on 9/13/18.
//

#ifndef lines_hpp
#define lines_hpp

#include <stdio.h>
#include "ofMain.h"


class lines {
    
public:
    
    void setup();
    void update();
    void draw(float mPct);
    
    lines();
    float x;
    
    float mPct;
    
};


#endif /* lines_hpp */
