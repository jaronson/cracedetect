#include <opencv2/opencv.hpp>
#include <iostream>
#include "src/algorithm.h"
#include "gtest/gtest.h"

using cv::Mat;
using namespace std;

TEST(AlgorithmTest, ImageLoading){
  Mat image = cv::imread("/usr/dev/jaronson/cracedetect/test/data/face.png", CV_LOAD_IMAGE_GRAYSCALE);

  EXPECT_FALSE(image.empty());

  Mat wld_hist = algorithm::extractWLD(image, 8, 6, 20);
  cout << "wld_hist = " << endl << " " << wld_hist << endl;
}
