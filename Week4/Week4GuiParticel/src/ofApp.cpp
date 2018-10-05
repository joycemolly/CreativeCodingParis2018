#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofPoint spawnSize = ofPoint(30,30,30);
    
    for(int i =0;i<1000;i++){
        Particle p;
        
        p.setup(ofPoint(
                ofRandom(-spawnSize.x,spawnSize.x),
                ofRandom(-spawnSize.y,spawnSize.y),
                ofRandom(-spawnSize.z,spawnSize.z)
                        ));
        particles.push_back(p);
    }
    
    
    gui.setup("Particles");
    gui.add(spaceFrequecy.set("spaceFrequecy", .1f, 0.0001f,1.0f));
    gui.add(timeFrequecy.set("TimeFrequecy", .1f, 0.0001f,2.0f));
    gui.add(noiseMagnetic.set("noiseMagnetic", .1f, 0.0001f,1.0f));


}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef()* timeFrequecy;
    
    for(int i =0; i < particles.size();i++){
        
        ofPoint noiseReadPos = (particles[i].pos+particles[i].noiseRandomOffset)*spaceFrequecy;
        
        ofPoint forceP(0,0,0);
        forceP.x+= ofSignedNoise(noiseReadPos.x,noiseReadPos.y,time);
        forceP.y+= ofSignedNoise(noiseReadPos.y,time,noiseReadPos.z);
        forceP.z+= ofSignedNoise(time,noiseReadPos.z,noiseReadPos.x);

        particles[i].addAttractionForce(ofPoint(0,0,0), 100,0.015);
        particles[i].addForce(forceP*noiseMagnetic);
        
        particles[i].update();
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofMesh mesh;
    //add each particle as a vertex;
    
    for(int i =0; i<particles.size();i++){
    mesh.addColor(ofColor(255));
    mesh.addVertex(particles[i].pos);
    
    
    ofEnableDepthTest();
    
    camera.begin();
    ofPushMatrix();
    mesh.drawVertices();
    ofPopMatrix();
    camera.end();
        
    }
    
    ofDisableDepthTest();
    gui.draw();

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
