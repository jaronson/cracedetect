#include "environment.h"

namespace environment {
  // TODO: Move to compile-time constant
  extern const string app_root = "/usr/dev/jaronson/cracedetect";

  string const cascadesDir(){
    fs::path root(app_root);
    fs::path cascades_dir("data/cascades");
    fs::path full_path = root / cascades_dir;

    return full_path.string();
  }

  string getCascadePath(const string cascade_path){
    fs::path root(cascadesDir());
    fs::path casc(cascade_path);
    fs::path full_path = root / casc;

    return full_path.string();
  }

  void logAll(){
    LOG(DEBUG) << "app_root: " << app_root;
    LOG(DEBUG) << "cascadesDir(): " << cascadesDir();
  }
}
