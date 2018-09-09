#pragma once

#include "ofMain.h"

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
    

    ofPoint point0;
    ofPoint pos0A;
    ofPoint pos0B;
    
    ofPoint point1;
    ofPoint pos1A;
    ofPoint pos1B;
    
    ofPoint point2;
    ofPoint pos2A;
    ofPoint pos2B;
    
    ofPoint point3;
    ofPoint pos3A;
    ofPoint pos3B;
    
    ofPoint point4;
    ofPoint pos4A;
    ofPoint pos4B;
    
    ofPoint point5;
    ofPoint pos5A;
    ofPoint pos5B;
    
    ofPoint point6;
    ofPoint pos6A;
    ofPoint pos6B;
    
    ofPoint point7;
    ofPoint pos7A;
    ofPoint pos7B;
    
    ofPoint point8;
    ofPoint pos8A;
    ofPoint pos8B;
    
    ofPoint point9;
    ofPoint pos9A;
    ofPoint pos9B;
    
    ofPoint point10;
    ofPoint pos10A;
    ofPoint pos10B;
    
    float pct1;
    float xDestation;
    
    float inOutSine (float t);
    float inQuad (float t);
    float outQuad (float t);
    float inOutQuad (float t);
    float inQuint (float t);
    float outQuint (float t);
    float inOutQuint (float t);
    float inSine (float t);
    float outSine (float t);
    float inExpo (float t);






    





    
		
};
