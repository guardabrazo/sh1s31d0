#pragma once

#include "ofMain.h"
#include "SineWave.h"
#include "Writer.h"

#define SCALE 1

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

    
    Writer writer;
    
    ofFbo fbo;
    

};
