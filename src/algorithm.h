#ifndef SRC_ALGORITHM_H_
#define SRC_ALGORITHM_H_

#include <opencv2/opencv.hpp>
#include <iostream> // cout, endl
#include <cmath>    // abs

using cv::Mat;
using std::cout;
using std::endl;
using std::abs;

namespace algorithm {
  Mat extractWLD(const Mat &image, int T, int M, int S);
}

#endif  // SRC_ALGORITHM_H_
