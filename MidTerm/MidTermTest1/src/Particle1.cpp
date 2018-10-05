#include "Particle1.hpp"

void Particle1::setup(ofPoint _pos){
    pos=_pos;
    radius =0;
    color = 0;
    ofEnableAlphaBlending();
    
    ofSetCircleResolution(60);
    color1 = false;

    
}

void Particle1::update(){
    

    counter++;
    radius++;

    if(radius>50){
        radius = 50;
    }
    


    if(color1 == false){

    color = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 255);
    }

    if(color == 0){
        color1 = true;

    }
//    ofLog()<< color;

    
}


void Particle1::draw(){
    
//    radius =  _radius;

    float noiseIndex;
    noiseIndex = ofNoise(ofGetElapsedTimef());
    float _noiseIndex = ofMap(noiseIndex, 0, 1, 0, 255);
    
    ofNoFill();
    ofSetColor(50,_noiseIndex,_noiseIndex,color);
    ofDrawCircle(pos,radius);
    if(color > 100){
        grow();
    };
    
//    ofLog()<<_noiseIndex;
}

void Particle1::grow(){

    for(int i; i<20;i++){
        ofDrawCircle(pos, radius*i);

//            ofDrawCircle(pos.x+60*i,pos.y,radius2);
//            ofDrawCircle(pos.x-60*i,pos.y,radius2);
//            ofDrawCircle(pos.x,pos.y-60*i,radius2);
//            ofDrawCircle(pos.x,pos.y+60*i,radius2);
        

    }

}

void Particle1::interferece( ofPoint _pos){
    pos = _pos;
    for(int i; i<10;i++){
        ofDrawCircle(pos, radius*i);
}
}

