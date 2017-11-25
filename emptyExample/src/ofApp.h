#pragma once

#include "ofMain.h"
#define N 150

struct Ball {
    float x;
    float y;
    float vx;
    float vy;
    int r; //promień
    float m; //masa
    int R; // kolor
    int G; // kolor
    int B; // kolor
};

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        float dt = 0.1;
        int g = 9.8;
        int f = 2;
        Ball ball[N];
        float resistance (int r, float v);
        bool isOn = false;
    
};
