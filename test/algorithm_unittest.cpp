#include <opencv2/opencv.hpp>
#include "src/algorithm.h"
#include "gtest/gtest.h"

using cv::Mat;

TEST(AlgorithmTest, ImageLoading){
  Mat image = cv::imread("test/data/face.png", CV_LOAD_IMAGE_GRAYSCALE);
  EXPECT_FALSE(image.empty());

  Mat wld_hist = algorithm::extractWLD(image, 8, 6, 20);
}
