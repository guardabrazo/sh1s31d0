#include "Gradient.h"


Gradient::Gradient(){
    
    
}


void Gradient::setup(ofPoint _pos, vector<ofColor> _colors, vector<float> _values){
    pos = _pos;
    colors = _colors;
    values = _values;
    
    width = 20;
    height = 245;
    
}

void Gradient::update(){
    
    float duration = 1.5;
    float endTime = initTime + duration;
    float now = ofGetElapsedTimef();
    
    
    
//    float endPos = ofMap(value, 0, 1, posX + 30, posX + lineSize);
    
    vector<float> endAlphas = values;
    
    
    
    if (easing) {
        for (int i = 0; i < endAlphas.size(); i++) {
            alphaValues[i] = ofxeasing::map_clamp(now, initTime, endTime, 0, ofMap(endAlphas[i], 0, 1, 0.1, 1), &ofxeasing::quad::easeInOut);
            
        }
//        centerX = ofxeasing::map_clamp(now, initTime, endTime, posX + 30, endPos, &ofxeasing::quad::easeInOut);
    }else{
        for (int i = 0; i < endAlphas.size(); i++) {
            alphaValues[i] = 0;
        }
    }

    
}

void Gradient::render(){
    
    ofMesh grad;
    grad.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    for (int i = 0; i < colors.size(); i++) {
        
        
        
        grad.addVertex(ofPoint(pos.x, pos.y + (i * height/colors.size())));
        grad.addColor(ofColor(colors[i].r, colors[i].g, colors[i].b, ofMap(alphaValues[i], 0, 1, 0, 255)));
        grad.addVertex(ofPoint(pos.x + width, pos.y + (i * height/colors.size())));
        grad.addColor(ofColor(colors[i].r, colors[i].g, colors[i].b, ofMap(alphaValues[i], 0, 1, 0, 255)));


//        grad.addVertex(ofPoint(pos.x, pos.y + (i * height/colors.size())));
//        grad.addColor(ofColor(colors[i].r, colors[i].g, colors[i].b, 255));
//        grad.addVertex(ofPoint(pos.x + width, pos.y  + (i * height/colors.size())));
//        grad.addColor(ofColor(colors[i].r, colors[i].g, colors[i].b, 255));
    }
    
    grad.draw();
    
}
