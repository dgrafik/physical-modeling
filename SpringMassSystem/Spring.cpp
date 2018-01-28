#include "Spring.hpp"
#include <iostream>
#include <ofGraphics.h>
#include <of3dGraphics.h>
#include <ofColor.h>
#include <math.h>

Spring::Spring(Pointer* a, Pointer* b): point1(a), point2(b) { }
Spring::~Spring() { }

float Spring::calcLength()
{
    return (point1->position - point2->position).length();
}

void Spring::calcVolume(float objetosc)
{
    ofVec2f wekNormalny = ((point1->position - point2->position).perpendicular())/calcLength();
    float cisnienie = 0.00001;
    float cisnienieV = calcLength() * cisnienie * (1.0f / objetosc);
    point1->force += wekNormalny * cisnienieV;
}

ofVec2f Spring::calcNormalizedVec()
{
    return (point1->position - point2->position).perpendicular();
}

void Spring::drawSpring()
{
    ofSetLineWidth(2);
    ofDrawLine(point1->position, point2->position);
}

void Spring::forceSpring()
{
    
    float speedDlaX = point1->speedX() - point2->speedX();
    float speedDlaY = point1->speedY() - point2->speedY();
    
    float force = (((calcLength() - basicLength) * k) +
                   ((speedDlaX * (point1->position.x - point2->position.x)) +
                    (speedDlaY * (point1->position.y - point2->position.y)) * zeta) / calcLength());
    
    float calkowitaforceX = (((point1->position.x - point2->position.x) / calcLength()) * force);
    float calkowitaforceY = (((point1->position.y - point2->position.y) / calcLength()) * force);
    
    point1->changeXForce(point1->getXForce() - calkowitaforceX);
    point1->changeYForce(point1->getYForce() - calkowitaforceY);
    
    point2->changeXForce(point2->getXForce() + calkowitaforceX);
    point2->changeYForce(point2->getYForce() + calkowitaforceY);
}
