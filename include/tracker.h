#ifndef TRACKER_H
#define TRACKER_H

#include <opencv2/opencv.hpp>
#include "easylogging++.h"
#include "environment.h"
#include "utils.h"

using namespace cv;
using namespace std;
namespace env = environment;

class FaceTracker {

  public:

    CvCapture*                 capture;
    Mat                        frame_in;
    Mat                        normalized_frame;
    vector<vector<Rect>>       found_rects;
    vector<CascadeClassifier>  classifiers;

    const vector<string> cascades = {
      "lbp/frontalface.xml",

      /* TODO: Profile face will only detect */
      /*   right-rotated faces, so preprocessing */
      /*   will be required */
      "lbp/profileface.xml",
    };

    void run();
    void detect();
    void display();
    FaceTracker();

  private:
    double  classifier_scale_factor  = 1.3;
    int     classifier_min_neighbors = 4;
    int     classifier_flags         = 0;
    Size    min_size                 = Size(30, 30);

    void initCapture();
    void initClassifiers();
};

#endif
