#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "Insight.h"
#include "Gradient.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
    
    vector<Insight> insights;
    
    ofxJSONElement json;
    ofxJSONElement colors;
    
    ofFbo fbo;
    
    ofTrueTypeFont title;
    
    Gradient gradient;
    
    vector<Gradient> gradients;
    
    bool useTimer = false;
    float time0;
    float interval;
    
    void launchGradients();
		
};
