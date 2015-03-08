#include "tracker.h"

FaceTracker::FaceTracker(){
  initClassifiers();
};

// Public methods
void FaceTracker::run(){
  initCapture();

  if(capture){
    while(true){
      frame_in = cvQueryFrame(capture);

      if(!frame_in.empty()){
        detect();
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
}

void FaceTracker::detect(){
  cvtColor(frame_in, normalized_frame, CV_BGR2GRAY);
  equalizeHist(normalized_frame, normalized_frame);

  for(auto it : classifiers){
    vector<Rect> rects;

    it.detectMultiScale(normalized_frame, rects, 1.3, 4, 0);

    LOG(INFO) << "Found " << rects.size() << " faces";

    found_rects.push_back(rects);
  }
}

void FaceTracker::display(){
  Scalar color;
  int i = 0;

  for(auto vrects : found_rects){
    if(i % 2 == 0){
      color = Scalar(0, 255, 0);
    } else {
      color = Scalar(0, 0, 255);
    }

    for(auto rect : vrects){
      rectangle(frame_in, rect.tl(), rect.br(), color);
    }

    i++;
  }

  imshow("Faces", frame_in);
  found_rects.clear();
}

// Private methods

void FaceTracker::initCapture(){
  capture = cvCaptureFromCAM(0);
}

void FaceTracker::initClassifiers(){
  for(auto it : cascades){
    CascadeClassifier classifier;
    classifier.load(env::getCascadePath(it));
    classifiers.push_back(classifier);
  }
}
