#ifndef SRC_ENVIRONMENT_H_
#define SRC_ENVIRONMENT_H_

#include <boost/filesystem.hpp>
#include <string>
#include "vendor/easylogging++.h"

namespace fs = boost::filesystem;

using std::string;

namespace environment {

  extern const string app_root;
  const string cascadesDir();
  string getCascadePath(const string cascade_path);

  void logAll();
}

#endif  // SRC_ENVIRONMENT_H_
