#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>
#include <boost/filesystem.hpp>
#include "easylogging++.h"

using namespace std;
namespace fs = boost::filesystem;

namespace environment {

  extern const string app_root;
  const string cascadesDir();
  string getCascadePath(const string cascade_path);

  void logAll();
}

#endif
