#ifndef SRC_FACE_H_
#define SRC_FACE_H_

#include <opencv2/opencv.hpp>
#include <vector>

using cv::Rect;
using std::vector;

class Face {
 public:
    Face();

    static int getNextId() {
      return face_id++;
    }

    int  getId();
    bool getCanDelete();
    bool getIsAvailable();
    bool getIsDead();
    vector<Rect> getRects();

    void setCanDelete(bool value);
    void setIsAvailable(bool value);
    void setMatchLabel(int label);
    void setRects(vector<Rect> new_rects);

    void decr();

 private:
    // Count of found faces for incrementing ids
    static int face_id;

    // Timeout in seconds for each face
    int timeout = 60;

    // The distance below which a match is considered 'recognized'
    int distance_threshold = 65;

    int   match_label  = 0;
    bool  is_available = true;
    bool  can_delete   = false;
    int   id           = 0;
    int   timer        = timeout;

    vector<Rect> rects;
};
#endif  // SRC_FACE_H_
