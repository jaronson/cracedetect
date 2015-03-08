#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <glob.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace utils {
  vector<string> glob(const string& pattern);
  void normalizeImage(Mat source, Mat target);
}

#endif
