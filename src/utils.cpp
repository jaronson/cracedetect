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

  vector<string> readFile(const string& path){
    vector<string> dict;
    ifstream input_stream(path);
    string word;

    if(input_stream){
      while(input_stream >> word){
        dict.push_back(word);
      }
    }

    input_stream.close();

    return dict;
  }
}
