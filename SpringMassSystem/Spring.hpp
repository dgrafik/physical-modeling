#pragma once
#include <ofColor.h>
#include "Point.hpp"
#include <math.h>
class Spring
{
public:
    
    Spring(Pointer* a, Pointer* b) : point1(a), point2(b) { }
    ~Spring() { }
    
    float calcLength();
    
    void drawSpring();
    void forceSpring();
    void calcVolume(float objetosc);
    
    Pointer* point1;
    Pointer* point2;
    
    ofVec2f calcNormalizedVec();
    
private:
    
    float k = 1;
    float zeta = 15/1000; //współczynnik tłumienia
    float basicLength = calcLength();
};


