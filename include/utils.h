#ifndef UTILS_H
#define UTILS_H

#include <glob.h>
#include <vector>
#include <string>

namespace utils {
  std::vector<std::string> glob(const std::string& path);
}

#endif
