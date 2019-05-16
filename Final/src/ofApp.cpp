#include "ofApp.h"
#include <iostream>
#include <string>
#include <algorithm>


int NorthScotland;
float NorthScotlandFuel[100];
int lastBarX =500;



//ofxFloatSlider num;
//ofxPanel gui;

int num;
int fuelNum;

vector<int> treeNum{13,22,20};
int n;
int cityNum;

vector<string> city;







//--------------------------------------------------------------
void ofApp::setup(){
    
    
    england.load("england.png");
    wales.load("wales.png");
    scotland.load("scotland.png");

    
    
    cityNum = 14;
    
    font.loadFont("fonts/Roboto-Medium.ttf", 40);
    font1.loadFont("fonts/Roboto-Medium.ttf", 10);

    city = {"England","Scotland","Wales"};

    n = 0;
    
    // load the 8 sfx soundfile
    for(int i=0; i<N_SOUNDS; i++) {
        sound[i].load("sfx/"+ofToString(i)+".wav");
        sound[i].setMultiPlay(true);
        sound[i].setLoop(false);
    }
    
    
    
    num = 15;
//    gui.setup();
//    gui.add(num.setup("num", 0, 0, 17));

//Send request
    

    // Testing redirects and https.
    // This server will echo back everything that you send to it.
    std::string url = "https://api.carbonintensity.org.uk/regional";
    
    // Create a client.
    ofxHTTP::Client client;
    
    // Create a request.
    ofxHTTP::GetRequest request(url);
    
    // Create a context.
    ofxHTTP::Context context;
    
    try
    {
        // Execute the request within the given context.
        auto response = client.execute(context, request);
        
        // Check the response.
        if (response->getStatus() == Poco::Net::HTTPResponse::HTTP_OK)
        {
            // A successful response.
//            ofLogNotice("ofApp::setup") << "Response success, expecting " << response->estimatedContentLength() << " bytes.";
            
            // Buffer the response, or otherwise consume the stream.
            ofBuffer buffer(response->stream());
            
//            ofLogNotice("ofApp::setup") << "Content Begin";
            
            std::cout << buffer << std::endl;
            
//            ofLogNotice("ofApp::setup") << "Content End";
            
            json << response->stream();
//            ofLog() << json["data"][0]["regions"][0]["intensity"]["forecast"];
//            ofLog() << json["data"][0]["regions"][1]["intensity"]["forecast"];
//            ofLog() << json["data"][0]["regions"][2]["intensity"]["forecast"];
//            ofLog() << json["data"][0]["regions"][3]["intensity"]["forecast"];
            
            NorthScotland = json["data"][0]["regions"][cityNum]["intensity"]["forecast"];
            
            // northScotlandFuel number
            for (int i = 0; i<9; i++)
            {
                NorthScotlandFuel[i] = json["data"][0]["regions"][cityNum]["generationmix"][i]["perc"];
//                ofLog() << NorthScotlandFuel[i];

            }
            

            

        }
        else
        {
            ofLogError("ofApp::setup") << response->getStatus() << " " << response->getReason();
        }
    }
    catch (const Poco::Exception& exc)
    {
        ofLogError("ofApp::setup") << exc.displayText();
    }
    catch (const std::exception& exc)
    {
        ofLogError("ofApp::setup") << exc.what();
    }


    
//ofxBox2DPhysics
    
    ofDisableAntiAliasing();
    ofSetVerticalSync(true);
    ofBackgroundHex(0xECEEEB);
    ofSetLogLevel(OF_LOG_NOTICE);
    
    box2d.init();
    box2d.enableEvents();
    box2d.setGravity(0, 10);
    //box2d.createBounds();
    box2d.setFPS(60.0);
    box2d.registerGrabbing();//select object and interact with them
    
    
    // bar
    
    
    for(int i=0; i<treeNum[n];i++) {
        auto r = std::make_shared<ofxBox2dRect>();
        r.get()->setPhysics(0, 0, 0);
        
        r.get()->setup(box2d.getWorld(), lastBarX, ofGetHeight()-50, 30, ofRandom(300,800));
//        r.get()->setup(box2d.getWorld(), lastBarX, ofGetHeight()-50, 30, 100 + NorthScotlandFuel[i]);
        r.get()->setData(new SoundData());
        SoundData * sd = (SoundData*)r.get()->getData();
//        sd->soundID = i;
        sd->bHit    = false;
        
        for( b2Fixture * f = r.get()->body->GetFixtureList(); f; f = f->GetNext() ){
            f->SetSensor(true);
        }
        lastBarX += NorthScotlandFuel[i]  + 20;
//        ofLog() << NorthScotlandFuel[i] << " " << lastBarX;
        Rects.push_back(r);
    }
//
//
//    for(int i=0; i<9; i++) {
//        auto r = std::make_shared<ofxBox2dRect>();
//        r.get()->setPhysics(0, 0, 0);
//
//        r.get()->setup(box2d.getWorld(), lastBarX, ofGetHeight()-50, 10, ofRandom(300,500));
//        //        r.get()->setup(box2d.getWorld(), lastBarX, ofGetHeight()-50, 30, 100 + NorthScotlandFuel[i]);
//        r.get()->setData(new SoundData());
//        SoundData * sd = (SoundData*)r.get()->getData();
//        sd->soundID = i;
//        sd->bHit    = false;
//
//        for( b2Fixture * f = r.get()->body->GetFixtureList(); f; f = f->GetNext() ){
//            f->SetSensor(true);
//        }
//        lastBarX += NorthScotlandFuel[i]  + 100;
//        //        ofLog() << NorthScotlandFuel[i] << " " << lastBarX;
//        Rects.push_back(r);
//    }
    
    
    // register the listener so that we get the events
    ofAddListener(box2d.contactStartEvents, this, &ofApp::contactStart);
    ofAddListener(box2d.contactEndEvents, this, &ofApp::contactEnd);
    
    
    
    //texture
    ofDirectory dir;
    ofDisableArbTex();
    int n = dir.listDir("textures");
    for (int i=0; i<n; i++) {
        textures.push_back(ofImage(dir.getPath(i)));
    }

    hit = false;

    
    }

