#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <opencv2/opencv.hpp>

using namespace cv;

struct config_t {
    string recognizer_model_path;
};

extern config_t CONFIG;

#endif
