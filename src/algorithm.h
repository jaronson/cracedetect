#ifndef SRC_ALGORITHM_H_
#define SRC_ALGORITHM_H_

#include <opencv2/opencv.hpp>

using cv::Mat;

namespace algorithm {
  Mat extractWLD(const Mat &image,
      int n_subhistograms = 8,  // T
      int n_segments = 6,       // M
      int n_bins = 20);         // S
}

#endif  // SRC_ALGORITHM_H_
