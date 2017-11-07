#ifndef _SINEWAVE // if this class hasn't been defined, the program can define it
#define _SINEWAVE // by using this if statement you prevent the class to be called more

#include "ofMain.h"
#include "ofxPoly.h"
#include "ofxAudioDecoder.h"
#include "ofxAudioAnalyzer.h"
#include "ofSoundPlayerExtended.h"

class SineWave: public ofBaseApp {
    
public:
    
    
    SineWave();
    
    int xSpacing;
    int waveWidth;
    float theta;        //Start angle
    float amplitude;
    float amplitudeMult;
    float period;
    float dx;
    vector<float> yValues;
    
    int width;
    float yPos;
    
    ofPolyline line;
    ofMesh lineMesh;
    float lineWeight;
    void update();
    void calcWave();
    void renderWave();
    
    //AUDIO INPUT AND ANALYSIS
    void audioIn(float * input, int bufferSize, int nChannels);
    vector <float> left;
    vector <float> right;
    float smoothedVol;
    float scaledVol;
    ofSoundStream soundStream;
    int bufferSize;
    
    //AUDIO PLAYER AND ANALYSIS
    ofxAudioAnalyzer audioAnalyzer;
    ofSoundPlayerExtended audioPlayer;
    ofSoundBuffer soundBuffer;
    
    int input = 1;

};

#endif
