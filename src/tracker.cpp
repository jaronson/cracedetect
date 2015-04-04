#include "./tracker.h"
#include <vector>

FaceTracker::FaceTracker() {
}

void FaceTracker::run() {
}

FaceTracker::FaceTracker() {
  frontal_detector.loadClassifier();
  profile_detector.loadClassifier();
}

// Public methods
void FaceTracker::run() {
  initCapture();

  if (capture) {
    while (true) {
      frame_in = cvQueryFrame(capture);

      if (!frame_in.empty()) {
        detect();
        display();
      } else {
        LOG(INFO) << "No captured frame!";
      }

      int c = cv::waitKey(10);

      if ((0xFF & c) == 27) {
        break;
      }
    }
  }
}

void FaceTracker::detect() {
  Mat processed;
  vector<Rect> frontal_rects;
  vector<Rect> profile_rects;

  frontal_detector.find(frame_in, processed, frontal_rects);
  profile_detector.find(frame_in, processed, profile_rects);

  found_rects.push_back(frontal_rects);
  found_rects.push_back(profile_rects);
}

void FaceTracker::display() {
  Scalar color;
  int i = 0;

  for (auto rect_set : found_rects) {
    if (i % 2 == 0) {
      color = Scalar(0, 255, 0);
    } else {
      color = Scalar(0, 0, 255);
    }

    for (auto rect : rect_set) {
      rectangle(frame_in, rect.tl(), rect.br(), color);
    }

    i++;
  }

  cv::imshow("Faces", frame_in);
  found_rects.clear();
}

// Private methods

void FaceTracker::initCapture() {
  capture = cvCaptureFromCAM(0);
}
