#include "Insight.h"

Insight::Insight(){
    
}


Insight::Insight(string _font, string _text, float _value, bool _isBold){

    text = _text;
    value = _value;
    isBold = _isBold;
    
    textBlock.init(_font, 30);
    
    
    textBlock.setText(text);
    
    
    
}


void Insight::setup(string _font, string _text, float _value, bool _isBold, float _posX, float _posY){
    text = _text;
    value = _value;
    isBold = _isBold;
    posX = _posX;
    posY = _posY;
    
    int fontSize;
    if (isBold) {
        fontSize = 45;
    }else{
        fontSize = 20;
    }
    textBlock.init(_font, fontSize);
    
    
    textBlock.setText(text);
}

void Insight::update(){
    
    float duration = 3.0;
    float endTime = initTime + duration;
    float now = ofGetElapsedTimef();
    
    float endPos = ofMap(value, 0, 1, posX + 30, posX + lineSize);
    
    
    if (easing) {
        centerX = ofxeasing::map_clamp(now, initTime, endTime, posX + 30, endPos, &ofxeasing::quad::easeInOut);
    }else{
        centerX = posX + 30;
    }
    
    
    
}

void Insight::render(){
    
    textBlock.setColor(0, 0, 0, 255);
    textBlock.drawRight(posX, posY);
    
    if (isBold) {
        ofSetLineWidth(4);
        ofDrawLine(posX + 30, posY + 45 + 45/2, posX + lineSize, posY + 45 + 45/2);
        ofDrawCircle(centerX, posY + 50, 3);
    } else {
        ofSetLineWidth(2);
        ofDrawLine(posX + 30, posY + 20 + 20/2, posX + lineSize, posY + 20 + 20/2);
        ofDrawCircle(centerX, posY + 20 , 2);
    }
    
}
