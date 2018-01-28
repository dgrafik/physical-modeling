#pragma once
#include <ofColor.h>
#include <ofVec2f.h>


class Pointer
{
public:
    Pointer(float x, float y, float vx, float vy,  float r, bool mouse);
    ~Pointer() { }

    float speedX();
    float speedY();
    float getXForce();
    float getYForce();
    float getRadius();
    
    void draw();
    void updatePosition();
    
    void setX(float x);
    void setY(float y);
    
    void changeXForce(float forceX);
    void changeYForce(float forceY);
    
    void refelction(Pointer* pointOfReflection);
    
    ofVec2f position;
    ofVec2f speed;
    ofVec2f force;
    
private:
    
    ofColor color;
    
    float ay;
    float ax;
    float r;
    float mass;
    
};


