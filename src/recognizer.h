#ifndef SRC_RECOGNIZER_H_
#define SRC_RECOGNIZER_H_

#include <opencv2/opencv.hpp>
#include <iostream>
#include "./utils.h"

class Recognizer {
 private:
    cv::Ptr<cv::FaceRecognizer> model;
};

#endif  // SRC_RECOGNIZER_H_
