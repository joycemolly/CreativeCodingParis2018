#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    int bufferSize = 512;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    smoothedVol     = 0.0;
    scaledVol        = 0.0;
    ofSoundStreamSettings settings;
    auto devices = soundStream.getMatchingDevices("default");
    if(!devices.empty()){
        settings.setInDevice(devices[0]);
    }
    settings.setInListener(this);
    settings.sampleRate = 44100;
    settings.numOutputChannels = 0;
    settings.numInputChannels = 2;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    

    // setup visuals
    float sphereRadius = 200;
    
    for( int i = 0; i < bufferSize; i++){
        
        // get random postions on a sphere
        float theta1=ofRandom(0, TWO_PI);
        float theta2=ofRandom(0, TWO_PI);
        
        // store normalized vectors of 3d position on sphere
        ofVec3f p;
        p.x = cos( theta1 ) * cos( theta2 );
        p.y = sin( theta1 );
        p.z = cos( theta1 ) * sin( theta2 ) ;
        
        dirs.push_back(p);
        
        // store origin and extended points on sphere
        ofVec3f op = dirs[i] * (sphereRadius+i/100.0);
        orig_pts.push_back( op );
        pts.push_back( op  );
    }
    
    
    glowImg.loadImage("dot.png");
    
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){
    


    // change the distance of each point from its origin based on left and right channel audio input
    for( int i = 0; i < pts.size(); i++){
        
        ofVec3f p;
        
        // flip flop use of left or right for odd/even i values
        if(i%2 == 0){
            float scaledLeftVal = 1 + ( 200*left[i] ) ;
//            ofLog() << scaledLeftVal;
            p = orig_pts[i] * scaledLeftVal;
        }else{
            float scaledRVal = 1 + ( 200*right[i] );
            p = orig_pts[i] * scaledRVal;
        }
        
        // create blend towards new value for smoother animation
        pts[i] = .99 * pts[i] + .01 * p;
        
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // background gradient needs to be called in the draw
    // unlike ofBackground that can be called in setup
    ofBackgroundGradient(ofColor(175,252,242),ofColor(0,16,27),  OF_GRADIENT_BAR);
    
    // calculate radius of glow using the volume calculation
    // scale the vol up to a 0-1 range, adjust this as needed based on volume levels in room
    scaledVol = ofMap(smoothedVol, 0.0, 0.017, 0.0, 1.0, true);
    float radius = ofMap(scaledVol,0,1,10,200);
    
    
    float rotationAmount;
    ofVec3f rotationAngle;
    ofQuaternion rotation;
    
    glDepthMask(false);
    ofEnableDepthTest();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    cam.begin();
    
    ofPushMatrix();
    for( int i = 0; i < pts.size(); i++){
        
        // draw lines between origin and expanded point
        ofSetColor(255, 100);
        ofDrawLine(orig_pts[i].x,orig_pts[i].y,orig_pts[i].z,pts[i].x,pts[i].y,pts[i].z);
        
        ofSetColor(255, 100, 90);
        
        // draw glow images rotated towards center of sphere
        ofPushMatrix();
        
        ofTranslate(pts[i]);
        
        // find rotation
        ofVec3f normal = (pts[i]-orig_pts[i]).normalize();
        ofVec3f axis(0, 0, 1);
        rotation.makeRotate(axis, normal);
        rotation.getRotate(rotationAmount, rotationAngle);
        
        ofRotateDeg(rotationAmount, rotationAngle.x, rotationAngle.y, rotationAngle.z);
        glowImg.draw(0,0,radius,radius);
        
        ofPopMatrix();
    }
    ofPopMatrix();
    
    cam.end();
    ofDisableBlendMode();
    
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer & input){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (size_t i = 0; i < input.getNumFrames(); i++){
        left[i]        = input[i*2]*0.5;
        right[i]    = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
