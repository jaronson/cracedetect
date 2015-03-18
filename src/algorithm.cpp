#include "./algorithm.h"

float algorithm::getPixelRatio(float current_pixel, float neighbor) {
  float ret = 0.0;

  if (current_pixel == 0) {
    return ret;
  }

  ret = neighbor - current_pixel;
  ret = ret / current_pixel;

  return ret;
}

Mat algorithm::extractWLD(
    const Mat &image,
    int n_subhistograms = 8,
    int n_segments = 6,
    int n_bins = 20) {
  Mat hist(n_segments, n_subhistograms * n_bins, CV_32SC1, double(0));
  unsigned char *ptr = (unsigned char*)(image.data) + image.step + 1;
  int i, j;

  for (i = 1; i < image.rows - 1; ++i) {
    for (j = 1; j < image.cols - 1; ++j) {
      float cur   = ptr[0];
      float sigma = getPixelRatio(cur, ptr[-image.step - 1]) +
                    getPixelRatio(cur, ptr[-image.step]) +
                    getPixelRatio(cur, ptr[-image.step + 1]) +
                    getPixelRatio(cur, ptr[-1]) +
                    getPixelRatio(cur, ptr[1]) +
                    getPixelRatio(cur, ptr[image.step - 1]) +
                    getPixelRatio(cur, ptr[image.step]) +
                    getPixelRatio(cur, ptr[image.step + 1]);

      sigma = cv::fastAtan2(sigma, cur);

      if (sigma > 180.0) {
        sigma = sigma - 360.0;
      }

      float theta = cv::fastAtan2(
          ptr[image.step] - ptr[-image.step],
          ptr[-1] - ptr[1]);

      int t = (int)(theta / 360.0 * n_subhistograms);
      int c = (int)((sigma + 90.0) / 180.0 * n_segments * n_bins);

      uchar a = (unsigned char) (t * n_bins +
                  (c % n_bins) +
                  (int)(c / n_bins) *
                  n_bins *
                  n_subhistograms);

      hist.data[a]++;

      ptr++;
    }

    ptr += image.step - image.cols + 2;
  }

  Mat hist_norm(n_segments, n_bins * n_subhistograms, CV_32FC1);
  cv::resize(hist, hist_norm, cv::Size(image.rows - 2, image.cols - 2));

  return hist_norm;
}
