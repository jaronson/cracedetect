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

void BaseDetector::normalizeImage(Mat image, Mat image_out){
  cvtColor(image, image_out, CV_BGR2GRAY);
  equalizeHist(image_out, image_out);
};

void BaseDetector::preprocessImage(Mat image, Mat image_out){
};

vector<Rect> BaseDetector::find(Mat image) {
  vector<Rect> rects;

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
