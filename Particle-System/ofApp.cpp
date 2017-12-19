#include "ofApp.h"
#include <chrono>

//--------------------------------------------------------------
void ofApp::setup(int dupa, int mode1){
    ofEnableDepthTest();
    ofSetVerticalSync(true);
    ofBackground(10, 10, 10);
    dupa = dupa == 0 ? 1300: dupa;
    
    for (int i = 0; i < dupa; i++){
        particle.push_back(new Particle(mode1));
    }
    
    easycam.setTarget(ofPoint(ofGetWidth()/2, ofGetHeight()/2, 0));
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < particle.size(); i++){
        particle[i]->update();
        if(!particle[i]->isAlive){
            delete particle[i];
            particle.erase(particle.begin() + i);
        }
    }
}

void ofApp::reset(){
    for(int i = 0; i < particle.size(); i++){
        particle[i]->reset();
    }
}

void ofApp::disableLifeTime(){
    for(int i = 0; i < particle.size(); i++){
        particle[i]->willDisappear = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (mode == 3){
        for(int i = 0; i < particle.size(); i++){
            particle[i]->draw();
        }
        
    }else{
        easycam.begin();
        
        for(int i = 0; i < particle.size(); i++){
            particle[i]->draw();
        }
        ofSetColor(190);
        ofNoFill();
        ofDrawIcoSphere(ofGetWidth()/2, ofGetHeight()/2, 10, 30);
        
        easycam.end();
    }
    
    ofSetColor(255, 255, 255);
    if (mode == 2){
        ofDrawBitmapString("Mode: " + to_string(mode) + "\nNumber of particles: " + to_string(particle.size()) + "\nPress space to reset\nPress 1-3 to change mode\nPress a to emit 100 extra particles", 10, 20);
    }else{
        ofDrawBitmapString("Mode: " + to_string(mode) + "\nNumber of particles: " + to_string(particle.size()) + "\nPress space to reset\nPress 1-3 to change mode\nPress t to active life time of particle\nPress + to add 500 particles", 10, 20);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '+'){
        if (mode != 2){
            int tmpNumber = number;
            number += 500;
            number -= tmpNumber;
            setup(number, mode);
        }
        
    }else if(key == ' '){
        particle.clear();
        if(mode == 1){
            number = 3000;
            setup(number, mode);
        }else if(mode == 2){
            number = 100;
            setup(number, mode);
        }else{
            number = 1300;
            setup(number, mode);
        }
        
    }else if(key == '1'){
        mode = 1;
        particle.clear();
        number = 3000;
        setup(number, mode);
        
    }else if(key == '2'){
        mode = 2;
        particle.clear();
        number = 100;
        setup(number, mode);
        for (int i = 0; i < 100; i++){
            particle[i]->willDisappear = true;
        }
        
    }else if(key == '3'){
        mode = 3;
        number = 1300;
        particle.clear();
        setup(number, mode);
        
    }else if(key =='a'){
        //emit particle
        if (mode == 2){
            for (int i = 0; i < 100; i++){
                particle.push_back(new Particle(2));
            }
            for (int i = 0; i < particle.size(); i++){
                particle[i]->willDisappear = true;
            }
        }

    }else if(key == 't'){
        if(keyState){
            for(int i = 0; i < particle.size(); i++){
                particle[i]->willDisappear = keyState;
            }
            keyState = false;
        }else{
            for(int i = 0; i < particle.size(); i++){
                particle[i]->willDisappear = keyState;
            }
            keyState = true;
        }
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
