#include "utils.h"

using namespace std;

namespace utils {
  vector<string> glob(const string& pattern){
    using namespace std;

    glob_t glob_result;
    vector<string> ret;

    glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);

    for(unsigned int i=0; i < glob_result.gl_pathc; ++i){
      ret.push_back(string(glob_result.gl_pathv[i]));
    }

    globfree(&glob_result);

    return ret;
  }

  void normalizeImage(Mat source, Mat target){
    cvtColor(source, target, CV_BGR2GRAY);
    equalizeHist(target, target);
  }
}
