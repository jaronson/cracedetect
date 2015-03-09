#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#include <opencv2/opencv.hpp>
#include <glob.h>
#include <string>
#include <vector>

using std::string;
using std::vector;
using cv::Mat;

namespace utils {
  vector<string> glob(const string& pattern);
  void normalizeImage(Mat source, Mat target);
}

#endif  // SRC_UTILS_H_