//ContactListener:

void ofApp::contactStart(ofxBox2dContactArgs &e) {
    if(e.a != NULL && e.b != NULL) {
        
        // if we collide with the ground we do not
        // want to play a sound. this is how you do that
        if(e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_circle) {
            
        }
        
        
        else if( (e.a->GetType() == b2Shape::e_polygon && e.b->GetType() == b2Shape::e_polygon) ||
                (e.a->GetType() == b2Shape::e_polygon && e.b->GetType() == b2Shape::e_polygon)) {;
        
            if(e.a->IsSensor() || e.b->IsSensor() ){
//                ofLog() << "HIT SENSOR";
                SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
                SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
                
                if(aData) {
                    aData->bHit = true;
                    sound[aData->soundID].play();
                    
                }
                
                if(bData) {
                    bData->bHit = true;
                    sound[bData->soundID].play();
                }
                
                hit = true;
            }else{
                hit = false;

            }
            }
            
            
        }
        
        
    }
    
    


    


//--------------------------------------------------------------
void ofApp::contactEnd(ofxBox2dContactArgs &e) {
    if(e.a != NULL && e.b != NULL) {
        
        SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
        SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
        
        if(aData) {
            aData->bHit = false;
        }
        
        if(bData) {
            bData->bHit = false;
        }
    }
}




