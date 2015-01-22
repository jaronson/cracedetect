#include "utils.h"

std::vector<std::string> utils::glob(const std::string& pattern){
  using namespace std;

  glob_t glob_result;
  vector<string> ret;

  glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);

  for(unsigned int i=0; i < glob_result.gl_pathc; ++i){
    ret.push_back(string(glob_result.gl_pathv[i]));
  }

  globfree(&glob_result);

  return ret;
};
