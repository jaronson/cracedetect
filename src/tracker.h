#ifndef SRC_TRACKER_H_
#define SRC_TRACKER_H_

#include <opencv2/opencv.hpp>
#include <vector>
#include "easylogging++.h"
#include "./environment.h"
#include "./utils.h"
#include "./detector.h"

namespace env = environment;

using std::vector;
using cv::Mat;
using cv::Scalar;

class FaceTracker {
 public:
    void run();
    FaceTracker();

 private:
    CvCapture*  capture;
    Mat         frame_in;

    vector<vector<Rect>> found_rects;

    FrontalFaceDetector frontal_detector;
    ProfileFaceDetector profile_detector;

    void initCapture();
    void detect();
    void display();
};

#endif  // SRC_TRACKER_H_
