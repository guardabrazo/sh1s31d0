#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(201, 214, 213);
    vector<string> fonts = {"PlayfairDisplay-Regular.ttf", "PlayfairDisplay-Black.ttf"};

    firstLine.load(fonts[0], 60);
    secondLine.load(fonts[0], 30);
    
    buttonText.load(fonts[0], 20);
    
    fbo.allocate(ofGetHeight(), ofGetWidth());
    fbo.begin();
    ofClear(255);
    fbo.end();
    
    text = "Un proyecto basado en la inteligencia\nartificial IBM Watson";
    
}

//--------------------------------------------------------------
void ofApp::update(){

//    if ((ofGetFrameNum() / 30) % 4 == 0 ) {
//        text = "Powered by IBM Watson";
//    }else if ((ofGetFrameNum() / 30) % 4 == 1){
//        text = "Powered by IBM Watson.";
//    }else if ((ofGetFrameNum() / 30) % 4 == 2){
//        text = "Powered by IBM Watson..";
//    }else if ((ofGetFrameNum() / 30) % 4 == 3){
//        text = "Powered by IBM Watson...";
//    }
    
    radius = ofMap(sin(radiusOff), 0, 1, 120, 130);
    radiusOff += 0.05;
    
    if (fade) {
        
        if (alpha > 0) {
            alpha -= 1;
            color = ofColor(0, alpha);
        }
        
        if (titleAlpha > 0) {
            titleAlpha -= 1;
            titleColor = ofColor(0, titleAlpha);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    fbo.begin();
    ofSetColor(201, 214, 213);
    ofDrawRectangle(0, 0, ofGetHeight(), ofGetWidth());
    
    drawText();
    drawButton();
    
    fbo.end();
    
    ofPushMatrix();
    ofTranslate(0, ofGetHeight());
    ofRotate(-90);
    fbo.draw(0, 0);
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'f') {
        ofToggleFullscreen();
    }
    
    if (key == ' ') {
        alpha = 50;
        color = ofColor(0, alpha);
        
    }
    
    if (key == 'r') {
        reset();
    }
    
    
}

void ofApp::keyReleased(int key){
    
    if (key == ' ') {
//        color = ofColor(0, 255);
        fade = true;
    }
    
    
    
}


void ofApp::drawText(){
    
    ofSetColor(titleColor);
    firstLine.drawString("Beauty inside", 130, 870);
    secondLine.drawString(text, 140, 920);
    
}

void ofApp::drawButton(){
    
    ofSetColor(color);
    ofNoFill();
    ofSetCircleResolution(256);
    ofSetLineWidth(2);
    ofDrawCircle(ofGetHeight() * 0.5, ofGetWidth() * 0.75, radius);
    buttonText.drawString("Tap to start", ofGetHeight() * 0.435, ofGetWidth() * 0.753);
    
}


void ofApp::reset(){
    
    fade = false;
    alpha = 255;
    color = ofColor(0, alpha);
    titleAlpha = 255;
    titleColor = ofColor(0, titleAlpha);
}








