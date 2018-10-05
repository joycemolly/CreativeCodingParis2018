#pragma once

#include "ofMain.h"
#include "Particle1.hpp"
#include "fish.hpp"
#include "biggerfish.hpp"




class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofPoint mouse;
        ofPoint pos;
        float radius;
        float counter;
    
        Particle1 p;
        vector<Particle1> particles;
    
        ofFbo fbo;
        ofColor color;
    
        vector<fish> fishes;
        vector<bigFish> bigFishes;
    
        int choices;



    
};
