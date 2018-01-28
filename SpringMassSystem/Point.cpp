#include "Point.hpp"
#include <iostream>
#include <ofGraphics.h>
#include <of3dGraphics.h>
#include <ofColor.h>
#include <math.h>

Pointer::Pointer(float x, float y, float vx, float vy, float r, bool mouse)
{
    this->position.x = x;
    this->position.y = y;
    this->mass = 5;
    this->ay = 0.25;
    this->r = r;
    this->speed.x = vx;
    this->speed.y = vy;
    
    if (!mouse){
        color = ofColor(ofRandom(0, 255),
                        ofRandom(0, 255),
                        ofRandom(0, 255));
    }else{
        color = ofColor(255,255,255,0);
    }
}

float Pointer::getRadius()
{
    return this->r;
}

float Pointer::speedX()
{
    return this->speed.x;
}

float Pointer::speedY()
{
    return this->speed.y;
}

void Pointer::draw()
{
    ofSetColor(color);
    ofDrawCircle(this->position.x, this->position.y, this->r);
}

void Pointer::updatePosition()
{
    this->speed += this->force / this->mass;
    this->position.x += this->speed.x;
    
    this->speed.y += this->ay;
    this->position.y += this->speed.y;
}

void Pointer::setX(float x)
{
    position.x = x;
}

void Pointer::setY(float y)
{
    position.y = y;
}

void Pointer::changeXForce(float forceX)
{
    this->force.x = forceX;
}

void Pointer::changeYForce(float forceY)
{
    this->force.y = forceY;
}

float Pointer::getXForce()
{
    return this->force.x;
}

float Pointer::getYForce()
{
    return this->force.y;
}

void Pointer::refelction(Pointer* pointOfReflection)
{
    float reverseMass = 1 / mass;
    float reverseMassOfPointOfReflection = 1 / pointOfReflection->mass;
    float sumOfRevMass = reverseMass + reverseMassOfPointOfReflection;
    
    ofVec2f diffPosition = position - pointOfReflection->position;
    ofVec2f minimalVecToMove = diffPosition * ((getRadius() + pointOfReflection->getRadius()) - diffPosition.length()) / diffPosition.length();

    position += minimalVecToMove * (reverseMass / (reverseMass + reverseMassOfPointOfReflection));
    pointOfReflection->position -= minimalVecToMove * (reverseMassOfPointOfReflection / sumOfRevMass);
    
    ofVec2f diffOfSpeed = speed - pointOfReflection->speed;
    float impulsRate = (-0.25 * diffOfSpeed.dot(minimalVecToMove.normalize())) / sumOfRevMass;
    
    ofVec2f wektorImpulsu = minimalVecToMove.normalize() * impulsRate;
    speed += wektorImpulsu * reverseMass;
    
    pointOfReflection->speed -= wektorImpulsu * reverseMassOfPointOfReflection;
    
}
