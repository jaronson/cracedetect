#ifndef RECOGNIZER_H
#define RECOGNIZER_H

#include <iostream>
#include <opencv2/opencv.hpp>

#include "utils.h"
#include "configuration.h"

using namespace cv;
using namespace std;

class Recognizer {
    private:
        Ptr<FaceRecognizer> model;
};

#endif
