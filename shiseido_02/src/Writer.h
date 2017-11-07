#ifndef Writer_h
#define Writer_h

#include "ofMain.h"
#include "ofxTextSuite.h"

class Writer{
    
public:
    
    Writer();
    
    int width;
    
    void update();
    void render();
    void reset();
    void advance();
    void advanceTo(int wordNumber);
    void resetTimer();
    
    string fullText;
    ofBuffer buffer;
    
    string highlightedText;
    ofBuffer highlightedBuffer;
    vector<string> splittedHighText;
    
    vector<int> highIndices;
    
    vector<string> splittedText;
    string displayText;
    
    int textPos;
    
    int maxWordsDisplayed;
    
    float time0;
    float interval;
    float timerSpeed;
    bool timerEnd;
    bool useTimer = false;
    
    ofxTextBlock textBlock;
    
    ofxTextBlock bodyTextBlock;
    
    string bodyText;
    
    bool changeColor = false;
    
    int advances = 0;
    int yPos;

};

#endif /* Writer_h */
