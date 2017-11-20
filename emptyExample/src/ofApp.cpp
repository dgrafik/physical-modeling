#include "ofApp.h"
#include "iostream"

//--------------------------------------------------------------
float ofApp::resistance(int r, float v){
    float d = -6 * 3.14 * r * v * 0.00001;
    return d;
}

void ofApp::setup(){
    ofBackground(0, 0, 0); //czarne tło ładnie wygląda
    ofSetFrameRate(60); //max ?
    
    for (int i=0; i<N; i++) {
        ball[i].x = ofGetWindowWidth()/2;
        ball[i].y = ofGetWindowHeight()/2;
//można zrobić losowe punkty z zakresu od r do width-r i od r do height - r, ale taki rozrzut na poącztku ładniej wygląda
        ball[i].vx = ofRandom(-10,10);
        ball[i].vy = ofRandom(-10,10);
        ball[i].r = ofRandom(5,50);
        ball[i].R = ofRandom(0,255);
        ball[i].G = ofRandom(0,255);
        ball[i].B = ofRandom(0,255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<N; i++) {
        float vxd = (ball[i].vx * resistance(ball[i].r, ball[i].vx));
        float vyd = (ball[i].vy * resistance(ball[i].r, ball[i].vy));
        
        if (ball[i].x < ball[i].r || ball[i].x + ball[i].r > ofGetWidth()) {
            if (!isOn){
                ball[i].vx *= -1;
            }else{
                vxd *= -1;
            }
        }
        
        if (ball[i].y < ball[i].r || ball[i].y + ball[i].r > ofGetHeight()) {
            if (!isOn){
                ball[i].vy *= -1;
            }else{
                vyd *= -1;
            }
        }
        //przesuń
        if (!isOn){
            ball[i].x += ball[i].vx;
            ball[i].y += ball[i].vy;
        }else{
            ball[i].x += vxd;
            ball[i].y += vyd;
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
    }else if (key == 'f'){
        std::cout<<"Wyłączono opór!"<<std::endl;
        isOn = false;
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
