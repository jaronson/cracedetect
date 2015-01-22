#include <iostream>

#include "utils.h"
#include "configuration.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

using namespace std;

int main(int argc, char ** argv){
  Configuration config = Configuration("config/racedetect.json");

  return 0;
}
