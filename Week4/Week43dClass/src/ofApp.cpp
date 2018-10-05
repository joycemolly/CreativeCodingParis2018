#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    model.loadModel("dodeca.obj");
    baseNoise.set(0,0,0);
    light.setPosition(200, 500, 1000);

}

//--------------------------------------------------------------
void ofApp::update(){
    baseNoise += ofPoint(.1,.1,.1);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();//important draw the face inside
    //access the mesh inside the model
    ofMesh mesh = model.getMesh(0);
    ofPoint center = mesh.getCentroid();
    //update all the verticles
    auto & verts = mesh.getVertices();
    
    for(int i =0; i< verts.size();i++){
        ofPoint diff = center -verts[i];
        diff = diff.normalize();
        
        //expand with sin
//        verts[i].x +=1*diff.x*sin(ofGetElapsedTimef());
//        verts[i].y +=1*diff.y*sin(ofGetElapsedTimef());
//        verts[i].z +=1*diff.z*sin(ofGetElapsedTimef());

        //instead use noise
        verts[i].x += diff.x*2* ofSignedNoise(verts[i].x+baseNoise.x/15, verts[i].y/15+baseNoise.y);
        verts[i].y += diff.x*2* ofSignedNoise(verts[i].y+baseNoise.y/15, verts[i].z/15+baseNoise.z);
        verts[i].z += diff.x*2* ofSignedNoise(verts[i].z+baseNoise.z/15, verts[i].x/15+baseNoise.x);
        

    }
    
    
    light.enable();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2,0);
    ofScale(model.getNormalizedScale());
    ofTranslate(0,-15, 0);
//    model.drawFaces();
    mesh.drawFaces();
//    model.drawWireframe();
    ofPopMatrix();


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
