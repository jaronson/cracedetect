#include "tracker.h"

FaceTracker::FaceTracker(){
  frontal_detector.loadClassifier();
};

// Public methods
void FaceTracker::run(){
  initCapture();

  if(capture){
    while(true){
      frame_in = cvQueryFrame(capture);

      if(!frame_in.empty()){
        detectFrontal();
        display();
      } else {
        LOG(INFO) << "No captured frame!";
      }

      int c = waitKey(10);

      if((0xFF & c) == 27){
        break;
      }
    }
  }
};

// Private methods
void FaceTracker::createFaces(){
  for(auto rect_set : found_rects){
    for(auto rect : rect_set){
      Face face;
      faces.push_back(face);
    }
  }
};

void FaceTracker::cullFaces(){
  vector<Face> preserved;

  for(auto face : faces){
    if(!face.getCanDelete()){
      preserved.push_back(face);
    }
  }

  faces = preserved;
};

void FaceTracker::detectFrontal(){
  Mat processed;
  vector<Rect> frontal_rects;

  frontal_detector.find(frame_in, processed, frontal_rects);

  found_rects.push_back(frontal_rects);
};

void FaceTracker::display(){
  Scalar color;
  int i = 0;

  for(auto rect_set : found_rects){
    if(i % 2 == 0){
      color = Scalar(0, 255, 0);
    } else {
      color = Scalar(0, 0, 255);
    }

    for(auto rect : rect_set){
      rectangle(frame_in, rect.tl(), rect.br(), color);
    }

    i++;
  }

  cv::imshow("Faces", frame_in);
  found_rects.clear();
};

void FaceTracker::matchFoundRects(){
  for(auto face : faces){
    for(auto rect_set: found_rects){
      int top = 50000;
      int i   = 0;
      int j;
      vector<Rect> face_rects;

      for(auto rect : rect_set){
      }
    }
  }
};

void FaceTracker::initCapture(){
  capture = cvCaptureFromCAM(0);
};