//--------------------------------------------------------------
void ofApp::update(){
    
    box2d.update();
    
    // add some circles every so often
//    if((int)ofRandom(0, (60-NorthScotland)) == 0) {
//        shared_ptr <ofxBox2dCircle> c = shared_ptr <ofxBox2dCircle>(new ofxBox2dCircle);
//        c.get()->setPhysics(1, 0.5, 0.9);
//        c.get()->setup(box2d.getWorld(), ofRandom(ofGetWidth()), -20, ofRandom(10, 20));
//
//        c.get()->setData(new SoundData());
//        SoundData * sd = (SoundData*)c.get()->getData();
//        sd->soundID = ofRandom(0, N_SOUNDS);
//        sd->bHit    = false;
//
//        circles.push_back(c);
//    }
    
//    if((int)ofRandom(0, 100) == 0) {
//        shared_ptr <ofxBox2dCircle> c = shared_ptr <ofxBox2dCircle>(new ofxBox2dCircle);
//        c.get()->setPhysics(1, 0.5, 0.9);
//        c.get()->setup(box2d.getWorld(), ofRandom(ofGetWidth()), -20, ofRandom(5, 20));
//
//        c.get()->setData(new SoundData());
//        SoundData * sd = (SoundData*)c.get()->getData();
//        sd->soundID = ofRandom(0, N_SOUNDS);
//        sd->bHit    = false;
//
//        circles2.push_back(c);
//    }
    
//    ofLog()<< NorthScotland;
    
    fuelNum=0;
    
    float fuel;
    fuel = ofMap(NorthScotland*(NorthScotlandFuel[fuelNum]/100), 0, 100, 80, 0);
    
    for(int i =0; i<9;i++){
    fuelNum =i;
    if((int)ofRandom(0,fuel) == 0) {
        shared_ptr <TextureShape> t = shared_ptr <TextureShape>(new TextureShape);


        shapes.push_back(t);
        shapes.back().get()->setTexture(&textures[(int)ofRandom(textures.size()-1)]);
        shapes.back().get()->setup(box2d, ofRandom(ofGetWidth()), ofRandom(-100,-5), (i+1)*3);

        
        

        
        t->polyShape.setData(new SoundData());
        SoundData * sd = (SoundData*)t->polyShape.getData();
        
            sd->soundID = i;
            sd->bHit    = false;
            ofLog()<< fuel;

        
        for( b2Fixture * f = t->polyShape.body->GetFixtureList(); f; f = f->GetNext() ){
            f->SetSensor(true);
            
            
            

            
            
        }

    }
    }
}
    





//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackgroundHex(0xF5E8C5);
//    england.draw(ofGetWidth()/2, ofGetHeight()/2, 300, 300);

    font.drawString(city[n], 20, 100);
    font1.drawString("Carbon Intensity:"+ ofToString(NorthScotland), 20, 150);
    font1.drawString( "Tree Coverage:"+ ofToString(treeNum[n]),20, 170);



//    gui.draw();

//    //drawMesh
//    ofSetColor(0);
//    sound1Mesh.draw();
//    sound2Mesh.draw();
    
    //drawCircle

//    for(size_t i=0; i<circles.size(); i++) {
//        ofFill();
//        SoundData * data = (SoundData*)circles[i].get()->getData();
//
//        if(data && data->bHit) ofSetHexColor(0xff0000);
//        else ofSetHexColor(0x4ccae9);
//
//
//        circles[i].get()->draw();
//    }
//
//    for(size_t i=0; i<circles2.size(); i++) {
//        ofFill();
//        SoundData * data = (SoundData*)circles2[i].get()->getData();
//
//        if(data && data->bHit) ofSetHexColor(0xff0000);
//        else ofSetHexColor(0xDD3333);
//
//
//        circles2[i].get()->draw();
//    }


    
    for (int i=0; i<Rects.size(); i++) {
        
        ofColor color;
        
        color.r = 40;
        color.g = i*70;
        color.b = i*69;
        
        SoundData * sd = (SoundData*)Rects[i].get()->getData();
        if(sd->bHit){

            color.r =i*200;
            color.g = i*200;
            color.b = i*200;
        }
        
        ofSetColor(color);
        ofFill();
        Rects[i].get()->draw();
        
        
        
    }
    


    for(int i=0; i<shapes.size(); i++) {
        
        SoundData * sd = (SoundData*)shapes[i]->polyShape.getData();
        
        
        if(sd->bHit){
            
//            shapes.back().get()->setTexture(&textures[7]);
        }
        
        shapes[i].get()->draw();
    }


}

