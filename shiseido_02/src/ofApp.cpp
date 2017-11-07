#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_ERROR);
    
    ofSetBackgroundColor(201, 214, 213);
    
    fbo.allocate(1080 * SCALE, 1920 * SCALE);
    fbo.begin();
    ofClear(255);
    fbo.end();
    ofHideCursor();
    ofToggleFullscreen();
    
}


//--------------------------------------------------------------
void ofApp::update(){

    sineWave.update();
    sineWave.calcWave();
    writer.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    fbo.begin();
    ofSetColor(201, 214, 213);
    ofDrawRectangle(0, 0, ofGetHeight(), ofGetWidth());
    
//    sineWave.renderWave();
    writer.render();
    
    fbo.end();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth(), 0);
    ofRotate(90);
    fbo.draw(0, 0, 1080 * SCALE, 1920 * SCALE);
    ofPopMatrix();
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == '1') {
        sineWave.input = 1;
    }

    if (key == '2') {
        sineWave.input = 2;
    }

    if (key == 's' ) {
        sineWave.audioPlayer.stop();
    }

    if (key == 'p') {
        sineWave.audioPlayer.play();
    }
    
    if (key == 'f') {
        ofToggleFullscreen();
    }
    
    if (key == 't') {
        writer.advance();
    }
    
    if (key == 'n') {
        writer.advanceTo(50);
    }
    
    
    if (key == 'r') {
        writer.reset();
    }
    
    if (key == ' ') {
        writer.resetTimer();
    }
    
    if (key == 'u') {
        writer.useTimer = !writer.useTimer;
    }
    

}

