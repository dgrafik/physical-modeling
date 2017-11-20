#pragma once

#include "ofMain.h"
#define N 15

struct Ball {
    float x;
    float y;
    float vx;
    float vy;
    int r;
    int R;
    int G;
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
        float resistance (int r, float v);
        bool isOn = false;
        Ball ball[N];
    
};