void ofApp::barPushback(){
    

    
    for(int i=0; i<treeNum[n];i++) {
        auto r = std::make_shared<ofxBox2dRect>();
        r.get()->setPhysics(0, 0, 0);
        
        r.get()->setup(box2d.getWorld(), lastBarX, ofGetHeight()-50, 30, ofRandom(300,800));
        //        r.get()->setup(box2d.getWorld(), lastBarX, ofGetHeight()-50, 30, 100 + NorthScotlandFuel[i]);
        r.get()->setData(new SoundData());
        SoundData * sd = (SoundData*)r.get()->getData();
        //        sd->soundID = i;
        sd->bHit    = false;
        
        for( b2Fixture * f = r.get()->body->GetFixtureList(); f; f = f->GetNext() ){
            f->SetSensor(true);
        }
        lastBarX += NorthScotlandFuel[i]  + 20;
        //        ofLog() << NorthScotlandFuel[i] << " " << lastBarX;
        Rects.push_back(r);
    }
    
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    Rects.clear();
    shapes.clear();
//    ofLog()<<NorthScotlandFuel;
    
    if(key == '1'){
        
//        ofBackgroundHex(0xF5E8C5);
//        ofSetColor(255,255,255,10);
//        scotland.draw(ofGetWidth()/2, ofGetHeight()/2, 300, 300);

        lastBarX = 500;
        
        cityNum = 15;
       
        barPushback();
        
        fuelNum = 1;
        
        n=1;

        
    }
    if(key == '2'){
        
//        ofBackgroundHex(0xF5E8C5);
//        ofSetColor(255,255,255,10);
//        wales.draw(ofGetWidth()/2, ofGetHeight()/2, 300, 300);
        
        lastBarX = 500;

        cityNum = 16;
        
        barPushback();
        
        fuelNum = 2;
        
        n=2;
    }
    
    if(key == '3'){
        
//        ofBackgroundHex(0xF5E8C5);
//        ofSetColor(255,255,255,10);
//        england.draw(ofGetWidth()/2, ofGetHeight()/2, 300, 300);
        
        lastBarX = 500;
        
        cityNum = 14;
        
        barPushback();
        
        fuelNum = 0;
        
        n=0;
    }



        
    

    

    for (int i = 0; i<9; i++)
    {
        NorthScotlandFuel[i] = json["data"][0]["regions"][cityNum]["generationmix"][i]["perc"];
//    ofLog() << NorthScotlandFuel[i];
        
    }

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
    
//    shared_ptr <ofxBox2dCircle> c = shared_ptr <ofxBox2dCircle>(new ofxBox2dCircle);
//    c.get()->setPhysics(1, 0.5, 0.9);
//    c.get()->setup(box2d.getWorld(), x, y, ofRandom(20, 50));
//
//    c.get()->setData(new SoundData());
//    SoundData * sd = (SoundData*)c.get()->getData();
//    sd->soundID = ofRandom(0, N_SOUNDS);
//    sd->bHit    = false;
//
//    circles.push_back(c);
    
    
    shared_ptr <TextureShape> t = shared_ptr <TextureShape>(new TextureShape);



    shapes.push_back(t);
    shapes.back().get()->setTexture(&textures[(int)ofRandom(textures.size())]);
    shapes.back().get()->setup(box2d, ofRandom(ofGetWidth()), -20, ofRandom(10, 30));

    t->polyShape.setData(new SoundData());
    SoundData * sd = (SoundData*)t->polyShape.getData();
    sd->soundID = ofRandom(0, N_SOUNDS);
    sd->bHit    = false;

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
