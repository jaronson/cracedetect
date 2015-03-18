#ifndef SRC_ALGORITHM_H_
#define SRC_ALGORITHM_H_

#include <opencv2/opencv.hpp>
#include <iostream>

using cv::Mat;

namespace algorithm {
  float getPixelRatio(float current_pixel, float neighbor);
  Mat extractWLD(const Mat &image,
      int n_subhistograms,  // T
      int n_segments,       // M
      int n_bins);          // S
}

#endif  // SRC_ALGORITHM_H_
