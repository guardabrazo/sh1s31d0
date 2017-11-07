#include "SineWave.h"

SineWave::SineWave(){
    
    
    width = ofGetHeight();
    yPos = ofGetWidth() * 0.2;
    
    xSpacing = 5;
    theta = 0;
    amplitude = 150;
    period = 250;
//    waveWidth = ofGetWidth() + xSpacing;
    waveWidth = width + xSpacing;
    dx = (TWO_PI / period) * xSpacing;
    
    int numberOfValues = waveWidth / xSpacing;
    
    for (int i = 0; i < numberOfValues; i++) {
        yValues.push_back(0);
    }
    
    lineWeight = 5;
    
    bufferSize = 512;
    int sampleRate = 44100;
    int channels = 1;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    soundStream.setDeviceID(0);
    soundStream.setup(this, 0, channels, sampleRate, bufferSize, 4);
    
    audioPlayer.load("speech.mp3");
    audioAnalyzer.setup(sampleRate, bufferSize, 2);
}


void SineWave::update(){
    
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    
    cout << audioPlayer.isLoaded() << endl;
    cout <<" A "  << endl;
    
    
    soundBuffer = audioPlayer.getCurrentSoundBuffer(bufferSize);
    //ANALYZE SOUNDBUFFER:
    cout <<" AA "  << endl;
    cout << soundBuffer.size() << endl;
    
    audioAnalyzer.analyze(soundBuffer);
    
    cout <<" B "  << endl;
    float left = audioAnalyzer.getValue(POWER, 0, 0.9);
    float right = audioAnalyzer.getValue(POWER, 1, 0.9);
    float rms = (left + right) * 0.5;
    
    float power;
    
    if (input == 1) {
        power = scaledVol;
    }else if (input == 2){
        power = rms;
    }
    
    amplitude = ofMap(power, 0, 1, 50, 300);
    cout <<" C "  << endl;

}

void SineWave::calcWave(){
    
    // Increment theta (try different values for 'angular velocity' here
    theta -= 0.04;
    
    float x = theta;
    for (int i = 0; i < yValues.size(); i++) {
        yValues[i] = sin(x) * amplitude;
        x += dx;
    }
    for (int x = 0; x < yValues.size(); x++) {
        float easing = ofMap(cos(TWO_PI / yValues.size() * x), -1, 1, 1, 0);
        ofPoint pt = ofPoint(x * xSpacing, yPos + yValues[x] * easing);
        line.addVertex(pt);
    }
    
    ofxPolyToMesh(lineMesh, line, lineWeight);
    
}

void SineWave::renderWave(){
    
    ofSetColor(40);
    ofSetLineWidth(lineWeight);
    lineMesh.draw();
    line.clear();
    
}

//--------------------------------------------------------------
void SineWave::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    
}


