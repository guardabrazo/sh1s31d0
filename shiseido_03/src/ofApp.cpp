#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofHideCursor();
    ofToggleFullscreen();
    ofSetBackgroundColor(201, 214, 213);
    
    vector<string> fonts = {"PlayfairDisplay-Regular.ttf", "PlayfairDisplay-Bold.ttf"};
    
    title.load(fonts[1], 60);
    
    json.open("insights.json");
    colors.open("colors.json");
    
    
    for (int i = 0; i < json.size(); i++) {
        Insight tempInsight;
        insights.push_back(tempInsight);
    }
    
    int offset = 0;
    for (int i = 0; i < 5; i++) {
        
        for (int j = 0; j < 7; j++) {
            if (j == 0) {
                insights[i * 7].setup(fonts[1], json[i*7]["name"].asString(), json[i*7]["value"].asFloat(), true, 750, offset + 200 + j - 55);
            }else{
                insights[i*7 +j].setup(fonts[0], json[i*7+j]["name"].asString(), json[i*7+j]["value"].asFloat(), false, 750, offset + 200 + j * 35);
            }
        }
        offset += 350;
        
    }
    
    
    offset = 0;
    for (int i = 0; i < colors.size(); i++) {
        Gradient tempGradient;
        vector<ofColor> tempColors;
        vector<float> tempValues;
        for (int j = 0; j < colors[i].size(); j++) {
            ofColor tempColor = ofColor(colors[i][j]["r"].asFloat(), colors[i][j]["g"].asFloat(), colors[i][j]["b"].asFloat());
            tempColors.push_back(tempColor);
            tempValues.push_back( json[j + i*colors[i].size()]["value"].asFloat());

        }
        
        
        
        tempGradient.setup(ofPoint(1000, offset + 250), tempColors, tempValues);
        
        gradients.push_back(tempGradient);
        
        offset += 350;
    }
    
    
//    vector<ofColor> colors = {ofColor(255, 0, 255), ofColor(255, 0, 0), ofColor(0, 255, 0), ofColor(255, 0, 255), ofColor(0, 255, 255), ofColor(0, 0, 255)};
//    vector<float> values = {1, 1, 1, 1, 1, 1};
//    
//    gradient.setup(ofPoint(100, 100), colors, values);
    
    
    
    interval = 1500;
    
    fbo.allocate(ofGetHeight(), ofGetWidth());
    fbo.begin();
    ofClear(255);
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < insights.size(); i++) {
        insights[i].update();
    }
    
    for (int i = 0; i < gradients.size(); i ++) {
        gradients[i].update();
    }

    
    if (ofGetElapsedTimeMillis() > time0 + interval && useTimer == true) {
        launchGradients();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    boldFont.drawString("insights", 100, 100);
//    ofSetColor(0);
    
    fbo.begin();
    ofSetColor(201, 214, 213);
    ofDrawRectangle(0, 0, ofGetHeight(), ofGetWidth());
    
    ofSetColor(0);
    title.drawString("insights", 60, 120);
    
    for (int i = 0; i < insights.size(); i++) {
        insights[i].render();
    }
    
    for (int i = 0; i < gradients.size(); i ++) {
        gradients[i].render();
    }
    
    fbo.end();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth(), 0);
    ofRotate(90);
    fbo.draw(0, 0);
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'f') {
        ofToggleFullscreen();
    }
    
    if (key == 'r') {
        for (int i = 0; i < insights.size(); i++) {
            insights[i].easing = !insights[i].easing;
            insights[i].initTime = ofGetElapsedTimef();
        }
        useTimer = true;
        time0 = ofGetElapsedTimeMillis();
        
    }
    
    if (key == 'g') {
        
        for (int i = 0; i < gradients.size(); i++) {
//            gradients[i].initialAlpha = 50;
            gradients[i].easing = !gradients[i].easing;
            gradients[i].initTime = ofGetElapsedTimef();
        }
    }
    
}

void ofApp::launchGradients(){
    
    useTimer = false;
    
    for (int i = 0; i < gradients.size(); i++) {
        //            gradients[i].initialAlpha = 50;
        gradients[i].easing = !gradients[i].easing;
        gradients[i].initTime = ofGetElapsedTimef();
    }
}
