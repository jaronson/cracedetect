#ifndef SRC_DETECTOR_H_
#define SRC_DETECTOR_H_

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include "./environment.h"
#include "./errors.h"

namespace env = environment;

using std::string;
using std::vector;
using cv::Mat;
using cv::Rect;
using cv::Size;

class BaseDetector {
 public:
    vector<Rect> find(const Mat &image, Mat &processed_image,
        vector<Rect> &rects);
    void loadClassifier();

 protected:
    cv::CascadeClassifier classifier;

    double classifier_scale_factor  = 1.3;
    int    classifier_min_neighbors = 4;
    int    classifier_flags         = 0 | CV_HAAR_SCALE_IMAGE;
    Size   min_size                 = Size(30, 30);

    virtual const string getCascadeName() = 0;
    Mat normalizeImage(const Mat &image, Mat &image_out);
    Mat preprocessImage(const Mat &image, Mat &image_out);
    vector<Rect> detect(const Mat &image, vector<Rect> &rects);
};

class FrontalFaceDetector : public BaseDetector {
 public:
    const string getCascadeName() override {
      return "lbp/frontalface.xml";
    };
};

class ProfileFaceDetector : public BaseDetector {
 public:
    const string getCascadeName() override {
      return "lbp/profileface.xml";
    };
    vector<Rect> find(const Mat &image, Mat &processed_image,
        vector<Rect> &rects);
};

#endif  // SRC_DETECTOR_H_
