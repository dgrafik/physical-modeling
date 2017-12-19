#include "Particle.hpp"

Particle::Particle(int mode1){
    isAlive = true;
    willDisappear = false;
    setColour();
    mode = mode1;
    
    lifeTime = ofRandom(0.9, 15.2);
    lifeTimer = std::clock();
    r = ofRandom(2.8, 4.1);
    
    if (mode == 3){
        position.x = ofRandom(5.1, ofGetWidth());
        position.y = ofRandom(5.1, ofGetHeight());
        position.z = ofRandom(0, 23.7);
        
        velocity.x = ofRandom(-3.5, 3.5);
        velocity.y = ofRandom(-3.5, 3.5);
        velocity.z = ofRandom(-3.5, 3.5);
    }else{
        position.x = ofGetWidth()/2;
        position.y = ofGetHeight()/2;
        position.z = 10;
        
        velocity.x = ofRandom(-8.1, 8.1);
        velocity.y = ofRandom(-8.1, 8.1);
        velocity.z = ofRandom(-8.1, 8.1);
    }
    
    if (mode == 1){
        force = ofPoint(ofRandom(-2.1, 2.8), ofRandom(-2.1, 2.8), ofRandom(-2.1, 2.8));
    }else{
        force = ofPoint(0, 0, 0);
    }
    
    drag  = ofRandom(0.82, 0.97);
}

void Particle::reset(){
    
}

void Particle::setColour(){
    R = ofRandom(0,255);
    G = ofRandom(0,255);
    B = ofRandom(0,255);
}

void Particle::checkIfIsAlive(){
    double duration = (std::clock() - lifeTimer) / (double)CLOCKS_PER_SEC;
    opacity = (duration / lifeTime) * 100;
    opacity = 100 - opacity;
    
    if (duration > lifeTime) {
        isAlive = false;
    }
}

void Particle::update(){
    if(mode == 1){
        velocity *= drag;
        velocity += force;
        position += velocity * 0.27;
        
    }else if(mode == 2){
        position += velocity.normalize() * 2.4;
    
    }else if (mode == 3){
        float mouseX = ofGetMouseX();
        float mouseY = ofGetMouseY();
        
        force.x = mouseX - position.x;
        force.y = mouseY - position.y;
        force.normalize();
        
        velocity *= drag;
        velocity += force;
        
        position += velocity * 0.4;
        
        if( position.x > ofGetWidth() ){
            position.x = ofGetWidth();
            velocity.x *= -1.0;
        }else if( position.x < 0 ){
            position.x = 0;
            velocity.x *= -1.0;
        }
        if( position.y > ofGetHeight() ){
            position.y = ofGetHeight();
            velocity.y *= -1.0;
        }
        else if( position.y < 0 ){
            position.y = 0;
            velocity.y *= -1.0;
        }
    }
    
    if(ofGetKeyPressed('h')){
        velocity.x = 0;
        velocity.y = 0;
        velocity.z = 0;
    }
    
    if(willDisappear){
        checkIfIsAlive();
    }
    
}

void Particle::draw(){
    if(willDisappear){
        ofSetColor(R, G, B, opacity * 2);
    }else{
        ofSetColor(R, G, B);
    }
    ofFill();
    ofDrawSphere(position.x, position.y, position.z, r);
}
