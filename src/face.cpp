#include "face.h"

int Face::face_id = 0;

Face::Face(){
  id = Face::getNextId();
};

int Face::getId(){
  return id;
};

bool Face::getCanDelete(){
  return can_delete;
};

bool Face::getIsAvailable(){
  return is_available;
};

bool Face::getIsDead(){
  return timer < 0;
};

vector<Rect> Face::getRects(){
  return rects;
};

void Face::setCanDelete(bool value){
  can_delete = value;
};

void Face::setIsAvailable(bool value){
  is_available = value;
};

void Face::setMatchLabel(int label){
  match_label = label;
};

void Face::setRects(vector<Rect> new_rects){
  rects = new_rects;
};

void Face::decr(){
  timer--;
};
