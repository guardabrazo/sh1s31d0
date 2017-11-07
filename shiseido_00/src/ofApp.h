#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    void keyReleased(int key);
	
    
    ofFbo fbo;
    
    ofTrueTypeFont firstLine;
    ofTrueTypeFont secondLine;
    
    string text;
    
    float time0;
    
    
    void drawText();
    void drawButton();
    
    ofTrueTypeFont buttonText;
    ofColor color = ofColor(0);
    ofColor titleColor = ofColor(0);
    
    float radius;
    float radiusOff = 0;
    
    bool fade = false;
    
    float titleAlpha = 255;
    float alpha = 50;
    
    void reset();
		
};
