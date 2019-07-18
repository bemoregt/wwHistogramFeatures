# ofxHistogramFeatures
Display 6-Histogram of Image and get 4-Histogram Features

![Histogram example]( https://github.com/bemoregt/ofxHistogramFeatures/blob/master/hist.png "exmaple")

![Histogram example3]( https://github.com/bemoregt/ofxHistogramFeatures/blob/master/lab.jpg "exmaple")

![Histogram example2]( https://github.com/bemoregt/ofxHistogramFeatures/blob/master/hf.png "exmaple2")

### How TO
- Resize your image to 320x240 size & jpg format before test.
- R,G,B Histogram & H, S,V Histograms
- 4-Histogram features: Mean, Var, Energy, Entropy

### Algorithm
- Histogram Mean: Intensity level of image
- Histogram Variance: Contrast of Image
- Histogram Energy: Peakness of Image
- Histogram Entropy: Uniformity of Image

### Dependency
- OpenFrameworks 0.10.1
- ofxCv
- ofxOpenCv
- ofxHitogram
- XCode 10.12.x
- OSX Mojave

### Next Plan
- Add Skewness & Kurtosis
- R, B, H, S, V Channel Features
- Spectral Histogram Features
- L*a*b* Histogram Features

### Reference
- Edited source from https://github.com/genekogan/ofxHistogram.git
