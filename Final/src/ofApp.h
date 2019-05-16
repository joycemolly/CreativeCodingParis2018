#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxHTTP.h"
#include "ofxGui.h"
#include "TextureShape.h"




#define N_SOUNDS 9


class SoundData {
public:
    int  soundID;
    bool bHit;
};


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
        void barPushback();

    
    
    
    
    ofxBox2d                               box2d;   // the box2d world
    vector   <shared_ptr<ofxBox2dCircle> > circles; // default box2d circles
    vector   <shared_ptr<ofxBox2dCircle> > circles2; // default box2d circles
    
    vector <shared_ptr<ofxBox2dRect>> Rects;

    


    
    ofxBox2dCircle                         sound1;
    ofxBox2dCircle                         sound2;
    
    
    
    //sound
    ofSoundPlayer mySound;
    ofSoundPlayer  sound[N_SOUNDS];





    
    //listener
    void contactStart(ofxBox2dContactArgs &e);
    void contactEnd(ofxBox2dContactArgs &e);
    
//    ofxJSONElement json;
    
    //texture
    
    ofJson json;
    
    vector <ofImage> textures;
    vector <shared_ptr<TextureShape> > shapes;
    
    bool hit;
    

    ofTrueTypeFont font;
    ofTrueTypeFont font1;
    
    ofImage england;
    ofImage scotland;
    ofImage wales;




    
    




		
};
