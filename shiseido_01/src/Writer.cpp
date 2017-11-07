
#include "Writer.h"

Writer::Writer(){
    
    width = 1080;
    
    buffer = ofBufferFromFile("text.txt");
    fullText = buffer.getText();
    splittedText = ofSplitString(fullText, " ");
    
    highlightedBuffer = ofBufferFromFile("hText.txt");
    highlightedText = highlightedBuffer.getText();
    splittedHighText = ofSplitString(highlightedText, " ");
    
    maxWordsDisplayed = 5;
    int numberOfWords = 50;
    textPos = 0;
    
    
    
    for (int i = 0; i < maxWordsDisplayed ; i++) {
        splittedText.insert(splittedText.begin(), " ");
    }
    
    //    for (int i = 0; i < numberOfWords; i++) {
    //        splittedText.push_back(ofToString(i));
    //    }
    
    timerEnd = true;
    time0 = ofGetElapsedTimeMillis();
    timerSpeed = 0.25;
    interval = ofRandom(timerSpeed * 0.5, timerSpeed * 2) * 1000;
    
    textBlock.init("PlayfairDisplay-Regular.ttf", 50);
    
    bodyTextBlock.init("PlayfairDisplay-Regular.ttf", 20);
    bodyTextBlock.altFont.load("PlayfairDisplay-Black.ttf", 20);
    
    
    for (int i = 0; i < splittedHighText.size(); i++) {
        if (ofIsStringInString(splittedHighText[i], "*")) {
            highIndices.push_back(i);
        }
    }
    
    
}

void Writer::update(){
    displayText = "";
    bodyText = "";
    
    if (textPos > maxWordsDisplayed) {
        displayText += "...";
    }
    
    
    
    for (int i = 0; i < maxWordsDisplayed; i++) {
        displayText += (splittedText[textPos + i] + ' ');
    }
    textBlock.setText(displayText);
    
    for (int i = 0; i < textPos + maxWordsDisplayed; i++) {
        if (ofIsStringInString(splittedHighText[i], "*")) {
//            splittedHighText[i].pop_back();
        }
        bodyText += splittedHighText[i - maxWordsDisplayed] + ' ';
    }
    bodyTextBlock.setText(bodyText);
    
    
    
    float timer = ofGetElapsedTimeMillis() - time0;
    
    if (timer >= interval && timerEnd == false && useTimer == true) {
        timerEnd = true;
        advance();
        resetTimer();
    }

}

void Writer::render(){
    //    ofDrawBitmapString(displayText, 100, 100);
    textBlock.setColor(40, 40, 40, 255);
    textBlock.wrapTextX(width * 0.8);
    textBlock.drawCenter(width * 0.5, width * 0.6);
    
    
    bodyTextBlock.setColor(40, 40, 40, 255);
    
    
    for (int i = 0; i < bodyTextBlock.words.size(); i++) {
        for (int j = 0; j < highIndices.size(); j++) {
            if (i == highIndices[j]) {
//                bodyTextBlock.words[i*2].color = ofColor(255);
            }
        }
        //        if (i == 10) {
        //            bodyTextBlock.words[i].color = ofColor(255);
        //        }
        
    }
    
    bodyTextBlock.wrapTextX(width * 0.8);
    bodyTextBlock.drawLeft(width * 0.1, ofGetWidth() * 0.5);
}

void Writer::advance(){
    
    if (textPos < fullText.size() - maxWordsDisplayed) {
        textPos ++;
    }
    
}

void Writer::advanceTo(int wordNumber){
    
    if (wordNumber < fullText.size() - maxWordsDisplayed) {
        textPos = wordNumber;
    }
    
}

void Writer::reset(){
    textPos = 0;
}

void Writer::resetTimer(){
    useTimer = true;
    timerEnd = false;
    time0 = ofGetElapsedTimeMillis();
    interval = ofRandom(timerSpeed * 0.5, timerSpeed * 2) * 1000;
}
