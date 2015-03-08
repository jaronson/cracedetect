#ifndef DETECTOR_H
#define DETECTOR_H

#include <opencv2/opencv.hpp>
#include "environment.h"
#include "errors.h"

using namespace cv;
using namespace std;
namespace env = environment;

class BaseDetector {
  public:
    CascadeClassifier classifier;

    double classifier_scale_factor  = 1.3;
    int    classifier_min_neighbors = 4;
    int    classifier_flags         = 0 | CV_HAAR_SCALE_IMAGE;
    Size   min_size                 = Size(30,30);

    virtual const string getCascadeName();
    void loadClassifier();
    void normalizeImage(Mat image, Mat image_out);
    void preprocessImage(Mat image, Mat image_out);
    vector<Rect> find(Mat image);

};

class FrontalFaceDetector : public BaseDetector {
  public:
    virtual const string getCascadeName() override {
      return "lbp/frontalface.xml";
    };
};

class ProfileFaceDetector : public BaseDetector {
  public:
    virtual const string getCascadeName() override {
      return "lbp/profileface.xml";
    };
};

#endif
