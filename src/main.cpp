#include <iostream>
#include "easylogging++.h"
#include "tracker.h"

INITIALIZE_EASYLOGGINGPP

using namespace std;

int main(int argc, char ** argv){
  FaceTracker tracker;
  tracker.run();
}
