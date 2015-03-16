#include "./algorithm.h"

Mat algorithm::extractWLD(const Mat &image,
    int n_subhistograms,
    int n_segments,
    int n_bins) {
  Mat hist(n_segments, n_subhistograms * n_bins, CV_32SC1, 0.0);
  unsigned char *ptr = (unsigned char*)(image.data) + image.step + 1;
  int i;
  int j;

  for (i = 1; i < image.rows - 1; ++i) {
    for (j = 1; j < image.cols - 1; ++j) {
    }
  }
  return hist;
}
