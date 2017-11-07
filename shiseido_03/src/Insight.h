#ifndef Insight_h
#define Insight_h

#include "ofMain.h"
#include "ofxTextSuite.h"
#include "ofxEasing.h"

class Insight {
public:

    Insight();

    Insight(string _font, string _text, float _value, bool _isBold);
    string text;
    float value;
    bool isBold;
    ofxTextBlock textBlock;
    
    int lineSize = 240;
    
    int initTime = 0;
    
    float posX, posY;
    
    float centerX, centerY;
    
    
    bool easing = false;
    
    void setup(string _font, string _text, float _value, bool _isBold, float _posX, float _posY);
    void update();
    void render();
};

#endif /* Insight_h */
