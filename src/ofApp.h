#pragma once

#include "ofMain.h"
#include "ofxHistogram.h"


class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void drawHistogram(vector<float> & h);
    
    int width, height;
    
    ofVideoGrabber cam;
    ofxHistogram histogram;
    
    ofxCvColorImage rgb, hsv;
    ofxCvGrayscaleImage r, g, b;
    ofxCvGrayscaleImage h, s, v;
    
    vector<float> histogramR, histogramG, histogramB;
    vector<float> histogramH, histogramS, histogramV;
};
