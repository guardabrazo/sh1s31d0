#ifndef Gradient_h
#define Gradient_h

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxEasing.h"

class Gradient{
public:
    Gradient();
    
    void setup(ofPoint _pos, vector<ofColor> _colors, vector<float> _values);
    void update();
    void render();
    
    vector<ofColor> colors;
    vector<float> values;
    
    ofPoint pos;
    float width;
    float height;
    
    int initTime = 0;
    bool easing = false;
    
    vector<float> alphaValues = {0, 0, 0, 0, 0, 0};
    
//    int initialAlpha = 0;
};


#endif /* Gradient_h */
