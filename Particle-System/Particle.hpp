//
//  Particle.hpp
//  emptyExample
//
//  Created by Dominik Grafik on 17.12.2017.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle{
    public:
        Particle(int mode1);
    
        ofPoint position;
        ofPoint velocity;
        ofPoint force;
    
    //colour
        int R;
        int G;
        int B;
        void setColour();
    
        float drag;
        float r;
    
    //life time
        bool isAlive;
        float opacity;
        double lifeTime;
        double lifeTimer;
        bool willDisappear;
        void checkIfIsAlive();
    
    //mode
//        bool fromCenter = false;
        int mode;   
    
        void reset();
        void update();
        void draw();
    
};

#endif /* Particle_hpp */
