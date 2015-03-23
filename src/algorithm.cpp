#include "./algorithm.h"

Mat algorithm::extractWLD(const Mat &image, int T = 8, int M = 6, int S = 20) {

  int y_size        = image.cols,
      x_size        = image.rows,
      step          = image.step,
      block_size_y  = 3,
      block_size_x  = 3,
      delta         = 5,
      alpha         = 3,
      num_neighbors = 8;

  double epsilon = 0.0000001;
  double pi      = 3.141592653589;

  int dx = x_size - block_size_x,
      dy = y_size - block_size_y;

  Mat differential_excitation(dy + 1, dx + 1, CV_32SC1, double(0));
  Mat gradient_orientation(dy + 1, dx + 1, CV_32SC1, double(0));
  unsigned char *ptr = (unsigned char*)(image.data) + step + 1;

  for (int y = 1; y < y_size - 2; ++y) {
    for (int x = 1; x < x_size - 2; ++x) {
      float v00 = ptr[-step - 1] +
                  ptr[-step] +
                  ptr[-step + 1] +
                  ptr[-1] +
                  ptr[1] +
                  ptr[step - 1] +
                  ptr[step] +
                  ptr[step + 1];

      float v01 = ptr[0] + delta;

      if (v01 > 0 && v01 < 0.01) {
        differential_excitation.at<double>(y,x) = cv::fastAtan2(alpha * v00, v01);
      } else {
        differential_excitation.at<double>(y,x) = 0.1;
      }

      ptr++;
    }

    ptr += step - y_size + 2;
  }

  return gradient_orientation;
}
