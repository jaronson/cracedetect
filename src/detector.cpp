#include "detector.h"

/*
 * BaseDetector
 */

vector<Rect> BaseDetector::find(Mat &image, Mat &processed_image, vector<Rect> &rects) {
  preprocessImage(image, processed_image);

  detect(processed_image, rects);
  return rects;
};

void BaseDetector::loadClassifier() {
  string path = env::getCascadePath(getCascadeName());
  classifier.load(path);

  if(classifier.empty()){
    LOG(ERROR) << "Unable to load classifier file: " << path;
    throw DetectorError();
  }
};

/*
 * ProfileFaceDetector
 */
vector<Rect> ProfileFaceDetector::find(Mat &image, Mat &processed_image, vector<Rect> &rects) {
  Mat flipped;
  vector<Rect> flipped_rects;

  preprocessImage(image, processed_image);

  flip(processed_image, flipped, 1);

  detect(processed_image, rects);
  detect(flipped, flipped_rects);

  if(flipped_rects.size() > 0){
    rects.insert(rects.end(), flipped_rects.begin(), flipped_rects.end());
  }

  return rects;
};

/*
 * Private
 */
Mat BaseDetector::normalizeImage(Mat &image, Mat &image_out) {
  cvtColor(image, image_out, CV_BGR2GRAY);
  equalizeHist(image_out, image_out);
  return image_out;
};

Mat BaseDetector::preprocessImage(Mat &image, Mat &image_out) {
  normalizeImage(image, image_out);
  return image_out;
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
