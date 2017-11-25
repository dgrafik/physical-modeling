#include "ofApp.h"
#include "iostream"

//--------------------------------------------------------------
float ofApp::resistance(int r, float v){
    float d = (-6) * 3.14 * r * v * 0.001;
    return d;
}

void ofApp::setup(){
    ofBackground(0, 0, 0); //czarne tło ładnie wygląda
    ofSetFrameRate(60); //max ?
    
    for (int i=0; i<N; i++) {
        ball[i].x = ofRandom(30, ofGetWidth()-30);
        ball[i].y = ofRandom(30, ofGetHeight()-30);
        ball[i].vx = ofRandom(-10,10);
        ball[i].vy = ofRandom(-10,10);
        ball[i].r = ofRandom(5,30);
        ball[i].m = ball[i].r/20;
        ball[i].R = ofRandom(0,255);
        ball[i].G = ofRandom(0,255);
        ball[i].B = ofRandom(0,255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<N; i++) {
        //przesuń
        if (!isOn){
            ball[i].vx = ball[i].vx + f/ball[i].m;
            ball[i].vy = ball[i].vy + g/ball[i].m;
            ball[i].x = ball[i].x + ball[i].vx * dt;
            ball[i].y = ball[i].y + ball[i].vy * dt;
        }else{
            float acceleration_x = resistance(ball[i].r, ball[i].vx) / ball[i].m;
            float acceleration_y = resistance(ball[i].r, ball[i].vy) / ball[i].m;
            ball[i].vx = ball[i].vx + (f/ball[i].m) + acceleration_x;
            ball[i].vy = ball[i].vy + (g/ball[i].m) + acceleration_y;
            ball[i].x = ball[i].x + ball[i].vx * dt;
            ball[i].y = ball[i].y + ball[i].vy * dt;
        }
        
        if (ball[i].x < ball[i].r) {
            ball[i].vx *= -1;
            ball[i].x = ball[i].r;
        }
        if(ball[i].x + ball[i].r > ofGetWidth()){
            ball[i].vx *= -1;
            ball[i].x = ofGetWidth() - ball[i].r;
        }
        
        if (ball[i].y < ball[i].r) {
            ball[i].vy *= -1;
            ball[i].y = ball[i].r;
        }
        if(ball[i].y + ball[i].r > ofGetHeight()){
            ball[i].vy *= -1;
            ball[i].y = ofGetHeight() - ball[i].r;
        }

    }
}

//-------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<N; i++) {
        ofSetColor(ball[i].R, ball[i].G, ball[i].B);
        ofDrawCircle(ball[i].x, ball[i].y, ball[i].r);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'o'){
        std::cout<<"Włączono opór!"<<std::endl;
        isOn = true;
        f = 0;
    }else if (key == 'f'){
        std::cout<<"Wyłączono opór!"<<std::endl;
        isOn = false;
        f = 2;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
