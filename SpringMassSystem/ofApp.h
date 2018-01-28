#include "ofMain.h"
#include "Point.hpp"
#include <vector>
#include "Spring.hpp"
#include <ofImage.h>

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
private:
    Pointer* mousePoint;
    
    std::vector<Pointer*> points;
    std::vector<Spring*> spring;
    
    float volume = 0;
    int iloscPunktow = 15;
    
    int HEIGHT = 1000;
    int WIDTH = 650;
    
};

