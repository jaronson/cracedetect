#ifndef TRACKER_H
#define TRACKER_H

#include <opencv2/opencv.hpp>
#include "easylogging++.h"
#include "environment.h"
#include "utils.h"
#include "detector.h"

using namespace cv;
using namespace std;
namespace env = environment;

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

#endif