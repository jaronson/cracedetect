#include "detector.h"

/*
 * BaseDetector
 */
void BaseDetector::loadClassifier() {
  string path = env::getCascadePath(getCascadeName());
  classifier.load(path);

  if(classifier.empty()){
    LOG(ERROR) << "Unable to load classifier file: " << path;
    throw DetectorError();
  }
};

Mat BaseDetector::normalizeImage(Mat &image, Mat &image_out) {
  cvtColor(image, image_out, CV_BGR2GRAY);
  equalizeHist(image_out, image_out);
  return image_out;
};

Mat BaseDetector::preprocessImage(Mat &image, Mat &image_out) {
  return image;
};

vector<Rect> BaseDetector::find(Mat &image, vector<Rect> &rects) {
  detect(image, rects);
  return rects;
};

vector<Rect> BaseDetector::detect(Mat &image, vector<Rect> &rects) {
  classifier.detectMultiScale(image,
      rects,
      classifier_scale_factor,
      classifier_min_neighbors,
      classifier_flags,
      min_size);

  return rects;
};

/*
 * ProfileFaceDetector
 */
vector<Rect> ProfileFaceDetector::find(Mat &image, vector<Rect> &rects) {
  int w = image.cols;
  int h = image.rows;

  Mat flipped;
  vector<Rect> flipped_rects;
  flip(image, flipped, 1);

  detect(image, rects);
  detect(flipped, flipped_rects);

  if(flipped_rects.size() > 0){
    rects.insert(rects.end(), flipped_rects.begin(), flipped_rects.end());
  }

  return rects;
};
