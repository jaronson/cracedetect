#include <iostream>
#include "configuration.h"
#include "recognizer.h"

using namespace std;

int main(int argc, char ** argv){
  cout << CONFIG.recognizer_model_path;
  return 0;
}
