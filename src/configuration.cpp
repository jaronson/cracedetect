#include "configuration.h"
#include "easylogging++.h"

using namespace std;

Configuration::Configuration(const string filepath)
  : filepath(filepath)
{
  this->filepath = filepath;
}

void Configuration::readConfig() {
  ifstream fh;
  fh.open(this->filepath);

  if(fh.is_open()){
  }

  fh.close();
}
