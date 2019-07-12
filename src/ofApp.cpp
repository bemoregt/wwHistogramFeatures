#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    width = 320;
    height = 240;

    cam.initGrabber(width, height);
    
    rgb.allocate(width, height);
    hsv.allocate(width, height);
    r.allocate(width, height);
    g.allocate(width, height);
    b.allocate(width, height);
    h.allocate(width, height);
    s.allocate(width, height);
    v.allocate(width, height);
    
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

    cam.update();
    
	if(cam.isFrameNew()) {
        
        rgb.setFromPixels(cam.getPixels());
        
        // get separate red, green, blue channels
        r.setFromPixels(rgb.getPixels().getChannel(0));
        g.setFromPixels(rgb.getPixels().getChannel(1));
        b.setFromPixels(rgb.getPixels().getChannel(2));

        // convert rgb to hsv and grab each channel individually
        cvCvtColor(rgb.getCvImage(), hsv.getCvImage(), CV_BGR2HSV);
        h.setFromPixels(hsv.getPixels().getChannel(0));
        s.setFromPixels(hsv.getPixels().getChannel(1));
        v.setFromPixels(hsv.getPixels().getChannel(2));

        // get histograms
        histogramR = histogram.getHistogram(r, 30); // 30 bins
        histogramG = histogram.getHistogram(g, 30);
        histogramB = histogram.getHistogram(b, 30);
        histogramH = histogram.getHistogram(h, 30);
        histogramS = histogram.getHistogram(s, 30);
        histogramV = histogram.getHistogram(v, 30);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 0, 0);
    r.draw(0, 0);
    drawHistogram(histogramR);
    
    ofTranslate(width, 0);

    ofSetColor(0, 255, 0);
    g.draw(0, 0);
    drawHistogram(histogramG);
    
    ofTranslate(width, 0);
    
    ofSetColor(0, 0, 255);
    b.draw(0, 0);
    drawHistogram(histogramB);
    
    ofTranslate(-2*width, height);
    
    ofSetColor(255);
    h.draw(0, 0);
    drawHistogram(histogramH);
    
    ofTranslate(width, 0);

    ofSetColor(255);
    s.draw(0, 0);
    drawHistogram(histogramS);
    
    ofTranslate(width, 0);

    ofSetColor(255);
    v.draw(0, 0);
    drawHistogram(histogramV);
    
    
    ofTranslate(-2*width, -height);
    ofDrawBitmapString("red", 0, 15);
    ofDrawBitmapString("green", width, 15);
    ofDrawBitmapString("blue", 2*width, 15);
    ofDrawBitmapString("hue", 0, 15+height);
    ofDrawBitmapString("saturation", width, 15+height);
    ofDrawBitmapString("value", 2*width, 15+height);

}

//--------------------------------------------------------------
void ofApp::drawHistogram(vector<float> & h) {
    ofBeginShape();
    ofNoFill();
    ofSetLineWidth(3);
    for (int i=0; i<h.size(); i++) {
        float x = ofMap(i, 0, h.size(), 0, 320);
        float y = ofMap(h[i], 0, 0.3, 240, 0);
        ofVertex(x, y);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}
