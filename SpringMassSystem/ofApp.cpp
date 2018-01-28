#include "ofApp.h"
#include "Point.hpp"
#include "Spring.hpp"
#include <math.h>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(HEIGHT, WIDTH);
    ofSetFrameRate(60);
    
    mousePoint = new Pointer(0,0,0,0,75, true);
    
    for (int i = 0; i < iloscPunktow; ++i)
    {
        float x = 100 * sin(i + 1 * (2.0 * PI) / iloscPunktow);
        float y = 100 * cos(i + 1 * (2.0 * PI) / iloscPunktow);
        points.push_back(new Pointer(x+500,y+500,0,0,15,false));
    }
    
    for (int i = 0; i < iloscPunktow - 1; ++i)
    {
        Spring* s;
        s = new Spring(points[i], points[i+1]);
        spring.push_back(s);
        volume += 0.5 * fabs(s->point1->position.x - s->point2->position.x) * fabs(s->calcNormalizedVec().x) * s->calcLength();
    }

}

//--------------------------------------------------------------
void ofApp::update()
{
    
    for (Spring* s : spring)
    {
        s->calcVolume(volume);
        s->forceSpring();
    }
    
    for (Pointer* p : points)
    {
        p->updatePosition();
        if ((p->position - mousePoint->position).length() < p->getRadius() + mousePoint->getRadius())
        {
            p->refelction(mousePoint);
            mousePoint->speed = ofVec2f(0, 0);
            mousePoint->position = ofVec2f(mouseX, mouseY);
        }
        
        p->force.x = 0;
        p->force.y = 0;
        
        if (p->position.x < p->getRadius())
        {
            p->speed.x *= -1;
            p->position.x = p->getRadius();
        }
        if (p->position.x > HEIGHT - p->getRadius())
        {
            p->speed.x *= -1;
            p->position.x = HEIGHT - p->getRadius();
        }
        
        if(p->position.y >= WIDTH - p->getRadius())
        {
            p->speed.y *= -1;
            p->position.y = WIDTH - p->getRadius();
        }
        if (p->position.y < p->getRadius())
        {
            p->speed.y *= -1;
            p->position.y = p->getRadius();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetBackgroundColor(0, 0, 0);
    
    for (Pointer* p : points)
    {
        p->draw();
    }
    
    for (Spring* s : spring)
    {
        s->drawSpring();
    }
    
//    ofEnableAlphaBlending();
//    ofSetColor(255, 255, 255, 0);
    mousePoint->draw();
//    ofDisableAlphaBlending();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    mousePoint->setX(x);
    mousePoint->setY(y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
    
}
